// SPDX-License-Identifier: MIT
// Copyright (c) 2026 paulo-vitor-cs
#pragma once
#include <ceseb/finance.hpp>
#include <stdexcept>
#include <utility>

namespace ceseb::detail {
using Integer = boost::multiprecision::cpp_int;
struct Failure : std::runtime_error {
    ErrorCode code;
    explicit Failure(ErrorCode value) : std::runtime_error("Financial calculation rejected"), code(value) {}
};
template<class T, class F> Result<T> guarded(F&& function) {
    try { return function(); }
    catch (const Failure& failure) { return Error{failure.code}; }
    catch (const std::exception&) { return Error{ErrorCode::ArithmeticError}; }
}
Integer power(Integer, unsigned);
Rational power(Rational, unsigned);
Rational decimal_fraction(const std::string&);
std::optional<Integer> exact_twelfth_root(const Integer&);
std::int64_t checked_integer(const Integer&);
std::int64_t round_half_up(const Rational&);
std::int64_t add(std::int64_t, std::int64_t);
Decimal decimal_projection(const Rational&);
std::pair<Rational, Rational> root_bounds(const Rational&);
std::int64_t rounded_monthly_product(const NormalizedRate&, std::int64_t);
std::int64_t price_payment(std::int64_t, int, const NormalizedRate&);
}
