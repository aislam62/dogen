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
#include "dogen/test_models/database/test_data/northwind/region_id_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return static_cast<int>(position);
}

}

namespace dogen {
namespace test_models {
namespace database {
namespace northwind {

region_id_generator::region_id_generator() : position_(0) { }

void region_id_generator::
populate(const unsigned int position, result_type& v) {
    v.value(create_int(position + 1));
}

region_id_generator::result_type
region_id_generator::create(const unsigned int position) {
    region_id r;
    region_id_generator::populate(position, r);
    return r;
}

region_id_generator::result_type*
region_id_generator::create_ptr(const unsigned int position) {
    region_id* r = new region_id();
    region_id_generator::populate(position, *r);
    return r;
}

region_id_generator::result_type
region_id_generator::operator()() {
    return create(position_++);
}

} } } }
