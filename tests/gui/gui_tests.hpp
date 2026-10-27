// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs

#pragma once
#include <ceseb/finance.hpp>
#include "ui/main_window.hpp"
#include "ui/money_codec.hpp"
#include <QtTest/QTest>
#include <QComboBox>
#include <QCoreApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegularExpression>
#include <QString>
#include <array>
#include <variant>

class GuiContractTests final: public QObject {
    Q_OBJECT
private slots:
    void req1211_localized_input();
    void req1212_rate_presentation();
    void req1213_comparison_presentation();
    void req1214_state_recovery();
};
namespace gui_fixture {
using ceseb::ui::MainWindow;
template<class T> T* named(MainWindow& window,const char* name) {
    return window.findChild<T*>(QString::fromLatin1(name));
}
struct Form {
    MainWindow& window;
    QLineEdit* principal;
    QLineEdit* rate;
    QComboBox* kind;
    QLineEdit* term;
    QPushButton* calculate;
    QPushButton* clear;
    QPushButton* about;
    explicit Form(MainWindow& w):window(w),principal(named<QLineEdit>(w,"principalInput")),rate(named<QLineEdit>(w,"rateInput")),kind(named<QComboBox>(w,"rateKindInput")),term(named<QLineEdit>(w,"termInput")),calculate(named<QPushButton>(w,"calculateButton")),clear(named<QPushButton>(w,"clearButton")),about(named<QPushButton>(w,"aboutButton")) {}
    bool valid() const { return principal && rate && kind && term && calculate && clear && about; }
    bool fill(const QString& p,const QString& r,bool effective,const QString& n) {
        if (!valid()) return false;
        principal->setText(p); rate->setText(r); term->setText(n);
        const int index=kind->findText(effective ? QStringLiteral("Efetiva anual") : QStringLiteral("Nominal anual"),Qt::MatchStartsWith);
        if (index<0) return false;
        kind->setCurrentIndex(index);
        QCoreApplication::processEvents();
        return true;
    }
    void run() { QTest::mouseClick(calculate,Qt::LeftButton); QCoreApplication::processEvents(); }
};
inline QString label(MainWindow& window,const char* name) {
    const auto* w=named<QLabel>(window,name);
    return w ? w->text() : QString{};
}
inline QString money_number(QString text) {
    text.remove(QStringLiteral("R$")); text.remove(QChar(0x00a0)); text.remove(QChar(0x202f));
    text=text.trimmed(); if (text.startsWith(QLatin1Char('+'))) text.remove(0,1);
    return text.trimmed();
}
inline QString percentage_number(QString text) { text.remove(QLatin1Char('%')); return text.trimmed(); }
inline bool contains_integer(const QString& text,int value) {
    return text.contains(QRegularExpression(QStringLiteral("(^|\\D)%1(\\D|$)").arg(value)));
}
inline constexpr std::array<const char*,16> result_names{
    "monthlyRateValue","nominalAnnualRateValue","effectiveAnnualRateValue","requestedTermValue",
    "priceOrdinaryValue","priceLastValue","pricePaymentsValue","priceTotalValue","priceInterestValue","priceAdjustmentNotice",
    "sacFirstValue","sacLastValue","sacPaymentsValue","sacTotalValue","sacInterestValue","interestDifferenceValue"};
inline bool results_empty(MainWindow& w) {
    for (const auto* name:result_names) {
        const auto* item=named<QLabel>(w,name);
        if (!item || !item->text().isEmpty()) return false;
    }
    return true;
}
inline bool show(MainWindow& w) {
    w.show();
    w.activateWindow();
    return QTest::qWaitForWindowActive(&w);
}
}
