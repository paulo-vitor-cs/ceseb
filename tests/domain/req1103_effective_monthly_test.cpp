// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1103, CompoundRootMatchesIndependentConstants) {
    struct Case { const char* p; const char* m; };
    for (const auto& c:std::array<Case,3>{{{"0","0"},{"4.5","0.003674809400436766676274626791736065"},{"12","0.009488792934582974126355069193493956"}}}) {
        SCOPED_TRACE(c.p);
        const auto n=normalize(fx::effective(c.p)); ASSERT_TRUE(fx::success(n));
        const auto projection=project_rates(fx::value(n)); ASSERT_TRUE(fx::success(projection));
        fx::expect_close(fx::value(projection).effective_monthly_decimal,c.m,"1e-12");
        if (std::string(c.p)=="0") EXPECT_EQ(fx::value(projection).effective_monthly_decimal,Decimal(0));
    }
}
TEST(Req1103, SmallTypedInputPreservesPositiveExactOrigin) {
    const std::string p="0.000000000000000000000001";
    const auto n=normalize(fx::effective(p)); ASSERT_TRUE(fx::success(n));
    EXPECT_EQ(fx::value(n).original.percent,p);
    ASSERT_TRUE(std::holds_alternative<TwelfthRootGrowth>(fx::value(n).growth));
    EXPECT_GT(std::get<TwelfthRootGrowth>(fx::value(n).growth).annual_factor,Rational(1));
    const auto projection=project_rates(fx::value(n)); ASSERT_TRUE(fx::success(projection));
    EXPECT_GT(fx::value(projection).effective_monthly_decimal,Decimal(0));
}
