/**
 * @file
 * @copyright (c) Copyright 2022-2023 Volvo Car Corporation
 * @copyright (c) Copyright 2024 Zenseact AB
 * @license SPDX-License-Identifier: Apache-2.0
 */

#include "zmbt/logging.hpp"
#include "zmbt/core.hpp"
#include "zmbt/reflect.hpp"
#include "zmbt/model/signal_operator_handler.hpp"
#include "zmbt/model/expression.hpp"
#include "zmbt/model/exceptions.hpp"
#include "zmbt/model/keyword_codegen_type.hpp"


namespace
{

using V = boost::json::value;
using O = zmbt::SignalOperatorHandler;
using E = zmbt::Expression;
using Keyword = zmbt::dsl::Keyword;
}

namespace zmbt {

boost::json::value Expression::eval_UnaryOp(boost::json::value const& x, SignalOperatorHandler const& op) const
{
    return op.apply(keyword(), nullptr, Expression(x).eval());
}

boost::json::value Expression::eval_BinaryOp(boost::json::value const& x, SignalOperatorHandler const& op) const
{
    V const* lhs {nullptr}; // binary LHS or expr params
    V const* rhs {nullptr}; // binary RHS or expr arg
    handle_binary_args(x, lhs, rhs);
    if (not (lhs and rhs))
    {
        throw zmbt::expression_error("Invalid binary operation: %s << %s", serialize(), x);
    }
    return op.apply(keyword(), Expression(*lhs).eval(), Expression(*rhs).eval());
}


} // namespace zmbt

