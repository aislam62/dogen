/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright(C) 2012 Kitanda <info@kitanda.co.uk>
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
#include "dogen/cpp/types/formatters/test_data/ptime_helper_stitch.hpp"

namespace dogen {
namespace cpp {
namespace formatters {
namespace test_data {

void ptime_helper_stitch(
    formatters::nested_type_formatting_assistant& fa,
    const formattables::nested_type_info& t) {
fa.stream() << std::endl;
fa.stream() << t.complete_name() << std::endl;
fa.stream() << "create_" << t.complete_identifiable_name() << "(const unsigned int position) {" << std::endl;
fa.stream() << "    unsigned int day((position + 1) % 27);" << std::endl;
fa.stream() << "    using boost::gregorian::date;" << std::endl;
fa.stream() << "    using boost::posix_time::ptime;" << std::endl;
fa.stream() << "    using boost::posix_time::time_duration;" << std::endl;
fa.stream() << "    date d(2002, 2, day);" << std::endl;
fa.stream() << "    ptime r(d, time_duration(1,2,3));" << std::endl;
fa.stream() << "    return r;" << std::endl;
fa.stream() << "}" << std::endl;
}
} } } }
