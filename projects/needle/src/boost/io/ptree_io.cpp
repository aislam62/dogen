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
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "dogen/needle/boost/io/ptree_io.hpp"

namespace dogen {
namespace needle {
namespace core {
namespace io {

detail::no_op_formatting<std::string>
jsonify(const boost::property_tree::ptree& v) {
    std::ostringstream ss;
    boost::property_tree::write_json(ss, v);

    std::string content(ss.str());
    boost::replace_all(content, "\r\n", "");
    boost::replace_all(content, "\n", "");

    return detail::no_op_formatting<std::string>(content);
}

} } } }