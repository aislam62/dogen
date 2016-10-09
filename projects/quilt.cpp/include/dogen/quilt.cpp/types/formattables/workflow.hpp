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
#ifndef DOGEN_QUILT_CPP_TYPES_FORMATTABLES_WORKFLOW_HPP
#define DOGEN_QUILT_CPP_TYPES_FORMATTABLES_WORKFLOW_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <memory>
#include <utility>
#include <unordered_map>
#include "dogen/dynamic/types/object.hpp"
#include "dogen/dynamic/types/repository.hpp"
#include "dogen/options/types/cpp_options.hpp"
#include "dogen/formatters/types/decoration_configuration_factory.hpp"
#include "dogen/yarn/types/model.hpp"
#include "dogen/quilt.cpp/types/annotations/path_annotations.hpp"
#include "dogen/quilt.cpp/types/formatters/container.hpp"
#include "dogen/quilt.cpp/types/formattables/model.hpp"
#include "dogen/quilt.cpp/types/formattables/formattable.hpp"
#include "dogen/quilt.cpp/types/formattables/locator.hpp"
#include "dogen/quilt.cpp/types/formattables/model.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace formattables {

class workflow {
private:
    typedef std::unordered_map<std::string, annotations::path_annotations>
    path_annotations_type;

    path_annotations_type make_path_annotations(const dynamic::repository& drp,
        const dynamic::object& root_object,
        const formatters::container& fc) const;

    model
    make_model(const formatters::container& fc, const yarn::model& m) const;

    void expand_model(
        const std::forward_list<boost::filesystem::path>& data_directories,
        const dynamic::repository& drp, const dynamic::object& root_object,
        const dogen::formatters::decoration_configuration_factory& dcf,
        const path_annotations_type& pa, const formatters::container& fc,
        const locator& l, model& fm) const;

public:
    model execute(
        const std::forward_list<boost::filesystem::path>& data_directories,
        const options::cpp_options& opts,
        const dynamic::repository& drp, const dynamic::object& root_object,
        const dogen::formatters::decoration_configuration_factory& dcf,
        const formatters::container& fc, const yarn::model& m) const;
};

} } } }

#endif
