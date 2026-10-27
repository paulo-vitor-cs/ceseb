// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#include "gui_tests.hpp"
#include <functional>
using namespace ceseb;
void GuiContractTests::req1214_state_recovery() {
    gui_fixture::MainWindow w; QVERIFY2(gui_fixture::show(w),"Precondition: the window manager must activate the test window before focus assertions."); gui_fixture::Form f(w); QVERIFY(f.valid());
    const auto valid=[&]() { return f.fill(QStringLiteral("1.000,00"),QStringLiteral("12"),false,QStringLiteral("3")); };
    const std::array<std::function<void()>,4> edits{{[&]{f.principal->setText(QStringLiteral("1001,00"));},[&]{f.rate->setText(QStringLiteral("11"));},[&]{f.term->setText(QStringLiteral("4"));},[&]{f.kind->setCurrentIndex(1);}}};
    for (const auto& edit:edits) {
        QVERIFY(valid()); f.run(); QVERIFY(!gui_fixture::label(w,"priceTotalValue").isEmpty());
        edit(); QCoreApplication::processEvents(); QVERIFY(gui_fixture::results_empty(w));
    }
    QVERIFY(valid()); f.run();
    f.principal->setText(QStringLiteral("0")); f.rate->setText(QStringLiteral("101")); f.term->setText(QStringLiteral("0")); f.run();
    QVERIFY(f.principal->hasFocus()); QCOMPARE(f.principal->text(),QStringLiteral("0")); QVERIFY(gui_fixture::results_empty(w));
    f.principal->setText(QStringLiteral("1000,00")); f.run(); QVERIFY(f.rate->hasFocus());
    f.rate->setText(QStringLiteral("12")); f.kind->setCurrentIndex(-1); f.run(); QVERIFY(f.kind->hasFocus());
    f.kind->setCurrentIndex(0); f.run(); QVERIFY(f.term->hasFocus());
    QVERIFY(f.fill(QStringLiteral("0,01"),QStringLiteral("0"),false,QStringLiteral("600"))); f.run();
    QVERIFY(f.principal->hasFocus()); QVERIFY(gui_fixture::results_empty(w));
    const auto message=gui_fixture::label(w,"validationMessage");
    QVERIFY(!message.isEmpty());
    QVERIFY(message.contains(QStringLiteral("valor"),Qt::CaseInsensitive) || message.contains(QStringLiteral("prazo"),Qt::CaseInsensitive) || message.contains(QStringLiteral("taxa"),Qt::CaseInsensitive));
    QVERIFY(!message.contains(QStringLiteral("/home/"))); QVERIFY(!message.contains(QStringLiteral("Traceback"),Qt::CaseInsensitive));
    QVERIFY(valid()); f.run(); QCOMPARE(gui_fixture::money_number(gui_fixture::label(w,"priceTotalValue")),QStringLiteral("1.020,07"));
    QTest::mouseClick(f.clear,Qt::LeftButton); QCoreApplication::processEvents();
    QVERIFY(f.principal->text().isEmpty()); QVERIFY(f.rate->text().isEmpty()); QVERIFY(f.term->text().isEmpty());
    QCOMPARE(f.kind->currentIndex(),0); QVERIFY(f.principal->hasFocus()); QVERIFY(gui_fixture::results_empty(w));
    w.close();
    gui_fixture::MainWindow fault([](const LoanInput&)->Result<Comparison>{return Error{ErrorCode::ArithmeticError};});
    QVERIFY2(gui_fixture::show(fault),"Precondition: the window manager must activate the error test window before focus assertions."); gui_fixture::Form ff(fault); QVERIFY(ff.valid());
    QVERIFY(ff.fill(QStringLiteral("1000,00"),QStringLiteral("12"),false,QStringLiteral("3"))); ff.run();
    QVERIFY(ff.calculate->hasFocus()); QVERIFY(gui_fixture::results_empty(fault));
    const auto arithmetic=gui_fixture::label(fault,"validationMessage");
    QVERIFY(!arithmetic.isEmpty()); QVERIFY(!arithmetic.contains(QStringLiteral("/home/")));
    QVERIFY(!arithmetic.contains(QStringLiteral("Traceback"),Qt::CaseInsensitive));
}
