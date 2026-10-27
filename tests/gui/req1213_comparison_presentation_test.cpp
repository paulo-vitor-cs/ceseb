// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "gui_tests.hpp"
void GuiContractTests::req1213_comparison_presentation() {
    gui_fixture::MainWindow w; gui_fixture::show(w); gui_fixture::Form f(w); QVERIFY(f.valid());
    QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("12"),false,QStringLiteral("3"))); f.run();
    struct Field { const char* name; const char* expected; };
    for (const auto& x:std::array<Field,9>{{{"priceOrdinaryValue","340,02"},{"priceLastValue","340,03"},{"priceTotalValue","1.020,07"},{"priceInterestValue","20,07"},{"sacFirstValue","343,34"},{"sacLastValue","336,66"},{"sacTotalValue","1.020,00"},{"sacInterestValue","20,00"},{"interestDifferenceValue","0,07"}}})
        QCOMPARE(gui_fixture::money_number(gui_fixture::label(w,x.name)),QString::fromLatin1(x.expected));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"pricePaymentsValue"),3));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"sacPaymentsValue"),3));
    QVERIFY(!gui_fixture::label(w,"priceAdjustmentNotice").isEmpty());
    QVERIFY(f.fill(QStringLiteral("1.000,00"),QStringLiteral("0"),false,QStringLiteral("600"))); f.run();
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"requestedTermValue"),600));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"pricePaymentsValue"),599));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"sacPaymentsValue"),600));
    QCOMPARE(gui_fixture::money_number(gui_fixture::label(w,"priceLastValue")),QStringLiteral("1,34"));
    QCOMPARE(gui_fixture::money_number(gui_fixture::label(w,"sacLastValue")),QStringLiteral("1,66"));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"priceAdjustmentNotice"),599));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"priceAdjustmentNotice"),600));
    QVERIFY(f.fill(QStringLiteral("1,00"),QStringLiteral("6"),false,QStringLiteral("1"))); f.run();
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"pricePaymentsValue"),1));
    QVERIFY(gui_fixture::contains_integer(gui_fixture::label(w,"sacPaymentsValue"),1));
    const auto notice=gui_fixture::label(w,"priceAdjustmentNotice");
    QVERIFY(notice.contains(QString::fromUtf8("única"),Qt::CaseInsensitive) || notice.contains(QStringLiteral("somente"),Qt::CaseInsensitive));
}
