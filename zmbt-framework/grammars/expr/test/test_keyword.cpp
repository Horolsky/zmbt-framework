/**
 * @file
 * @copyright (c) Copyright 2025 Zenseact AB
 * @license SPDX-License-Identifier: Apache-2.0
 */

#include <boost/json.hpp>

#include <boost/test/unit_test.hpp>

#include "zmbt-framework/grammars/expr/keyword_grammar.hpp"


namespace utf = boost::unit_test;

using namespace zmbt::expr;
using namespace boost::json;

using V = boost::json::value;


BOOST_AUTO_TEST_CASE(KeywordSerialization)
{
    auto const original = Keyword::Intersect;
    value js = boost::json::value_from(original);
    auto const converted = boost::json::value_to<Keyword>(js);
    BOOST_CHECK(original == converted);
}

