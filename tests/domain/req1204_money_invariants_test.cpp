// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "../support/financial_fixtures.hpp"

using namespace ceseb;
namespace fx=ceseb::tests;

TEST(Req1204, NormativeAndBoundaryBooksConserveMoney) {
    std::size_t successful=0,cent_rejections=0;
    for (const auto c:fx::grade_principals) for (const auto months:fx::grade_terms)
        for (const auto kind:{RateKind::NominalAnnualMonthlyCapitalization,RateKind::EffectiveAnnual}) for (const auto* p:fx::grade_percentages) {
            SCOPED_TRACE(::testing::Message()<<c<<","<<months<<","<<static_cast<int>(kind)<<","<<p);
            const auto result=compare(LoanInput{c,months,AnnualRate{kind,p}});
            if (std::holds_alternative<Error>(result)) {
                EXPECT_EQ(std::get<Error>(result).code,ErrorCode::UnsupportedCentPrecision);
                ++cent_rejections;
                continue; // Invariants judge produced valid books; rejection correctness has independent T1201/T1206 fixtures.
            }
            ASSERT_GE(c,months);
            ++successful;
            const auto& comparison=fx::value(result);
            fx::expect_invariants(comparison.price,c,months,false);
            fx::expect_invariants(comparison.sac,c,months,true);
            EXPECT_EQ(comparison.interest_difference,comparison.price.summary.interest_total-comparison.sac.summary.interest_total);
        }
    EXPECT_GT(successful,0U); EXPECT_GT(cent_rejections,0U);
    RecordProperty("successful_grade_inputs",std::to_string(successful));
    RecordProperty("cent_precision_rejections",std::to_string(cent_rejections));
}
