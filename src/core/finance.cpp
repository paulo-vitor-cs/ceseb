// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include <ceseb/finance.hpp>
#include "exact_math.hpp"
#include <algorithm>

namespace ceseb {
namespace {
void principal_domain(std::int64_t principal) {
    if (principal<1 || principal>10000000000LL) throw detail::Failure(ErrorCode::PrincipalOutOfRange);
}
void term_domain(int months) {
    if (months<1 || months>600) throw detail::Failure(ErrorCode::TermOutOfRange);
}
void book_domain(std::int64_t principal,int months) {
    principal_domain(principal); term_domain(months);
    if (principal<months) throw detail::Failure(ErrorCode::UnsupportedCentPrecision);
}
Schedule finish(std::vector<ScheduleRow> rows,std::int64_t principal,int months,std::int64_t ordinary) {
    Schedule result{std::move(rows),{}};
    auto& summary=result.summary;
    summary.requested_months=months;
    summary.actual_payments=static_cast<int>(result.rows.size());
    summary.ordinary_payment=ordinary;
    summary.first_payment=result.rows.front().payment;
    summary.last_payment=result.rows.back().payment;
    summary.early_payoff=summary.actual_payments<months;
    for (const auto& row:result.rows) {
        if (row.principal_paid<=0 || row.closing_balance<0 || row.opening_balance-row.closing_balance!=row.principal_paid || detail::add(row.principal_paid,row.interest)!=row.payment)
            throw detail::Failure(ErrorCode::ArithmeticError);
        summary.principal_total=detail::add(summary.principal_total,row.principal_paid);
        summary.interest_total=detail::add(summary.interest_total,row.interest);
        summary.payment_total=detail::add(summary.payment_total,row.payment);
    }
    if (summary.principal_total!=principal || result.rows.back().closing_balance!=0 || summary.payment_total!=detail::add(principal,summary.interest_total))
        throw detail::Failure(ErrorCode::ArithmeticError);
    return result;
}
Schedule price(std::int64_t principal,int months,const NormalizedRate& rate) {
    book_domain(principal,months);
    const auto ordinary=detail::price_payment(principal,months,rate);
    if (ordinary<=detail::rounded_monthly_product(rate,principal))
        throw detail::Failure(ErrorCode::UnsupportedCentPrecision);
    std::vector<ScheduleRow> rows;
    rows.reserve(static_cast<std::size_t>(months));
    auto balance=principal;
    for (int period=1;period<=months && balance>0;++period) {
        const auto interest=detail::rounded_monthly_product(rate,balance);
        const auto settlement=detail::add(balance,interest);
        const auto payment=period==months ? settlement : std::min(ordinary,settlement);
        const auto amortization=payment-interest;
        const auto closing=balance-amortization;
        rows.push_back({period,balance,interest,amortization,payment,closing});
        balance=closing;
    }
    return finish(std::move(rows),principal,months,ordinary);
}
Schedule sac(std::int64_t principal,int months,const NormalizedRate& rate) {
    book_domain(principal,months);
    const auto quotient=principal/months, remainder=principal%months;
    std::vector<ScheduleRow> rows;
    rows.reserve(static_cast<std::size_t>(months));
    auto balance=principal;
    for (int period=1;period<=months;++period) {
        const auto amortization=quotient+(period<=remainder ? 1 : 0);
        const auto interest=detail::rounded_monthly_product(rate,balance);
        const auto payment=detail::add(amortization,interest);
        const auto closing=balance-amortization;
        rows.push_back({period,balance,interest,amortization,payment,closing});
        balance=closing;
    }
    return finish(std::move(rows),principal,months,0);
}
}
Result<NormalizedRate> normalize(const AnnualRate& rate) {
    return detail::guarded<NormalizedRate>([&] {
        if (!rate.kind || (*rate.kind!=RateKind::NominalAnnualMonthlyCapitalization && *rate.kind!=RateKind::EffectiveAnnual))
            throw detail::Failure(ErrorCode::InvalidRateKind);
        const Rational percent=detail::decimal_fraction(rate.percent);
        if (percent<0 || percent>100) throw detail::Failure(ErrorCode::RateOutOfRange);
        if (*rate.kind==RateKind::NominalAnnualMonthlyCapitalization)
            return NormalizedRate{rate,RationalGrowth{1+percent/1200}};
        const Rational annual=1+percent/100;
        const auto n=detail::exact_twelfth_root(numerator(annual));
        if (n) {
            const auto d=detail::exact_twelfth_root(denominator(annual));
            if (d) return NormalizedRate{rate,RationalGrowth{Rational(*n)/(*d)}};
        }
        return NormalizedRate{rate,TwelfthRootGrowth{annual}};
    });
}
Result<RateProjection> project_rates(const NormalizedRate& rate) {
    return detail::guarded<RateProjection>([&] {
        Rational monthly, effective;
        if (const auto* r=std::get_if<RationalGrowth>(&rate.growth)) {
            monthly=r->factor-1;
            effective=100*(detail::power(r->factor,12)-1);
        } else {
            const Rational annual=std::get<TwelfthRootGrowth>(rate.growth).annual_factor;
            const auto bounds=detail::root_bounds(annual);
            monthly=(bounds.first+bounds.second)/2-1;
            effective=100*(annual-1);
        }
        return RateProjection{detail::decimal_projection(monthly),detail::decimal_projection(1200*monthly),detail::decimal_projection(effective)};
    });
}
Result<QuantizedRates> quantize_rates(const NormalizedRate& rate) {
    return detail::guarded<QuantizedRates>([&] {
        Rational effective;
        if (const auto* r=std::get_if<RationalGrowth>(&rate.growth)) effective=100*(detail::power(r->factor,12)-1);
        else effective=100*(std::get<TwelfthRootGrowth>(rate.growth).annual_factor-1);
        return QuantizedRates{detail::rounded_monthly_product(rate,100000000),detail::rounded_monthly_product(rate,1200000000),detail::round_half_up(effective*1000000)};
    });
}
Result<std::int64_t> quantize_percent(const Rational& percent) {
    return detail::guarded<std::int64_t>([&] {
        if (percent<0) throw detail::Failure(ErrorCode::RateOutOfRange);
        return detail::round_half_up(percent*1000000);
    });
}
Result<Schedule> calculate_price(std::int64_t principal,int months,const NormalizedRate& rate) {
    return detail::guarded<Schedule>([&]{return price(principal,months,rate);});
}
Result<Schedule> calculate_sac(std::int64_t principal,int months,const NormalizedRate& rate) {
    return detail::guarded<Schedule>([&]{return sac(principal,months,rate);});
}
Result<Comparison> compare(const LoanInput& input) {
    return detail::guarded<Comparison>([&] {
        principal_domain(input.principal_cents);
        auto normalized=normalize(input.rate);
        if (const auto* error=std::get_if<Error>(&normalized)) throw detail::Failure(error->code);
        term_domain(input.term_months);
        auto rate=std::get<NormalizedRate>(std::move(normalized));
        auto p=price(input.principal_cents,input.term_months,rate);
        auto s=sac(input.principal_cents,input.term_months,rate);
        const auto difference=detail::add(p.summary.interest_total,-s.summary.interest_total);
        return Comparison{std::move(rate),std::move(p),std::move(s),difference};
    });
}
}
