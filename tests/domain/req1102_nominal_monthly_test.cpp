// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1102, ProportionalFractionAndExactOrigin) {
    struct Case { const char* p; const char* monthly; int numerator; int denominator; };
    for (const auto& c:std::array<Case,4>{{{"0","0",1,1},{"4.5","0.00375",803,800},{"12","0.01",101,100},{"100","0.083333333333333333333333333333333333",13,12}}}) {
        SCOPED_TRACE(c.p);
        const auto n=normalize(fx::nominal(c.p)); ASSERT_TRUE(fx::success(n));
        const auto projection=project_rates(fx::value(n)); ASSERT_TRUE(fx::success(projection));
        fx::expect_close(fx::value(projection).effective_monthly_decimal,c.monthly,"1e-12");
        ASSERT_TRUE(std::holds_alternative<RationalGrowth>(fx::value(n).growth));
        EXPECT_TRUE(std::get<RationalGrowth>(fx::value(n).growth).factor==Rational(c.numerator)/c.denominator);
        if (std::string(c.p)=="0") EXPECT_EQ(fx::value(projection).effective_monthly_decimal,Decimal(0));
    }
}
