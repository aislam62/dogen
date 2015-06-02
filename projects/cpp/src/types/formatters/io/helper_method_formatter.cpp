/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include "dogen/utility/log/logger.hpp"
#include "dogen/cpp/types/formatters/formatting_error.hpp"
#include "dogen/cpp/types/formatters/io/associative_container_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/optional_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/pair_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/ptree_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/sequence_container_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/smart_pointer_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/string_helper_stitch.hpp"
#include "dogen/cpp/types/formatters/io/variant_helper_stitch.hpp"

#include "dogen/cpp/types/formatters/io/helper_method_formatter.hpp"

namespace {

using namespace dogen::utility::log;
auto lg(logger_factory("cpp.formatters.io.helper_method_formatter"));

const std::string invalid_sequence_container(
    "Sequence containers have exactly one type argument");
const std::string invalid_associative_container(
    "Associative containers have one or two type arguments");
const std::string invalid_smart_pointer(
    "Smart pointers have exactly one type argument");
const std::string invalid_optional_type(
    "Optional types have exactly one type argument");
const std::string invalid_pair_type(
    "Pair types have exactly two type arguments");
const std::string invalid_variant("Variants should have at least one type");
const std::string invalid_ptree("Ptree's should have no type arguments");

}

namespace dogen {
namespace cpp {
namespace formatters {
namespace io {

helper_method_formatter::helper_method_formatter(
    const std::list<formattables::property_info>& properties)
    : properties_(properties) {}


void helper_method_formatter::sequence_container_helper(std::ostream& s,
    const formattables::nested_type_info& t) const {

    if (t.children().size() != 1) {
        BOOST_LOG_SEV(lg, error) << invalid_sequence_container;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_sequence_container));
    }
    sequence_container_helper_stitch(s, t);
}

void helper_method_formatter::associative_container_helper(std::ostream& s,
    const formattables::nested_type_info& t) const {

    if (t.children().size() != 1 && t.children().size() != 2) {
        BOOST_LOG_SEV(lg, error) << invalid_associative_container;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_associative_container));
    }

    if (t.children().size() == 1) {
        sequence_container_helper(s, t);
        return;
    }
    associative_container_helper_stitch(s, t);
}

void helper_method_formatter::smart_pointer_helper(std::ostream& s,
    const formattables::nested_type_info& t) const {

    if (t.children().size() != 1) {
        BOOST_LOG_SEV(lg, error) << invalid_smart_pointer;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_smart_pointer));
    }
    smart_pointer_helper_stitch(s, t);
}

void helper_method_formatter::optional_helper(std::ostream& s,
    const formattables::nested_type_info& t) const {
    if (t.children().size() != 1) {
        BOOST_LOG_SEV(lg, error) << invalid_optional_type;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_optional_type));
    }

    optional_helper_stitch(s, t);
}

void helper_method_formatter::
pair_helper(std::ostream& s, const formattables::nested_type_info& t) const {
    if (t.children().size() != 2) {
        BOOST_LOG_SEV(lg, error) << invalid_pair_type;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_pair_type));
    }

    pair_helper_stitch(s, t);
}

void helper_method_formatter::
variant_helper(std::ostream& s, const formattables::nested_type_info& t) const {
    if (t.children().empty()) {
        BOOST_LOG_SEV(lg, error) << invalid_variant;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_variant));
    }

    variant_helper_stitch(s, t);
}

void helper_method_formatter::ptree_helper(std::ostream& s,
    const formattables::nested_type_info& t) const {
    if (!t.children().empty()) {
        BOOST_LOG_SEV(lg, error) << invalid_ptree;
        BOOST_THROW_EXCEPTION(formatting_error(invalid_ptree));
    }

    ptree_helper_stitch(s, t);
}

void helper_method_formatter::recursive_helper_method_creator(
    std::ostream& s,
    const formattables::nested_type_info& t,
    std::unordered_set<std::string>& types_done) const {

    if (types_done.find(t.complete_identifiable_name()) != types_done.end())
        return;

    for (const auto c : t.children())
        recursive_helper_method_creator(s, c, types_done);

    if (t.is_sequence_container())
        sequence_container_helper(s, t);
    else if (t.is_associative_container())
        associative_container_helper(s, t);
    else if (t.is_smart_pointer())
        smart_pointer_helper(s, t);
    else if (t.is_optional_like())
        optional_helper(s, t);
    else if (t.is_pair())
        pair_helper(s, t);
    else if (t.is_variant_like())
        variant_helper(s, t);
    else if (t.is_ptree())
        ptree_helper(s, t);
    else if (t.is_string_like() && !t.is_char_like())
        string_helper_stitch(s, t);

    types_done.insert(t.complete_identifiable_name());
}

void helper_method_formatter::format(std::ostream& s) const {
    if (properties_.empty())
        return;

    std::unordered_set<std::string> types_done;
    for (const auto p : properties_)
        recursive_helper_method_creator(s, p.type(), types_done);
}

} } } }