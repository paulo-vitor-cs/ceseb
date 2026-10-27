// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#pragma once
#include <ceseb/finance.hpp>
#include <QString>

namespace ceseb::ui {
class MoneyCodec {
public:
    static Result<std::int64_t> parse_principal(QString);
    static Result<AnnualRate> parse_rate(QString,std::optional<RateKind>);
    static Result<int> parse_term(QString);
    static QString format_money(std::int64_t);
    static QString format_percent(std::int64_t);
};
}
