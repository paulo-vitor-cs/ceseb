// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#pragma once

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <cstdint>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace ceseb {
using Rational = boost::multiprecision::cpp_rational;
using Decimal = boost::multiprecision::cpp_dec_float_50;
enum class RateKind { NominalAnnualMonthlyCapitalization, EffectiveAnnual };
enum class ErrorCode {
    InvalidRateKind, RateOutOfRange, NonFiniteRate, PrincipalOutOfRange,
    TermOutOfRange, UnsupportedCentPrecision, ArithmeticError
};
struct Error { ErrorCode code; };
template<class T> using Result = std::variant<T, Error>;
struct AnnualRate { std::optional<RateKind> kind; std::string percent; };
struct RationalGrowth { Rational factor; };
struct TwelfthRootGrowth { Rational annual_factor; };
struct NormalizedRate {
    AnnualRate original;
    std::variant<RationalGrowth, TwelfthRootGrowth> growth;
};
struct RateProjection {
    Decimal effective_monthly_decimal, nominal_annual_percent, effective_annual_percent;
};
struct QuantizedRates {
    std::int64_t monthly_percent_millionths, nominal_annual_percent_millionths,
                 effective_annual_percent_millionths;
};
struct LoanInput { std::int64_t principal_cents; int term_months; AnnualRate rate; };
struct ScheduleRow {
    int period;
    std::int64_t opening_balance, interest, principal_paid, payment, closing_balance;
};
struct ScheduleSummary {
    int requested_months{}, actual_payments{};
    std::int64_t first_payment{}, last_payment{}, ordinary_payment{}, principal_total{},
                 interest_total{}, payment_total{};
    bool early_payoff{};
};
struct Schedule { std::vector<ScheduleRow> rows; ScheduleSummary summary; };
struct Comparison {
    NormalizedRate rate;
    Schedule price, sac;
    std::int64_t interest_difference;
};

Result<NormalizedRate> normalize(const AnnualRate&);
Result<RateProjection> project_rates(const NormalizedRate&);
Result<QuantizedRates> quantize_rates(const NormalizedRate&);
Result<std::int64_t> quantize_percent(const Rational&);
Result<Schedule> calculate_price(std::int64_t, int, const NormalizedRate&);
Result<Schedule> calculate_sac(std::int64_t, int, const NormalizedRate&);
Result<Comparison> compare(const LoanInput&);
}
