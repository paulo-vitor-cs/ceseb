// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "gui_tests.hpp"
using namespace ceseb;
void GuiContractTests::req1212_rate_presentation() {
    gui_fixture::MainWindow w; QVERIFY2(gui_fixture::show(w),"Precondition: the window manager must activate the test window before focus assertions."); gui_fixture::Form f(w); QVERIFY(f.valid());
    struct Case { bool effective; const char* monthly; const char* nominal; const char* annual; };
    for (const auto& c:std::array<Case,2>{{{false,"1,000000","12,000000","12,682503"},{true,"0,948879","11,386552","12,000000"}}}) {
        QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("12"),c.effective,QStringLiteral("3"))); f.run();
        QCOMPARE(gui_fixture::percentage_number(gui_fixture::label(w,"monthlyRateValue")),QString::fromLatin1(c.monthly));
        QCOMPARE(gui_fixture::percentage_number(gui_fixture::label(w,"nominalAnnualRateValue")),QString::fromLatin1(c.nominal));
        QCOMPARE(gui_fixture::percentage_number(gui_fixture::label(w,"effectiveAnnualRateValue")),QString::fromLatin1(c.annual));
        const auto normalized=normalize(AnnualRate{c.effective?RateKind::EffectiveAnnual:RateKind::NominalAnnualMonthlyCapitalization,"12"});
        QVERIFY(std::holds_alternative<NormalizedRate>(normalized));
        const auto q=quantize_rates(std::get<NormalizedRate>(normalized)); QVERIFY(std::holds_alternative<QuantizedRates>(q));
        QCOMPARE(std::get<QuantizedRates>(q).monthly_percent_millionths,std::int64_t(c.effective?948879:1000000));
    }
    QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("100"),false,QStringLiteral("3"))); f.run();
    const auto annual=gui_fixture::percentage_number(gui_fixture::label(w,"effectiveAnnualRateValue"));
    QVERIFY(!annual.isEmpty()); QVERIFY(annual.startsWith(QStringLiteral("161,")));
    struct Tie { const char* input; const char* expected; };
    for (const auto& c:std::array<Tie,3>{{{"0,000005","0,000000"},{"0,000006","0,000001"},{"0,000007","0,000001"}}}) {
        QVERIFY(f.fill(QStringLiteral("1.000,00"),QString::fromLatin1(c.input),false,QStringLiteral("3"))); f.run();
        QCOMPARE(gui_fixture::percentage_number(gui_fixture::label(w,"monthlyRateValue")),QString::fromLatin1(c.expected));
    }
    const auto exact=quantize_percent(Rational(1)/2000000); // 0.0000005 percentage point, not a monthly fraction.
    QVERIFY(std::holds_alternative<std::int64_t>(exact)); QCOMPARE(std::get<std::int64_t>(exact),std::int64_t(1));
    QCOMPARE(gui_fixture::percentage_number(ceseb::ui::MoneyCodec::format_percent(std::get<std::int64_t>(exact))),QStringLiteral("0,000001"));
    QString labels;
    for (const auto* label:w.findChildren<QLabel*>()) labels+=label->text()+QLatin1Char(' ');
    QVERIFY(labels.contains(QStringLiteral("mensal"),Qt::CaseInsensitive));
    QVERIFY(labels.contains(QStringLiteral("anual"),Qt::CaseInsensitive));
    QVERIFY(labels.contains(QStringLiteral("nominal"),Qt::CaseInsensitive));
    QVERIFY(labels.contains(QString::fromUtf8("efetiva"),Qt::CaseInsensitive));
    QVERIFY(labels.contains(QLatin1Char('%')));
}
