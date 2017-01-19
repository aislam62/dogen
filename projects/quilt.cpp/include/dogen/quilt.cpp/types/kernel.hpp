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
#ifndef DOGEN_QUILT_CPP_TYPES_KERNEL_HPP
#define DOGEN_QUILT_CPP_TYPES_KERNEL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <vector>
#include <string>
#include <memory>
#include <forward_list>
#include <unordered_map>
#include <boost/filesystem/path.hpp>
#include "dogen/annotations/types/annotation.hpp"
#include "dogen/annotations/types/type_repository.hpp"
#include "dogen/annotations/types/annotation_groups_factory.hpp"
#include "dogen/yarn/types/model.hpp"
#include "dogen/quilt/types/kernel_interface.hpp"
#include "dogen/quilt.cpp/types/formatters/repository.hpp"
#include "dogen/quilt.cpp/types/formattables/model.hpp"

namespace dogen {
namespace quilt {
namespace cpp {

/**
 * @brief Manages the c++ kernel kernel.
 */
class kernel final : public quilt::kernel_interface {
public:
    kernel() = default;
    kernel(const kernel&) = delete;
    kernel(kernel&&) = default;

public:
    ~kernel() noexcept;

private:
    /**
     * @brief Create the formattables representation of the yarn model.
     */
    formattables::model create_formattables_model(
        const options::knitting_options& ko,
        const annotations::type_repository& atrp,
        const annotations::annotation& ra,
        const dogen::formatters::decoration_properties_factory& dpf,
        const formatters::repository& frp, const bool requires_kernel_directory,
        const yarn::model& m) const;

    /**
     * @brief Create the files representation of the formattables model.
     */
    std::forward_list<dogen::formatters::artefact>
    format(const annotations::type_repository& atrp,
        const annotations::annotation_groups_factory& agf,
        const dogen::formatters::repository& drp,
        const formattables::model& fm) const;

public:
    std::string id() const override;

    std::forward_list<boost::filesystem::path>
    managed_directories(const options::knitting_options& ko,
        const yarn::name& model_name) const override;

    annotations::archetype_location archetype_location() const override;

    std::forward_list<annotations::archetype_location>
    archetype_locations() const override;

    yarn::languages language() const override;

    std::forward_list<dogen::formatters::artefact> generate(
        const options::knitting_options& ko,
        const annotations::type_repository& atrp,
        const annotations::annotation_groups_factory& agf,
        const dogen::formatters::repository& drp,
        const dogen::formatters::decoration_properties_factory& dpf,
        const bool enable_kernel_directories,
        const yarn::model& m) const override;
};

} } }

#endif