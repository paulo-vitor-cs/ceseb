// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1101, ExplicitKindsHaveDifferentMonthlyMeaning) {
    const auto n=normalize(fx::nominal("12")), e=normalize(fx::effective("12"));
    ASSERT_TRUE(fx::success(n)); ASSERT_TRUE(fx::success(e));
    const auto np=project_rates(fx::value(n)), ep=project_rates(fx::value(e));
    ASSERT_TRUE(fx::success(np)); ASSERT_TRUE(fx::success(ep));
    fx::expect_close(fx::value(np).effective_monthly_decimal,"0.01","1e-12");
    fx::expect_close(fx::value(ep).effective_monthly_decimal,"0.009488792934582974126355069193493956","1e-12");
}
TEST(Req1101, MissingAndUnknownKindsAreRejected) {
    fx::expect_error(normalize(AnnualRate{std::nullopt,"12"}),ErrorCode::InvalidRateKind);
    fx::expect_error(normalize(AnnualRate{static_cast<RateKind>(-1),"12"}),ErrorCode::InvalidRateKind);
}
