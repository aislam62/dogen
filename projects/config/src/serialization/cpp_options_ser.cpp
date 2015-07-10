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
#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "dogen/utility/serialization/path.hpp"
#include "dogen/config/serialization/cpp_options_ser.hpp"

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const dogen::config::cpp_options& v,
    const unsigned int /*version*/) {
    ar << make_nvp("split_project", v.split_project_);
    ar << make_nvp("project_directory_path", v.project_directory_path_.generic_string());
    ar << make_nvp("source_directory_path", v.source_directory_path_.generic_string());
    ar << make_nvp("include_directory_path", v.include_directory_path_.generic_string());
    ar << make_nvp("disable_cmakelists", v.disable_cmakelists_);
}

template<typename Archive>
void load(Archive& ar,
    dogen::config::cpp_options& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("split_project", v.split_project_);
    std::string project_directory_path_tmp;
    ar >> make_nvp("project_directory_path", project_directory_path_tmp);
    v.project_directory_path_ = project_directory_path_tmp;
    std::string source_directory_path_tmp;
    ar >> make_nvp("source_directory_path", source_directory_path_tmp);
    v.source_directory_path_ = source_directory_path_tmp;
    std::string include_directory_path_tmp;
    ar >> make_nvp("include_directory_path", include_directory_path_tmp);
    v.include_directory_path_ = include_directory_path_tmp;
    ar >> make_nvp("disable_cmakelists", v.disable_cmakelists_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const dogen::config::cpp_options& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, dogen::config::cpp_options& v, unsigned int version);

template void save(archive::text_oarchive& ar, const dogen::config::cpp_options& v, unsigned int version);
template void load(archive::text_iarchive& ar, dogen::config::cpp_options& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const dogen::config::cpp_options& v, unsigned int version);
template void load(archive::binary_iarchive& ar, dogen::config::cpp_options& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const dogen::config::cpp_options& v, unsigned int version);
template void load(archive::xml_iarchive& ar, dogen::config::cpp_options& v, unsigned int version);

} }
