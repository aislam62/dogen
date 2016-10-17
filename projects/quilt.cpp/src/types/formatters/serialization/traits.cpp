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
#include "dogen/quilt.cpp/types/formatters/traits.hpp"
#include "dogen/quilt.cpp/types/formatters/serialization/traits.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace formatters {
namespace serialization {

std::string traits::facet_name() {
    static std::string r(formatters::traits::model_name() + ".serialization");
    return r;
}

std::string traits::canonical_archetype() {
    static std::string r(traits::facet_name() + ".canonical_archetype");
    return r;
}

std::string traits::class_header_archetype() {
    static std::string r(traits::facet_name() + ".class_header_formatter");
    return r;
}

std::string traits::class_implementation_archetype() {
    static std::string r(traits::facet_name() +
        ".class_implementation_formatter");
    return r;
}

std::string traits::enum_header_archetype() {
    static std::string r(traits::facet_name() + ".enum_header_formatter");
    return r;
}

std::string traits::forward_declarations_archetype() {
    static std::string r(traits::facet_name() +
        ".forward_declarations_formatter");
    return r;
}

std::string traits::registrar_header_archetype() {
    static std::string r(traits::facet_name() + ".registrar_header_formatter");
    return r;
}

std::string traits::registrar_implementation_archetype() {
    static std::string r(traits::facet_name() +
        ".registrar_implementation_formatter");
    return r;
}

std::string traits::primitive_header_archetype() {
    static std::string r(traits::facet_name() + ".primitive_header_formatter");
    return r;
}

} } } } }
