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
#include "dogen/yarn/types/enumeration.hpp"
#include "dogen/cpp/types/formatters/traits.hpp"
#include "dogen/cpp/types/formatters/types/traits.hpp"
#include "dogen/cpp/types/formatters/entity_formatting_assistant.hpp"
#include "dogen/cpp/types/formatters/types/enum_header_formatter_stitch.hpp"
#include "dogen/cpp/types/formatters/types/enum_header_formatter.hpp"
#include "dogen/cpp/types/formatters/types/enum_header_formatter.hpp"

namespace dogen {
namespace cpp {
namespace formatters {
namespace types {

std::string enum_header_formatter::static_formatter_name() {
    return traits::enum_header_formatter_name();
}

dynamic::ownership_hierarchy enum_header_formatter::
ownership_hierarchy() const {
    static dynamic::ownership_hierarchy
        r(formatters::traits::model_name(), traits::facet_name(),
            enum_header_formatter::static_formatter_name(),
            formatters::traits::header_formatter_group_name());
    return r;
}

file_types enum_header_formatter::file_type() const {
    return file_types::cpp_header;
}

formattables::origin_types
enum_header_formatter::formattable_origin_type() const {
    return formattables::origin_types::external;
}

void enum_header_formatter::register_inclusion_dependencies_provider(
    formattables::registrar& /*rg*/) const {}

dogen::formatters::file enum_header_formatter::
format(const context& ctx, const formattables::enum_info& c) const {
    entity_formatting_assistant fa(c, ctx, ownership_hierarchy(), file_type());
    const auto r(enum_header_formatter_stitch(fa, c));
    return r;
}

} } } }
