// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1206, BothDistinctCentPrecisionRefusalsAreAtomic) {
    fx::expect_error(compare(LoanInput{1,600,fx::nominal("0")}),ErrorCode::UnsupportedCentPrecision);
    fx::expect_error(compare(LoanInput{1200,600,fx::nominal("100")}),ErrorCode::UnsupportedCentPrecision);
}
