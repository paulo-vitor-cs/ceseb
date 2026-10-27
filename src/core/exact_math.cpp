// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include "exact_math.hpp"
#include <algorithm>
#include <cctype>
#include <limits>

namespace ceseb::detail {
Integer power(Integer base, unsigned exponent) {
    Integer result=1;
    while (exponent) {
        if (exponent&1U) result*=base;
        exponent>>=1U;
        if (exponent) base*=base;
    }
    return result;
}
Rational power(Rational base, unsigned exponent) {
    Rational result=1;
    while (exponent) {
        if (exponent&1U) result*=base;
        exponent>>=1U;
        if (exponent) base*=base;
    }
    return result;
}
Rational decimal_fraction(const std::string& text) {
    std::string lower=text;
    std::transform(lower.begin(),lower.end(),lower.begin(),[](unsigned char c){return static_cast<char>(std::tolower(c));});
    if (lower=="nan" || lower=="inf" || lower=="infinity" || lower=="+inf" || lower=="-inf" || lower=="+infinity" || lower=="-infinity")
        throw Failure(ErrorCode::NonFiniteRate);
    std::size_t i=0;
    bool negative=false;
    if (i<text.size() && (text[i]=='+' || text[i]=='-')) negative=text[i++]=='-';
    Integer value=0;
    unsigned fractional=0;
    bool dot=false, digit=false;
    for (;i<text.size();++i) {
        const char c=text[i];
        if (c=='.' && !dot) { dot=true; continue; }
        if (c<'0' || c>'9') throw Failure(ErrorCode::NonFiniteRate);
        digit=true; value*=10; value+=c-'0';
        if (dot) {
            if (fractional==std::numeric_limits<unsigned>::max()) throw Failure(ErrorCode::ArithmeticError);
            ++fractional;
        }
    }
    if (!digit) throw Failure(ErrorCode::NonFiniteRate);
    Rational result(value);
    result/=power(Integer(10),fractional);
    return negative ? -result : result;
}
std::optional<Integer> exact_twelfth_root(const Integer& value) {
    if (value<0) return std::nullopt;
    if (value<=1) return value;
    // Bit-length gives a compact certified upper bound; no floating estimate is trusted.
    const unsigned bits=boost::multiprecision::msb(value)+1;
    Integer low=0, high=Integer(1)<<((bits+11)/12);
    ++high;
    while (high-low>1) {
        const Integer mid=(low+high)/2;
        const Integer p=power(mid,12);
        if (p==value) return mid;
        if (p<value) low=mid; else high=mid;
    }
    if (power(low,12)==value) return low;
    return std::nullopt;
}
std::int64_t checked_integer(const Integer& value) {
    if (value<std::numeric_limits<std::int64_t>::min() || value>std::numeric_limits<std::int64_t>::max())
        throw Failure(ErrorCode::ArithmeticError);
    return value.convert_to<std::int64_t>();
}
std::int64_t round_half_up(const Rational& value) {
    if (value<0) throw Failure(ErrorCode::ArithmeticError);
    const Integer n=numerator(value), d=denominator(value);
    return checked_integer((2*n+d)/(2*d));
}
std::int64_t add(std::int64_t a, std::int64_t b) {
    return checked_integer(Integer(a)+b);
}
Decimal decimal_projection(const Rational& value) {
    const Decimal n(numerator(value).convert_to<std::string>());
    const Decimal d(denominator(value).convert_to<std::string>());
    const Decimal result=n/d;
    if (!boost::multiprecision::isfinite(result) || (value!=0 && result==0))
        throw Failure(ErrorCode::ArithmeticError);
    return result;
}
std::pair<Rational,Rational> root_bounds(const Rational& annual) {
    if (annual<1 || annual>2) throw Failure(ErrorCode::ArithmeticError);
    if (annual==1) return {Rational(1),Rational(1)};
    Rational low=1, high=2;
    const Rational relative=Rational(1)/power(Integer(10),45);
    // These bounds serve projections only. No monetary decision uses the midpoint.
    while (low==1 || high-low>(low-1)*relative) {
        const Rational mid=(low+high)/2;
        if (power(mid,12)<annual) low=mid; else high=mid;
    }
    return {low,high};
}
std::int64_t rounded_monthly_product(const NormalizedRate& rate, std::int64_t scale) {
    if (scale<0) throw Failure(ErrorCode::ArithmeticError);
    if (!scale) return 0;
    if (const auto* rational=std::get_if<RationalGrowth>(&rate.growth)) {
        if (rational->factor<1 || rational->factor>=2) throw Failure(ErrorCode::ArithmeticError);
        return round_half_up((rational->factor-1)*scale);
    }
    const auto& annual=std::get<TwelfthRootGrowth>(rate.growth).annual_factor;
    if (annual<1 || annual>2) throw Failure(ErrorCode::ArithmeticError);
    const Integer denominator_value=Integer(2)*scale;
    const Integer left=numerator(annual)*power(denominator_value,12);
    const Integer annual_denominator=denominator(annual);
    std::uint64_t low=0, high=static_cast<std::uint64_t>(scale)+1;
    while (high-low>1) {
        const auto mid=low+(high-low)/2;
        const Integer threshold=denominator_value+Integer(2)*mid-1;
        if (left>=annual_denominator*power(threshold,12)) low=mid; else high=mid;
    }
    return checked_integer(Integer(low));
}
static Rational annuity(std::int64_t principal, int months, const Rational& growth) {
    if (growth==1) return Rational(principal)/months;
    const Rational powered=power(growth,static_cast<unsigned>(months));
    // The geometric-sum identity is evaluated exactly as a rational, with no cancellation error.
    const Rational sum=(powered-1)/(growth-1);
    return Rational(principal)*powered/sum;
}
std::int64_t price_payment(std::int64_t principal, int months, const NormalizedRate& rate) {
    if (const auto* rational=std::get_if<RationalGrowth>(&rate.growth)) {
        if (rational->factor<1 || rational->factor>=2) throw Failure(ErrorCode::ArithmeticError);
        return round_half_up(annuity(principal,months,rational->factor));
    }
    const Rational annual=std::get<TwelfthRootGrowth>(rate.growth).annual_factor;
    if (annual<=1 || annual>2) throw Failure(ErrorCode::ArithmeticError);
    Rational low=1, high=2;
    for (;;) {
        const auto lo=round_half_up(annuity(principal,months,low));
        const auto hi=round_half_up(annuity(principal,months,high));
        if (lo==hi) return lo;
        const Rational mid=(low+high)/2;
        if (power(mid,12)<annual) low=mid; else high=mid;
    }
}
}
