/**
 * @file
 * @copyright (c) Copyright 2024-2025 Zenseact AB
 * @license SPDX-License-Identifier: Apache-2.0
 */


#ifndef ZMBT_MODEL_EXPRESSION_GRAMMAR_HPP_
#define ZMBT_MODEL_EXPRESSION_GRAMMAR_HPP_

#include <boost/json.hpp>
#include <boost/spirit/include/qi.hpp>

#include "zmbt-framework/grammars/expr/keyword.hpp"


namespace zmbt {
namespace expr {

/// Boost.Sirit.Qi Symbol for zmbt::Keyword parsing
struct KeywordSymbol : public boost::spirit::qi::symbols<char, Keyword>
{
    KeywordSymbol();
};

/// Boost.Sirit.Qi Grammar for zmbt::Keyword parsing
struct KeywordGrammar : public boost::spirit::qi::grammar<boost::json::string::const_iterator, Keyword()>
{
    KeywordGrammar();

    KeywordSymbol keyword_symbol;
    boost::spirit::qi::rule<boost::json::string::const_iterator, Keyword()> start;
};

// Boost JSON conversion from Keyword
void tag_invoke(boost::json::value_from_tag const&, boost::json::value&, Keyword const& t);

// Boost JSON conversion to Keyword
Keyword tag_invoke(boost::json::value_to_tag<Keyword> const&, boost::json::value const&);

} // namespace expr
} // namespace zmbt


#endif // ZMBT_MAPPING_EXPRESSION_HPP_
