/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
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
#include <boost/test/unit_test.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/sml/types/model.hpp"
#include "dogen/sml/io/model_io.hpp"
#include "dogen/config/test/mock_settings_factory.hpp"
#include "dogen/cpp/types/transformer.hpp"

using dogen::config::cpp_facet_types;
using namespace dogen::cpp;

namespace {

const std::string empty;
const std::string test_module("cpp");
const std::string test_suite("transformer_spec");

}

BOOST_AUTO_TEST_SUITE(transformer)

BOOST_AUTO_TEST_CASE(transforming_enumeration_results_in_expected_enumeration_info) {
    SETUP_TEST_LOG("transforming_enumeration_results_in_expected_enumeration_info");
}

BOOST_AUTO_TEST_SUITE_END()
