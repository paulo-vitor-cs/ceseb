// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1207, SameOriginEquivalentRatesAndSignedDifference) {
    const auto nominal=compare(LoanInput{100000,3,fx::nominal("12")}); ASSERT_TRUE(fx::success(nominal));
    const auto equivalent=compare(LoanInput{100000,3,fx::effective("12.682503013196972066120100")}); ASSERT_TRUE(fx::success(equivalent));
    for (const auto* c:{&fx::value(nominal),&fx::value(equivalent)}) {
        EXPECT_EQ(c->price.summary.interest_total,2007); EXPECT_EQ(c->sac.summary.interest_total,2000);
        EXPECT_EQ(c->interest_difference,7);
        fx::expect_ledger(c->price,fx::price_nominal_three,true); fx::expect_ledger(c->sac,fx::sac_nominal_three,false);
        const auto labels=quantize_rates(c->rate); ASSERT_TRUE(fx::success(labels));
    }
    const auto distinct=compare(LoanInput{100000,3,fx::effective("12")}); ASSERT_TRUE(fx::success(distinct));
    EXPECT_EQ(fx::value(distinct).price.summary.interest_total,1904);
    EXPECT_EQ(fx::value(distinct).sac.summary.interest_total,1898);
    EXPECT_EQ(fx::value(distinct).interest_difference,6);
    ASSERT_TRUE(fx::value(nominal).rate.original.kind.has_value());
    EXPECT_EQ(*fx::value(nominal).rate.original.kind,RateKind::NominalAnnualMonthlyCapitalization);
}
