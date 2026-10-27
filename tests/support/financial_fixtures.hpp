// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#pragma once
#include <ceseb/finance.hpp>
#include <gtest/gtest.h>
#include <array>
#include <chrono>
#include <cstdint>
#include <iomanip>
#include <limits>
#include <locale>
#include <optional>
#include <sstream>
#include <string>
#include <variant>
#include <utility>
#include <vector>

namespace ceseb::tests {
inline AnnualRate nominal(std::string p) { return {RateKind::NominalAnnualMonthlyCapitalization, std::move(p)}; }
inline AnnualRate effective(std::string p) { return {RateKind::EffectiveAnnual, std::move(p)}; }
template<class T> ::testing::AssertionResult success(const Result<T>& result) {
    if (std::holds_alternative<T>(result)) return ::testing::AssertionSuccess();
    return ::testing::AssertionFailure() << "ErrorCode=" << static_cast<int>(std::get<Error>(result).code);
}
template<class T> const T& value(const Result<T>& result) { return std::get<T>(result); }
template<class T> void expect_error(const Result<T>& result, ErrorCode code) {
    ASSERT_TRUE(std::holds_alternative<Error>(result)) << "Unexpected success";
    EXPECT_EQ(std::get<Error>(result).code, code);
}
inline void expect_close(const Decimal& actual, const char* expected, const char* tolerance) {
    const Decimal reference(expected), limit(tolerance);
    const Decimal delta = boost::multiprecision::abs(actual-reference);
    EXPECT_TRUE(delta <= limit) << "actual=" << actual << ", expected=" << reference << ", error=" << delta;
}
struct LedgerFixture {
    std::int64_t principal;
    int months;
    std::vector<std::int64_t> payments, interests, balances;
    std::int64_t ordinary, total, interest_total;
};
inline const LedgerFixture price_nominal_three{100000,3,{34002,34002,34003},{1000,670,337},{66998,33666,0},34002,102007,2007};
inline const LedgerFixture sac_nominal_three{100000,3,{34334,34000,33666},{1000,667,333},{66666,33333,0},0,102000,2000};
inline void expect_ledger(const Schedule& schedule, const LedgerFixture& f, bool price) {
    ASSERT_EQ(schedule.rows.size(), f.payments.size());
    std::int64_t opening=f.principal;
    for (std::size_t i=0;i<f.payments.size();++i) {
        SCOPED_TRACE(i);
        const auto& row=schedule.rows[i];
        EXPECT_EQ(row.period, static_cast<int>(i+1));
        EXPECT_EQ(row.opening_balance, opening);
        EXPECT_EQ(row.payment,f.payments[i]);
        EXPECT_EQ(row.interest,f.interests[i]);
        EXPECT_EQ(row.principal_paid,f.payments[i]-f.interests[i]);
        EXPECT_EQ(row.closing_balance,f.balances[i]);
        opening=f.balances[i];
    }
    const auto& sum=schedule.summary;
    EXPECT_EQ(sum.requested_months,f.months);
    EXPECT_EQ(sum.actual_payments,static_cast<int>(f.payments.size()));
    EXPECT_EQ(sum.first_payment,f.payments.front());
    EXPECT_EQ(sum.last_payment,f.payments.back());
    EXPECT_EQ(sum.principal_total,f.principal);
    EXPECT_EQ(sum.payment_total,f.total);
    EXPECT_EQ(sum.interest_total,f.interest_total);
    if (price) EXPECT_EQ(sum.ordinary_payment,f.ordinary);
}
inline void expect_invariants(const Schedule& schedule, std::int64_t principal, int months, bool sac) {
    using boost::multiprecision::cpp_int;
    ASSERT_FALSE(schedule.rows.empty());
    EXPECT_LE(schedule.rows.size(),static_cast<std::size_t>(months));
    if (sac) EXPECT_EQ(schedule.rows.size(),static_cast<std::size_t>(months));
    cpp_int amortized=0, paid=0, interest=0;
    std::int64_t opening=principal;
    for (std::size_t i=0;i<schedule.rows.size();++i) {
        SCOPED_TRACE(i);
        const auto& r=schedule.rows[i];
        EXPECT_EQ(r.period,static_cast<int>(i+1));
        EXPECT_EQ(r.opening_balance,opening);
        EXPECT_EQ(cpp_int(r.opening_balance)-r.closing_balance,cpp_int(r.principal_paid));
        EXPECT_EQ(cpp_int(r.payment),cpp_int(r.principal_paid)+r.interest);
        EXPECT_GT(r.principal_paid,0);
        EXPECT_GE(r.closing_balance,0);
        EXPECT_GE(r.interest,0);
        if (i+1<schedule.rows.size()) EXPECT_GT(r.closing_balance,0);
        if (sac) {
            const auto q=principal/months, remainder=principal%months;
            EXPECT_EQ(r.principal_paid,q+(static_cast<std::int64_t>(i)<remainder ? 1 : 0));
            if (i>0) EXPECT_LE(r.payment,schedule.rows[i-1].payment);
        }
        amortized+=r.principal_paid; paid+=r.payment; interest+=r.interest;
        opening=r.closing_balance;
    }
    EXPECT_EQ(opening,0);
    EXPECT_EQ(amortized,cpp_int(principal));
    EXPECT_EQ(paid,cpp_int(principal)+interest);
    EXPECT_EQ(paid,cpp_int(schedule.summary.payment_total));
    EXPECT_EQ(interest,cpp_int(schedule.summary.interest_total));
    EXPECT_EQ(amortized,cpp_int(schedule.summary.principal_total));
    EXPECT_EQ(schedule.summary.actual_payments,static_cast<int>(schedule.rows.size()));
    EXPECT_LE(paid,cpp_int(std::numeric_limits<std::int64_t>::max()));
}
inline std::string rational_effective_half_cent_percent() {
    // Independent exact fixture: 100*((201/200)^12-1). Denominator has only factors 2 and 5.
    using boost::multiprecision::cpp_int;
    cpp_int numerator=1,denominator=1;
    for (int i=0;i<12;++i) { numerator*=201; denominator*=200; }
    numerator=(numerator-denominator)*100;
    const cpp_int integral=numerator/denominator;
    cpp_int remainder=numerator%denominator;
    std::string decimal=integral.convert_to<std::string>();
    if (remainder==0) return decimal;
    decimal+='.';
    while (remainder!=0) {
        remainder*=10;
        const cpp_int digit_value=remainder/denominator;
        const unsigned digit=digit_value.convert_to<unsigned>();
        decimal.push_back(static_cast<char>('0'+digit));
        remainder%=denominator;
    }
    return decimal;
}
inline constexpr std::array<std::int64_t,8> grade_principals{1,3,6,100,1200,100000,10000000,10000000000LL};
inline constexpr std::array<int,6> grade_terms{1,2,3,12,360,600};
inline constexpr std::array<const char*,5> grade_percentages{"0","0.000001","4.5","12","100"};
}
