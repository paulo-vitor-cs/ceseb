// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1106, PresentationDoesNotReplaceExactDescriptor) {
    const auto normalized=normalize(fx::effective("12")); ASSERT_TRUE(fx::success(normalized));
    const auto n=fx::value(normalized);
    ASSERT_TRUE(n.original.kind.has_value()); EXPECT_EQ(*n.original.kind,RateKind::EffectiveAnnual);
    EXPECT_EQ(n.original.percent,"12");
    ASSERT_TRUE(std::holds_alternative<TwelfthRootGrowth>(n.growth));
    EXPECT_TRUE(std::get<TwelfthRootGrowth>(n.growth).annual_factor==Rational(28)/25);
    const auto before=calculate_price(100000,3,n); ASSERT_TRUE(fx::success(before));
    const auto projection=project_rates(n); ASSERT_TRUE(fx::success(projection));
    fx::expect_close(fx::value(projection).effective_monthly_decimal,"0.009488792934582974126355069193493956","1e-12");
    for (const int precision:{4,6}) {
        std::ostringstream text; text.imbue(std::locale::classic());
        text<<std::fixed<<std::setprecision(precision)<<fx::value(projection).effective_monthly_decimal*100;
        EXPECT_EQ(text.str(),precision==4 ? "0.9489" : "0.948879");
        const auto quantized=quantize_rates(n); ASSERT_TRUE(fx::success(quantized));
        const auto after=calculate_price(100000,3,n); ASSERT_TRUE(fx::success(after));
        EXPECT_EQ(fx::value(after).summary.payment_total,fx::value(before).summary.payment_total);
        EXPECT_EQ(fx::value(after).summary.payment_total,101904);
        EXPECT_TRUE(std::get<TwelfthRootGrowth>(n.growth).annual_factor==Rational(28)/25);
    }
    const auto recurring=normalize(fx::nominal("100")); ASSERT_TRUE(fx::success(recurring));
    const auto labels=quantize_rates(fx::value(recurring)); ASSERT_TRUE(fx::success(labels));
    ASSERT_TRUE(std::holds_alternative<RationalGrowth>(fx::value(recurring).growth));
    EXPECT_TRUE(std::get<RationalGrowth>(fx::value(recurring).growth).factor==Rational(13)/12);
    const auto price=calculate_price(6,1,fx::value(recurring)), sac=calculate_sac(6,1,fx::value(recurring));
    ASSERT_TRUE(fx::success(price)); ASSERT_TRUE(fx::success(sac));
    EXPECT_EQ(fx::value(price).summary.interest_total,1); EXPECT_EQ(fx::value(sac).summary.interest_total,1);
}
