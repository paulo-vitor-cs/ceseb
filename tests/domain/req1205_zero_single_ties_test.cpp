// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1205, ZeroAndOnePeriodExactHalfUp) {
    const auto zero=compare(LoanInput{120000,12,fx::nominal("0")}); ASSERT_TRUE(fx::success(zero));
    for (const auto* schedule:{&fx::value(zero).price,&fx::value(zero).sac}) {
        ASSERT_EQ(schedule->rows.size(),12U);
        for (const auto& row:schedule->rows) { EXPECT_EQ(row.payment,10000); EXPECT_EQ(row.interest,0); }
        EXPECT_EQ(schedule->summary.payment_total,120000); EXPECT_EQ(schedule->summary.interest_total,0);
    }
    for (const auto input:{LoanInput{100,1,fx::nominal("6")},LoanInput{6,1,fx::nominal("100")}}) {
        const auto r=compare(input); ASSERT_TRUE(fx::success(r));
        for (const auto* schedule:{&fx::value(r).price,&fx::value(r).sac}) {
            ASSERT_EQ(schedule->rows.size(),1U);
            EXPECT_EQ(schedule->rows[0].interest,1); EXPECT_EQ(schedule->rows[0].payment,input.principal_cents+1);
            EXPECT_EQ(schedule->rows[0].closing_balance,0);
        }
    }
}
TEST(Req1205, JustBelowAtAndAboveHalfCentAndRationalEffectiveRoot) {
    for (const auto* p:{"5.999999","6","6.000001"}) {
        const auto r=compare(LoanInput{100,1,fx::nominal(p)}); ASSERT_TRUE(fx::success(r));
        const int interest=std::string(p)=="5.999999" ? 0 : 1;
        for (const auto* schedule:{&fx::value(r).price,&fx::value(r).sac}) {
            ASSERT_EQ(schedule->rows.size(),1U); EXPECT_EQ(schedule->summary.interest_total,interest);
            EXPECT_EQ(schedule->summary.payment_total,100+interest);
        }
    }
    const auto rate=fx::effective(fx::rational_effective_half_cent_percent());
    const auto n=normalize(rate); ASSERT_TRUE(fx::success(n));
    ASSERT_TRUE(std::holds_alternative<RationalGrowth>(fx::value(n).growth));
    EXPECT_TRUE(std::get<RationalGrowth>(fx::value(n).growth).factor==Rational(201)/200);
    const auto r=compare(LoanInput{100,1,rate}); ASSERT_TRUE(fx::success(r));
    for (const auto* schedule:{&fx::value(r).price,&fx::value(r).sac}) {
        ASSERT_EQ(schedule->rows.size(),1U); EXPECT_EQ(schedule->summary.interest_total,1);
        EXPECT_EQ(schedule->summary.payment_total,101);
    }
}
