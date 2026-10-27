// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1203, NormativeSacRemainderAndTieNeighbors) {
    const auto n=normalize(fx::nominal("12")); ASSERT_TRUE(fx::success(n));
    const auto s=calculate_sac(100000,3,fx::value(n)); ASSERT_TRUE(fx::success(s));
    fx::expect_ledger(fx::value(s),fx::sac_nominal_three,false);
    const auto high=normalize(fx::nominal("100")); ASSERT_TRUE(fx::success(high));
    const auto tie=calculate_sac(6,1,fx::value(high)); ASSERT_TRUE(fx::success(tie));
    EXPECT_EQ(fx::value(tie).summary.interest_total,1); EXPECT_EQ(fx::value(tie).summary.payment_total,7);
    const std::array<const char*,3> rates{"5.999999","6","6.000001"};
    for (std::size_t i=0;i<rates.size();++i) {
        const auto r=normalize(fx::nominal(rates[i])); ASSERT_TRUE(fx::success(r));
        const auto result=calculate_sac(100,1,fx::value(r)); ASSERT_TRUE(fx::success(result));
        EXPECT_EQ(fx::value(result).summary.interest_total,i==0 ? 0 : 1);
    }
}
TEST(Req1203, SacGradeHasInitialRemainderAndNonIncreasingPayments) {
    for (const auto c:fx::grade_principals) for (const auto months:fx::grade_terms) {
        if (c<months) continue;
        for (const auto kind:{RateKind::NominalAnnualMonthlyCapitalization,RateKind::EffectiveAnnual}) for (const auto* p:fx::grade_percentages) {
            SCOPED_TRACE(::testing::Message()<<c<<","<<months<<","<<static_cast<int>(kind)<<","<<p);
            const auto n=normalize(AnnualRate{kind,p}); ASSERT_TRUE(fx::success(n));
            const auto result=calculate_sac(c,months,fx::value(n)); ASSERT_TRUE(fx::success(result));
            fx::expect_invariants(fx::value(result),c,months,true);
        }
    }
}
