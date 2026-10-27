// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#include "money_codec.hpp"
#include <QRegularExpression>
#include <QStringList>

namespace ceseb::ui {
Result<std::int64_t> MoneyCodec::parse_principal(QString text) {
    text=text.trimmed();
    static const QRegularExpression grammar(QStringLiteral("\\A(?:[0-9]+|[0-9]{1,3}(?:\\.[0-9]{3})+)(?:,[0-9]{1,2})?\\z"));
    if (!grammar.match(text).hasMatch()) return Error{ErrorCode::PrincipalOutOfRange};
    text.remove(QLatin1Char('.'));
    const auto parts=text.split(QLatin1Char(','));
    bool valid=false;
    const auto whole=parts.front().toULongLong(&valid);
    if (!valid || whole>100000000) return Error{ErrorCode::PrincipalOutOfRange};
    const auto fraction=parts.size()==2 ? parts.back().leftJustified(2,QLatin1Char('0')).toUInt() : 0U;
    const auto cents=static_cast<std::int64_t>(whole)*100+fraction;
    if (cents<1 || cents>10000000000LL) return Error{ErrorCode::PrincipalOutOfRange};
    return cents;
}
Result<AnnualRate> MoneyCodec::parse_rate(QString text,std::optional<RateKind> kind) {
    if (!kind || (*kind!=RateKind::NominalAnnualMonthlyCapitalization && *kind!=RateKind::EffectiveAnnual)) return Error{ErrorCode::InvalidRateKind};
    text=text.trimmed();
    static const QRegularExpression grammar(QStringLiteral("\\A[0-9]+(?:,[0-9]{1,6})?\\z"));
    if (!grammar.match(text).hasMatch()) return Error{ErrorCode::RateOutOfRange};
    const auto parts=text.split(QLatin1Char(','));
    bool valid=false;
    const auto whole=parts.front().toULongLong(&valid);
    const auto fraction=parts.size()==2 ? parts.back().leftJustified(6,QLatin1Char('0')).toUInt() : 0U;
    if (!valid || whole>100 || (whole==100 && fraction!=0)) return Error{ErrorCode::RateOutOfRange};
    text.replace(QLatin1Char(','),QLatin1Char('.'));
    return AnnualRate{kind,text.toStdString()};
}
Result<int> MoneyCodec::parse_term(QString text) {
    text=text.trimmed();
    static const QRegularExpression grammar(QStringLiteral("\\A[0-9]+\\z"));
    bool valid=false;
    const int months=text.toInt(&valid);
    if (!grammar.match(text).hasMatch() || !valid || months<1 || months>600) return Error{ErrorCode::TermOutOfRange};
    return months;
}
static std::uint64_t magnitude(std::int64_t value) {
    return value<0 ? static_cast<std::uint64_t>(-(value+1))+1 : static_cast<std::uint64_t>(value);
}
QString MoneyCodec::format_money(std::int64_t cents) {
    const auto absolute=magnitude(cents);
    QString whole=QString::number(static_cast<qulonglong>(absolute/100));
    for (qsizetype i=whole.size()-3;i>0;i-=3) whole.insert(i,QLatin1Char('.'));
    return QStringLiteral("R$ ")+(cents<0 ? QStringLiteral("-") : QString{})+whole+QLatin1Char(',')+QString::number(static_cast<qulonglong>(absolute%100)).rightJustified(2,QLatin1Char('0'));
}
QString MoneyCodec::format_percent(std::int64_t millionths) {
    const auto absolute=magnitude(millionths);
    return (millionths<0 ? QStringLiteral("-") : QString{})+QString::number(static_cast<qulonglong>(absolute/1000000))+QLatin1Char(',')+QString::number(static_cast<qulonglong>(absolute%1000000)).rightJustified(6,QLatin1Char('0'))+QLatin1Char('%');
}
}
