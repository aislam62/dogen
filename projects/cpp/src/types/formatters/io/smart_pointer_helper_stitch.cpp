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
#include "dogen/cpp/types/formatters/io/sequence_container_helper_stitch.hpp"

namespace dogen {
namespace cpp {
namespace formatters {
namespace io {

void smart_pointer_helper_stitch(
    formatters::nested_type_formatting_assistant& fa,
    const formattables::nested_type_info& t) {
    
    {
        auto snf(fa.make_scoped_namespace_formatter(t));
        const auto containee(t.children().front());
fa.stream() << std::endl;
fa.stream() << "inline std::ostream& operator<<(std::ostream& s, const " << t.complete_name() << "& v) {" << std::endl;
fa.stream() << "    s << \'{ \' << \'\\'__type__\\': \\'\' << " << t.name() << " \'\\', \'" << std::endl;
fa.stream() << "      << \'\\'memory\\': \' << \'\\'\' << \'static_cast<void*>(v.get()) << \'\\'\';" << std::endl;
fa.stream() << "    if (v)" << std::endl;
fa.stream() << "        s << \'\\'data\\': \' << " << fa.streaming_for_type(containee, "*v") << " << \';\'" << std::endl;
fa.stream() << "    else" << std::endl;
fa.stream() << "        s << \'\\'data\\': \' << \'\\'<empty>\\'\';" << std::endl;
fa.stream() << "    s << \' }\';" << std::endl;
fa.stream() << "    return s;" << std::endl;
fa.stream() << "}" << std::endl;
fa.stream() << std::endl;
    }
fa.stream() << std::endl;
}
} } } }
