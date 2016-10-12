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
#include <boost/throw_exception.hpp>
#include "dogen/utility/log/logger.hpp"
#include "dogen/utility/io/list_io.hpp"
#include "dogen/utility/io/forward_list_io.hpp"
#include "dogen/utility/io/unordered_map_io.hpp"
#include "dogen/utility/filesystem/file.hpp"
#include "dogen/annotations/io/profile_io.hpp"
#include "dogen/annotations/types/profile_hydrator.hpp"
#include "dogen/annotations/types/profiler.hpp"

using namespace dogen::utility::log;

namespace {

auto lg(logger_factory("annotations.profiler"));

const std::string profile_dir("profiles_v2");

}

namespace dogen {
namespace annotations {

std::forward_list<boost::filesystem::path> profiler::create_directory_list(
    const std::forward_list<boost::filesystem::path>& data_directories) const {
    std::forward_list<boost::filesystem::path> r;
    for (const auto& d : data_directories)
        r.push_front(d / profile_dir);
    return r;
}

std::list<profile>
profiler::hydrate_profiles(const std::forward_list<boost::filesystem::path>&
    data_directories) const {
    BOOST_LOG_SEV(lg, debug) << "Hydrating profile groups.";

    const auto dl(create_directory_list(data_directories));
    BOOST_LOG_SEV(lg, debug) << "Directory list: " << dl;

    std::list<profile> r;
    profile_hydrator h;
    const auto files(dogen::utility::filesystem::find_files(dl));
    for (const auto& f : files) {
        BOOST_LOG_SEV(lg, debug) << "Hydrating file: " << f.generic_string();
        r.push_back(h.hydrate(f));
    }

    BOOST_LOG_SEV(lg, debug) << "Hydrated profiles. Found: " << r.size();
    BOOST_LOG_SEV(lg, debug) << "Profiles: " << r;
    return r;
}

std::unordered_map<std::string, profiler::prof_ann> profiler::
create_prof_ann_map(const std::list<profile>& /*profiles*/) const {
    std::unordered_map<std::string, profiler::prof_ann> r;
    return r;
}

void profiler::validate_profiles(
    const std::forward_list<ownership_hierarchy>& /*ohs*/,
    const std::unordered_map<std::string, prof_ann>& /*pa*/) const {
}

void profiler::instantiate_value_templates(
    std::unordered_map<std::string, prof_ann>& /*pa*/) const {

}

void profiler::walk_up_parent_tree_and_merge(const std::string& /*current*/,
    std::unordered_map<std::string, prof_ann>& /*pa*/) const {
}

void profiler::merge(std::unordered_map<std::string, prof_ann>& /*pa*/) const {

}

std::unordered_map<std::string, profiler::prof_ann>
profiler::create_annotation_map(
    const std::unordered_map<std::string, prof_ann>& /*pa*/) const {
    std::unordered_map<std::string, profiler::prof_ann> r;
    return r;
}

std::unordered_map<std::string, annotation>
profiler::generate(const std::forward_list<ownership_hierarchy>& /*ohs*/,
    const std::forward_list<boost::filesystem::path>&
    data_directories) const {

    const auto profiles(hydrate_profiles(data_directories));
    std::unordered_map<std::string, annotation> r;
    return r;
}

} }
