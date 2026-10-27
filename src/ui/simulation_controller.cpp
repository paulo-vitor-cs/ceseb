// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include "simulation_controller.hpp"
#include "money_codec.hpp"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <array>

namespace ceseb::ui {
SimulationController::SimulationController(MainWindow& window,CompareFunction compare)
    : QObject(&window),window_(window),compare_(std::move(compare)) {
    for (auto* field:std::array<QLineEdit*,3>{window_.principal_,window_.rate_,window_.term_}) {
        connect(field,&QLineEdit::textChanged,this,[this]{invalidate();});
        connect(field,&QLineEdit::returnPressed,this,[this]{calculate();});
    }
    connect(window_.kind_,&QComboBox::currentIndexChanged,this,[this]{invalidate();});
    connect(window_.calculate_,&QPushButton::clicked,this,[this]{calculate();});
    connect(window_.clear_,&QPushButton::clicked,this,[this]{
        window_.principal_->clear();window_.rate_->clear();window_.term_->clear();
        window_.kind_->setCurrentIndex(0);invalidate();window_.principal_->setFocus();
    });
    connect(window_.about_,&QPushButton::clicked,this,[this]{window_.show_about();});
}
void SimulationController::invalidate() { window_.clear_results(); }
void SimulationController::calculate() {
    window_.clear_results();
    try {
        const auto principal=MoneyCodec::parse_principal(window_.principal_->text());
        if (const auto* e=std::get_if<Error>(&principal)) {window_.show_error(e->code);return;}
        std::optional<RateKind> kind;
        if (window_.kind_->currentIndex()>=0) kind=static_cast<RateKind>(window_.kind_->currentData().toInt());
        const auto rate=MoneyCodec::parse_rate(window_.rate_->text(),kind);
        if (const auto* e=std::get_if<Error>(&rate)) {window_.show_error(e->code);return;}
        const auto term=MoneyCodec::parse_term(window_.term_->text());
        if (const auto* e=std::get_if<Error>(&term)) {window_.show_error(e->code);return;}
        const auto comparison=compare_(LoanInput{std::get<std::int64_t>(principal),std::get<int>(term),std::get<AnnualRate>(rate)});
        if (const auto* e=std::get_if<Error>(&comparison)) {window_.show_error(e->code);return;}
        const auto& result=std::get<Comparison>(comparison);
        const auto quantized=quantize_rates(result.rate);
        if (const auto* e=std::get_if<Error>(&quantized)) {window_.show_error(e->code);return;}
        window_.present(result,std::get<QuantizedRates>(quantized));
    } catch (const std::exception&) {window_.show_error(ErrorCode::ArithmeticError);}
}
}
