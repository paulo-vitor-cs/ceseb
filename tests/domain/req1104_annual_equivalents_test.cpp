// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1104, AnnualPercentagePointsAndDerivedCeiling) {
    const auto nominal=normalize(fx::nominal("12")), effective=normalize(fx::effective("12"));
    ASSERT_TRUE(fx::success(nominal)); ASSERT_TRUE(fx::success(effective));
    const auto np=project_rates(fx::value(nominal)), ep=project_rates(fx::value(effective));
    ASSERT_TRUE(fx::success(np)); ASSERT_TRUE(fx::success(ep));
    fx::expect_close(fx::value(np).nominal_annual_percent,"12","1e-9");
    fx::expect_close(fx::value(np).effective_annual_percent,"12.682503013196972066120100","1e-9");
    fx::expect_close(fx::value(ep).nominal_annual_percent,"11.386551521499568951626083032192747","1e-9");
    fx::expect_close(fx::value(ep).effective_annual_percent,"12","1e-9");
    for (const auto& rate:{fx::nominal("0"),fx::effective("0")}) {
        const auto z=normalize(rate); ASSERT_TRUE(fx::success(z));
        const auto p=project_rates(fx::value(z)); ASSERT_TRUE(fx::success(p));
        EXPECT_EQ(fx::value(p).nominal_annual_percent,Decimal(0));
        EXPECT_EQ(fx::value(p).effective_annual_percent,Decimal(0));
    }
    const auto high=normalize(fx::nominal("100")); ASSERT_TRUE(fx::success(high));
    const auto hp=project_rates(fx::value(high)); ASSERT_TRUE(fx::success(hp));
    Decimal growth=Decimal(13)/12, factor=1;
    for (int i=0;i<12;++i) factor*=growth;
    const Decimal expected=100*(factor-1);
    EXPECT_GT(fx::value(hp).effective_annual_percent,Decimal(100));
    const Decimal delta=boost::multiprecision::abs(fx::value(hp).effective_annual_percent-expected);
    EXPECT_LE(delta,Decimal("1e-9"));
}
