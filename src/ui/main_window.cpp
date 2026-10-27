// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include "main_window.hpp"
#include "money_codec.hpp"
#include "simulation_controller.hpp"
#include <ceseb/version.hpp>
#include <QApplication>
#include <QBoxLayout>
#include <QComboBox>
#include <QDesktopServices>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDir>
#include <QFile>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QResizeEvent>
#include <QScrollArea>
#include <QShortcut>
#include <QTextBrowser>
#include <QUrl>

static void register_application_resources() { Q_INIT_RESOURCE(application); }
namespace ceseb::ui {
MainWindow::MainWindow(CompareFunction compare,QWidget* parent) : QMainWindow(parent) {
    register_application_resources();
    setWindowTitle(QStringLiteral("CESEB · Calculadora de financiamento"));
    setStyleSheet(QStringLiteral(
        "QMainWindow,QScrollArea{background:#f3f5f8;}"
        "QLabel{color:#182738;}"
        "QFrame[card=\"true\"]{background:white;border:1px solid #dfe5ed;border-radius:12px;}"
        "QLabel[muted=\"true\"]{color:#526579;}"
        "QLineEdit,QComboBox{background:white;border:1px solid #bac8d8;border-radius:6px;padding:8px;min-height:22px;}"
        "QLineEdit:focus,QComboBox:focus{border:2px solid #2563c5;padding:7px;}"
        "QPushButton{border:1px solid #bac8d8;border-radius:7px;padding:9px 15px;background:white;color:#182738;}"
        "QPushButton:focus{border:2px solid #2563c5;padding:8px 14px;}"
        "QPushButton#calculateButton{background:#245fcc;color:white;border-color:#245fcc;font-weight:600;}"
        "QPushButton#calculateButton:hover{background:#1c4fae;}"
        "QLabel#validationMessage{color:#a1222c;}"));
    auto* scroll=new QScrollArea(this);
    scroll->setObjectName(QStringLiteral("resultScrollArea"));
    scroll->setWidgetResizable(true);scroll->setFrameShape(QFrame::NoFrame);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);scroll->setFocusPolicy(Qt::NoFocus);
    auto* content=new QWidget(scroll);
    auto* page=new QVBoxLayout(content);page->setContentsMargins(26,24,26,24);page->setSpacing(18);
    auto* top=new QHBoxLayout;
    auto* title=new QLabel(QStringLiteral("Simule seu financiamento"),content);
    QFont titleFont=title->font();titleFont.setPointSize(21);titleFont.setBold(true);title->setFont(titleFont);title->setWordWrap(true);
    about_=new QPushButton(QStringLiteral("Sobre e modelo"),content);about_->setObjectName(QStringLiteral("aboutButton"));
    top->addWidget(title,1);top->addWidget(about_);page->addLayout(top);
    auto* subtitle=new QLabel(QStringLiteral("Compare Price e SAC com as mesmas condições. Cálculo local, em reais."),content);
    subtitle->setProperty("muted",true);subtitle->setWordWrap(true);page->addWidget(subtitle);
    auto* formCard=new QFrame(content);formCard->setProperty("card",true);
    auto* form=new QGridLayout(formCard);form->setContentsMargins(18,18,18,18);form->setHorizontalSpacing(16);form->setVerticalSpacing(9);
    principal_=new QLineEdit(QStringLiteral("250.000,00"),formCard);principal_->setObjectName(QStringLiteral("principalInput"));
    rate_=new QLineEdit(QStringLiteral("4,5"),formCard);rate_->setObjectName(QStringLiteral("rateInput"));
    term_=new QLineEdit(QStringLiteral("360"),formCard);term_->setObjectName(QStringLiteral("termInput"));
    kind_=new QComboBox(formCard);kind_->setObjectName(QStringLiteral("rateKindInput"));
    kind_->addItem(QStringLiteral("Nominal anual — capitalização mensal"),static_cast<int>(RateKind::NominalAnnualMonthlyCapitalization));
    kind_->addItem(QStringLiteral("Efetiva anual"),static_cast<int>(RateKind::EffectiveAnnual));
    const auto field=[&](const QString& text,const char* name,QWidget* input,int row,int column) {
        auto* label=new QLabel(text,formCard);label->setObjectName(QString::fromLatin1(name));label->setBuddy(input);
        input->setAccessibleName(text);input->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        form->addWidget(label,row,column);form->addWidget(input,row+1,column);
    };
    field(QStringLiteral("Valor financiado (R$)"),"principalLabel",principal_,0,0);
    field(QStringLiteral("Taxa anual (%)"),"rateLabel",rate_,0,1);
    field(QStringLiteral("Tipo de taxa"),"rateKindLabel",kind_,2,0);
    field(QStringLiteral("Prazo (meses)"),"termLabel",term_,2,1);
    form->setColumnStretch(0,1);form->setColumnStretch(1,1);
    auto* actions=new QHBoxLayout;
    calculate_=new QPushButton(QStringLiteral("Calcular"),formCard);calculate_->setObjectName(QStringLiteral("calculateButton"));
    clear_=new QPushButton(QStringLiteral("Limpar"),formCard);clear_->setObjectName(QStringLiteral("clearButton"));
    actions->addWidget(calculate_);actions->addWidget(clear_);actions->addStretch();form->addLayout(actions,4,0,1,2);
    message_=new QLabel(formCard);message_->setObjectName(QStringLiteral("validationMessage"));message_->setWordWrap(true);
    form->addWidget(message_,5,0,1,2);page->addWidget(formCard);
    auto* rates=new QFrame(content);rates->setProperty("card",true);
    auto* rateLayout=new QGridLayout(rates);rateLayout->setContentsMargins(18,15,18,15);rateLayout->setHorizontalSpacing(16);
    const auto valueLabel=[&](const char* name,QWidget* owner) {
        auto* value=new QLabel(owner);value->setObjectName(QString::fromLatin1(name));value->setWordWrap(true);
        value->setTextInteractionFlags(Qt::TextSelectableByMouse|Qt::TextSelectableByKeyboard);value->setFocusPolicy(Qt::ClickFocus);
        QFont font=value->font();font.setBold(true);font.setPointSize(12);value->setFont(font);
        results_.emplace(QString::fromLatin1(name),value);return value;
    };
    const char* rateNames[]={"monthlyRateValue","nominalAnnualRateValue","effectiveAnnualRateValue"};
    const QString captions[]={QStringLiteral("Efetiva mensal"),QStringLiteral("Nominal anual equivalente"),QStringLiteral("Efetiva anual equivalente")};
    for (int i=0;i<3;++i) {
        auto* label=new QLabel(captions[i],rates);label->setWordWrap(true);label->setProperty("muted",true);
        rateLayout->addWidget(label,0,i);rateLayout->addWidget(valueLabel(rateNames[i],rates),1,i);rateLayout->setColumnStretch(i,1);
    }
    page->addWidget(rates);
    auto* termRow=new QHBoxLayout;termRow->addWidget(new QLabel(QStringLiteral("Prazo informado"),content));termRow->addWidget(valueLabel("requestedTermValue",content));termRow->addStretch();page->addLayout(termRow);
    cards_=new QBoxLayout(QBoxLayout::LeftToRight);cards_->setSpacing(18);
    const auto card=[&](const QString& heading,bool isPrice) {
        auto* frame=new QFrame(content);frame->setProperty("card",true);
        auto* box=new QVBoxLayout(frame);box->setContentsMargins(18,18,18,18);box->setSpacing(8);
        auto* h=new QLabel(heading,frame);QFont f=h->font();f.setPointSize(17);f.setBold(true);h->setFont(f);box->addWidget(h);
        const auto row=[&](const QString& caption,const char* name) {
            auto* label=new QLabel(caption,frame);label->setProperty("muted",true);label->setWordWrap(true);
            box->addWidget(label);box->addWidget(valueLabel(name,frame));
        };
        row(isPrice ? QStringLiteral("Parcela ordinária") : QStringLiteral("Primeira parcela"),isPrice ? "priceOrdinaryValue" : "sacFirstValue");
        row(QStringLiteral("Última parcela"),isPrice ? "priceLastValue" : "sacLastValue");
        row(QStringLiteral("Pagamentos efetivos"),isPrice ? "pricePaymentsValue" : "sacPaymentsValue");
        row(QStringLiteral("Total pago"),isPrice ? "priceTotalValue" : "sacTotalValue");
        row(QStringLiteral("Juros totais"),isPrice ? "priceInterestValue" : "sacInterestValue");
        if (isPrice) {auto* notice=valueLabel("priceAdjustmentNotice",frame);QFont nf=notice->font();nf.setPointSize(10);nf.setBold(false);notice->setFont(nf);box->addWidget(notice);}
        box->addStretch();cards_->addWidget(frame,1);
    };
    card(QStringLiteral("Price"),true);card(QStringLiteral("SAC"),false);page->addLayout(cards_);
    auto* difference=new QHBoxLayout;difference->addWidget(new QLabel(QStringLiteral("Diferença de juros (Price − SAC)"),content));difference->addWidget(valueLabel("interestDifferenceValue",content));difference->addStretch();page->addLayout(difference);
    auto* footer=new QLabel(QStringLiteral("Principal + juros deste modelo. Seguros, tarifas, impostos e indexadores não incluídos. Não é CET."),content);footer->setWordWrap(true);footer->setProperty("muted",true);page->addWidget(footer);
    scroll->setWidget(content);setCentralWidget(scroll);
    setTabOrder(principal_,rate_);setTabOrder(rate_,kind_);setTabOrder(kind_,term_);setTabOrder(term_,calculate_);setTabOrder(calculate_,clear_);setTabOrder(clear_,about_);
    auto* enterKind=new QShortcut(QKeySequence(Qt::Key_Return),kind_);enterKind->setContext(Qt::WidgetShortcut);
    connect(enterKind,&QShortcut::activated,calculate_,&QPushButton::click);
    auto* escape=new QShortcut(QKeySequence(Qt::Key_Escape),this);connect(escape,&QShortcut::activated,this,&QWidget::close);
    new SimulationController(*this,std::move(compare));
    resize(1040,760);principal_->setFocus();
}
void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    if (cards_) cards_->setDirection(width()<900 ? QBoxLayout::TopToBottom : QBoxLayout::LeftToRight);
}
void MainWindow::clear_results() {
    for (auto& item:results_) item.second->clear();
    message_->clear();
}
void MainWindow::present(const Comparison& comparison,const QuantizedRates& rates) {
    const auto set=[&](const char* name,const QString& value){results_.at(QString::fromLatin1(name))->setText(value);};
    set("monthlyRateValue",MoneyCodec::format_percent(rates.monthly_percent_millionths));
    set("nominalAnnualRateValue",MoneyCodec::format_percent(rates.nominal_annual_percent_millionths));
    set("effectiveAnnualRateValue",MoneyCodec::format_percent(rates.effective_annual_percent_millionths));
    const auto& p=comparison.price.summary;const auto& s=comparison.sac.summary;
    set("requestedTermValue",QStringLiteral("%1 meses").arg(p.requested_months));
    set("priceOrdinaryValue",MoneyCodec::format_money(p.ordinary_payment));set("priceLastValue",MoneyCodec::format_money(p.last_payment));
    set("pricePaymentsValue",QString::number(p.actual_payments));set("priceTotalValue",MoneyCodec::format_money(p.payment_total));set("priceInterestValue",MoneyCodec::format_money(p.interest_total));
    set("sacFirstValue",MoneyCodec::format_money(s.first_payment));set("sacLastValue",MoneyCodec::format_money(s.last_payment));
    set("sacPaymentsValue",QString::number(s.actual_payments));set("sacTotalValue",MoneyCodec::format_money(s.payment_total));set("sacInterestValue",MoneyCodec::format_money(s.interest_total));
    auto difference=MoneyCodec::format_money(comparison.interest_difference);
    if (comparison.interest_difference>0) difference.replace(QStringLiteral("R$ "),QStringLiteral("R$ +"));
    set("interestDifferenceValue",difference);
    if (p.requested_months==1) set("priceAdjustmentNotice",QStringLiteral("Parcela única, com quitação final."));
    else if (p.early_payoff) set("priceAdjustmentNotice",QStringLiteral("Quitado em %1 de %2 meses por ajuste de centavos.").arg(p.actual_payments).arg(p.requested_months));
    else if (p.last_payment!=p.ordinary_payment) set("priceAdjustmentNotice",QStringLiteral("Última parcela ajustada para quitação."));
}
void MainWindow::show_error(ErrorCode code) {
    clear_results();QWidget* focus=calculate_;QString text;
    switch(code) {
    case ErrorCode::PrincipalOutOfRange:text=QStringLiteral("Informe um valor válido entre R$ 0,01 e R$ 100.000.000,00, com até duas casas decimais.");focus=principal_;break;
    case ErrorCode::InvalidRateKind:text=QStringLiteral("Selecione o tipo de taxa anual.");focus=kind_;break;
    case ErrorCode::NonFiniteRate:case ErrorCode::RateOutOfRange:text=QStringLiteral("Informe uma taxa de 0% a 100%, com vírgula e até seis casas decimais.");focus=rate_;break;
    case ErrorCode::TermOutOfRange:text=QStringLiteral("Informe um prazo inteiro entre 1 e 600 meses.");focus=term_;break;
    case ErrorCode::UnsupportedCentPrecision:text=QStringLiteral("Esta combinação não permite amortizar em centavos. Ajuste o valor, o prazo ou a taxa.");focus=principal_;break;
    case ErrorCode::ArithmeticError:text=QStringLiteral("Não foi possível concluir o cálculo. Revise os dados e tente novamente.");break;
    }
    message_->setText(text);focus->setFocus();
}
void MainWindow::show_about() {
    if (auto* existing=findChild<QDialog*>(QStringLiteral("aboutDialog"))) {existing->show();existing->raise();existing->activateWindow();return;}
    auto* dialog=new QDialog(this);dialog->setObjectName(QStringLiteral("aboutDialog"));dialog->setAttribute(Qt::WA_DeleteOnClose);dialog->setWindowTitle(QStringLiteral("Sobre e modelo"));dialog->resize(650,560);
    auto* layout=new QVBoxLayout(dialog);auto* model=new QTextBrowser(dialog);model->setObjectName(QStringLiteral("modelText"));model->setOpenExternalLinks(false);
    QFile help(QStringLiteral(":/ceseb/model-help.html"));if (help.open(QIODevice::ReadOnly)) model->setHtml(QString::fromUtf8(help.readAll()));
    layout->addWidget(model);
    auto* version=new QLabel(QStringLiteral("CESEB %1 · revisão %2").arg(QString::fromLatin1(ceseb::version::number),QString::fromLatin1(ceseb::version::revision)),dialog);version->setObjectName(QStringLiteral("versionValue"));version->setWordWrap(true);layout->addWidget(version);
    const QUrl licenses=QUrl::fromLocalFile(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath(QStringLiteral("../licenses")));
    auto* links=new QLabel(QStringLiteral("<a href=\"%1\">Licenças e avisos locais</a>").arg(licenses.toString().toHtmlEscaped()),dialog);links->setObjectName(QStringLiteral("licenseLinks"));links->setOpenExternalLinks(false);
    connect(links,&QLabel::linkActivated,dialog,[](const QString& value){const QUrl url(value);if(url.isLocalFile()) QDesktopServices::openUrl(url);});layout->addWidget(links);
    auto* buttons=new QDialogButtonBox(QDialogButtonBox::Close,dialog);buttons->button(QDialogButtonBox::Close)->setText(QStringLiteral("Fechar"));connect(buttons,&QDialogButtonBox::rejected,dialog,&QDialog::close);layout->addWidget(buttons);dialog->show();
}
}
