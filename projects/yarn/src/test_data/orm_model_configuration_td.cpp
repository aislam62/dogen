/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
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
#include <sstream>
#include "dogen/yarn/test_data/letter_cases_td.hpp"
#include "dogen/yarn/test_data/orm_database_systems_td.hpp"
#include "dogen/yarn/test_data/orm_model_configuration_td.hpp"

namespace {

dogen::yarn::orm_database_systems
create_dogen_yarn_orm_database_systems(const unsigned int position) {
    return dogen::yarn::orm_database_systems_generator::create(position);
}

std::vector<dogen::yarn::orm_database_systems> create_std_vector_dogen_yarn_orm_database_systems(unsigned int position) {
    std::vector<dogen::yarn::orm_database_systems> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_dogen_yarn_orm_database_systems(position + i));
    }
    return r;
}

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

dogen::yarn::letter_cases
create_dogen_yarn_letter_cases(const unsigned int position) {
    return dogen::yarn::letter_cases_generator::create(position);
}

boost::optional<dogen::yarn::letter_cases>
create_boost_optional_dogen_yarn_letter_cases(unsigned int position) {
    boost::optional<dogen::yarn::letter_cases> r(
        create_dogen_yarn_letter_cases(position));
    return r;
}

}

namespace dogen {
namespace yarn {

orm_model_configuration_generator::orm_model_configuration_generator() : position_(0) { }

void orm_model_configuration_generator::
populate(const unsigned int position, result_type& v) {
    v.database_systems(create_std_vector_dogen_yarn_orm_database_systems(position + 0));
    v.schema_name(create_std_string(position + 1));
    v.letter_case(create_boost_optional_dogen_yarn_letter_cases(position + 2));
}

orm_model_configuration_generator::result_type
orm_model_configuration_generator::create(const unsigned int position) {
    orm_model_configuration r;
    orm_model_configuration_generator::populate(position, r);
    return r;
}

orm_model_configuration_generator::result_type*
orm_model_configuration_generator::create_ptr(const unsigned int position) {
    orm_model_configuration* p = new orm_model_configuration();
    orm_model_configuration_generator::populate(position, *p);
    return p;
}

orm_model_configuration_generator::result_type
orm_model_configuration_generator::operator()() {
    return create(position_++);
}

} }
