// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1201, InclusivePrincipalAndTermLimits) {
    for (const auto p:{std::int64_t(0),std::int64_t(10000000001LL)})
        fx::expect_error(compare(LoanInput{p,1,fx::nominal("0")}),ErrorCode::PrincipalOutOfRange);
    for (const int n:{0,601}) fx::expect_error(compare(LoanInput{100000,n,fx::nominal("0")}),ErrorCode::TermOutOfRange);
    for (const auto input:{LoanInput{1,1,fx::nominal("0")},LoanInput{10000000000LL,1,fx::nominal("0")},LoanInput{10000000000LL,600,fx::nominal("0")}})
        ASSERT_TRUE(fx::success(compare(input)));
}
TEST(Req1201, PrincipalThenRateThenTermThenCentAdmissibility) {
    fx::expect_error(compare(LoanInput{0,0,fx::nominal("-1")}),ErrorCode::PrincipalOutOfRange);
    fx::expect_error(compare(LoanInput{100000,0,fx::nominal("-1")}),ErrorCode::RateOutOfRange);
    fx::expect_error(compare(LoanInput{100000,0,AnnualRate{std::nullopt,"12"}}),ErrorCode::InvalidRateKind);
    fx::expect_error(compare(LoanInput{100000,0,fx::nominal("12")}),ErrorCode::TermOutOfRange);
    fx::expect_error(compare(LoanInput{1,600,fx::nominal("0")}),ErrorCode::UnsupportedCentPrecision);
}
