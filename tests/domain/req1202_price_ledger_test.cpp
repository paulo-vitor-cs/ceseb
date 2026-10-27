// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1202, NormativePriceRowsAndEarlyPayoff) {
    const auto normalized=normalize(fx::nominal("12")); ASSERT_TRUE(fx::success(normalized));
    const auto actual=calculate_price(100000,3,fx::value(normalized)); ASSERT_TRUE(fx::success(actual));
    fx::expect_ledger(fx::value(actual),fx::price_nominal_three,true);
    const auto zero=normalize(fx::nominal("0")); ASSERT_TRUE(fx::success(zero));
    const auto early=calculate_price(100000,600,fx::value(zero)); ASSERT_TRUE(fx::success(early));
    const auto& s=fx::value(early);
    ASSERT_EQ(s.rows.size(),599U); EXPECT_EQ(s.summary.ordinary_payment,167);
    EXPECT_EQ(s.summary.last_payment,134); EXPECT_EQ(s.summary.payment_total,100000);
    EXPECT_TRUE(s.summary.early_payoff);
    for (std::size_t i=0;i+1<s.rows.size();++i) EXPECT_EQ(s.rows[i].payment,167);
    fx::expect_invariants(s,100000,600,false);
    const auto small=calculate_price(3,2,fx::value(zero)); ASSERT_TRUE(fx::success(small));
    fx::expect_ledger(fx::value(small),fx::LedgerFixture{3,2,{2,1},{0,0},{1,0},2,3,0},true);
}
TEST(Req1202, EffectiveIrrationalPriceAndRecordedDuration) {
    const auto normalized=normalize(fx::effective("12")); ASSERT_TRUE(fx::success(normalized));
    const auto start=std::chrono::steady_clock::now();
    const auto actual=calculate_price(100000,3,fx::value(normalized)); ASSERT_TRUE(fx::success(actual));
    fx::expect_ledger(fx::value(actual),fx::LedgerFixture{100000,3,{33968,33968,33968},{949,636,319},{66981,33649,0},33968,101904,1904},true);
    const auto long_case=calculate_price(10000000000LL,600,fx::value(normalized)); ASSERT_TRUE(fx::success(long_case));
    fx::expect_invariants(fx::value(long_case),10000000000LL,600,false);
    const auto elapsed=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-start).count();
    RecordProperty("effective_price_cases_microseconds",std::to_string(elapsed));
}
TEST(Req1202, NormativeTwelvePeriodPrice) {
    const auto n=normalize(fx::nominal("12")); ASSERT_TRUE(fx::success(n));
    const auto s=calculate_price(10000000,12,fx::value(n)); ASSERT_TRUE(fx::success(s));
    EXPECT_EQ(fx::value(s).summary.ordinary_payment,888488);
    EXPECT_EQ(fx::value(s).summary.last_payment,888485);
    EXPECT_EQ(fx::value(s).summary.payment_total,10661853);
    EXPECT_EQ(fx::value(s).summary.interest_total,661853);
}
