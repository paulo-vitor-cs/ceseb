// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "gui_tests.hpp"
using namespace ceseb;
using ceseb::ui::MoneyCodec;
void GuiContractTests::req1211_localized_input() {
    for (const auto& text:{QStringLiteral("100.000,00"),QStringLiteral("100000,00"),QStringLiteral(" 100.000,00 ")}) {
        const auto r=MoneyCodec::parse_principal(text);
        QVERIFY(std::holds_alternative<std::int64_t>(r)); QCOMPARE(std::get<std::int64_t>(r),std::int64_t(10000000));
    }
    for (const auto& text:{QStringLiteral("1,000"),QStringLiteral("1,234.56"),QStringLiteral("1e3"),QString{},QStringLiteral("12.34,56"),QStringLiteral("1 000,00")})
        QVERIFY(std::holds_alternative<Error>(MoneyCodec::parse_principal(text)));
    for (const auto kind:{RateKind::NominalAnnualMonthlyCapitalization,RateKind::EffectiveAnnual}) {
        const auto r=MoneyCodec::parse_rate(QStringLiteral("4,5"),kind);
        QVERIFY(std::holds_alternative<AnnualRate>(r));
        QCOMPARE(QString::fromStdString(std::get<AnnualRate>(r).percent),QStringLiteral("4.5"));
        QVERIFY(std::get<AnnualRate>(r).kind.has_value()); QVERIFY(*std::get<AnnualRate>(r).kind==kind);
        QVERIFY(std::holds_alternative<AnnualRate>(MoneyCodec::parse_rate(QStringLiteral("4,123456"),kind)));
        for (const auto& bad:{QStringLiteral("4.5"),QStringLiteral("4,1234567"),QStringLiteral("4e1"),QStringLiteral("+4,5"),QStringLiteral("4 5")})
            QVERIFY(std::holds_alternative<Error>(MoneyCodec::parse_rate(bad,kind)));
    }
    const auto term=MoneyCodec::parse_term(QStringLiteral("360"));
    QVERIFY(std::holds_alternative<int>(term)); QCOMPARE(std::get<int>(term),360);
    for (const auto& bad:{QStringLiteral("0"),QStringLiteral("3,5"),QStringLiteral("+360"),QString{}})
        QVERIFY(std::holds_alternative<Error>(MoneyCodec::parse_term(bad)));
    gui_fixture::MainWindow w; gui_fixture::show(w); gui_fixture::Form f(w); QVERIFY(f.valid());
    QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("12"),false,QStringLiteral("3"))); f.run();
    QCOMPARE(gui_fixture::money_number(gui_fixture::label(w,"priceTotalValue")),QStringLiteral("1.020,07"));
    QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("12"),true,QStringLiteral("3"))); f.run();
    QCOMPARE(gui_fixture::money_number(gui_fixture::label(w,"priceTotalValue")),QStringLiteral("1.019,04"));
}
