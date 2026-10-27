// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1105, NonFiniteOutOfRangeAndInclusiveBoundaries) {
    for (const auto kind:{RateKind::NominalAnnualMonthlyCapitalization,RateKind::EffectiveAnnual}) {
        for (const auto* p:{"NaN","Infinity","-Infinity"}) {
            SCOPED_TRACE(p); fx::expect_error(normalize(AnnualRate{kind,p}),ErrorCode::NonFiniteRate);
        }
        for (const auto* p:{"-0.01","100.01"}) {
            SCOPED_TRACE(p); fx::expect_error(normalize(AnnualRate{kind,p}),ErrorCode::RateOutOfRange);
        }
        for (const auto* p:{"0","100"}) {
            SCOPED_TRACE(p);
            const auto n=normalize(AnnualRate{kind,p}); ASSERT_TRUE(fx::success(n));
            const auto projection=project_rates(fx::value(n)); ASSERT_TRUE(fx::success(projection));
            const auto& values=fx::value(projection);
            EXPECT_TRUE(values.effective_monthly_decimal>=0 && values.effective_monthly_decimal<=Decimal("1000000"));
            EXPECT_TRUE(values.nominal_annual_percent>=0 && values.nominal_annual_percent<=Decimal("1000000"));
            EXPECT_TRUE(values.effective_annual_percent>=0 && values.effective_annual_percent<=Decimal("1000000"));
        }
    }
}
