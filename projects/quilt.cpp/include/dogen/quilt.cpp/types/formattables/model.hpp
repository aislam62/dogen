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
#ifndef DOGEN_QUILT_CPP_TYPES_FORMATTABLES_MODEL_HPP
#define DOGEN_QUILT_CPP_TYPES_FORMATTABLES_MODEL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include <unordered_map>
#include "dogen/quilt.cpp/types/formattables/formattable.hpp"
#include "dogen/quilt.cpp/types/formattables/profile_group.hpp"
#include "dogen/quilt.cpp/types/formattables/facet_configuration.hpp"
#include "dogen/quilt.cpp/serialization/formattables/model_fwd_ser.hpp"
#include "dogen/quilt.cpp/types/formattables/streaming_configuration.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace formattables {

class model final {
public:
    model() = default;
    model(const model&) = default;
    model(model&&) = default;
    ~model() = default;

public:
    model(
        const std::unordered_map<std::string, dogen::quilt::cpp::formattables::streaming_configuration>& streaming_configurations,
        const std::unordered_map<std::string, dogen::quilt::cpp::formattables::formattable>& formattables,
        const std::unordered_map<std::string, dogen::quilt::cpp::formattables::facet_configuration>& facet_configurations,
        const dogen::quilt::cpp::formattables::profile_group& global_profile_group);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const dogen::quilt::cpp::formattables::model& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, dogen::quilt::cpp::formattables::model& v, unsigned int version);

public:
    const std::unordered_map<std::string, dogen::quilt::cpp::formattables::streaming_configuration>& streaming_configurations() const;
    std::unordered_map<std::string, dogen::quilt::cpp::formattables::streaming_configuration>& streaming_configurations();
    void streaming_configurations(const std::unordered_map<std::string, dogen::quilt::cpp::formattables::streaming_configuration>& v);
    void streaming_configurations(const std::unordered_map<std::string, dogen::quilt::cpp::formattables::streaming_configuration>&& v);

    const std::unordered_map<std::string, dogen::quilt::cpp::formattables::formattable>& formattables() const;
    std::unordered_map<std::string, dogen::quilt::cpp::formattables::formattable>& formattables();
    void formattables(const std::unordered_map<std::string, dogen::quilt::cpp::formattables::formattable>& v);
    void formattables(const std::unordered_map<std::string, dogen::quilt::cpp::formattables::formattable>&& v);

    const std::unordered_map<std::string, dogen::quilt::cpp::formattables::facet_configuration>& facet_configurations() const;
    std::unordered_map<std::string, dogen::quilt::cpp::formattables::facet_configuration>& facet_configurations();
    void facet_configurations(const std::unordered_map<std::string, dogen::quilt::cpp::formattables::facet_configuration>& v);
    void facet_configurations(const std::unordered_map<std::string, dogen::quilt::cpp::formattables::facet_configuration>&& v);

    const dogen::quilt::cpp::formattables::profile_group& global_profile_group() const;
    dogen::quilt::cpp::formattables::profile_group& global_profile_group();
    void global_profile_group(const dogen::quilt::cpp::formattables::profile_group& v);
    void global_profile_group(const dogen::quilt::cpp::formattables::profile_group&& v);

public:
    bool operator==(const model& rhs) const;
    bool operator!=(const model& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(model& other) noexcept;
    model& operator=(model other);

private:
    std::unordered_map<std::string, dogen::quilt::cpp::formattables::streaming_configuration> streaming_configurations_;
    std::unordered_map<std::string, dogen::quilt::cpp::formattables::formattable> formattables_;
    std::unordered_map<std::string, dogen::quilt::cpp::formattables::facet_configuration> facet_configurations_;
    dogen::quilt::cpp::formattables::profile_group global_profile_group_;
};

} } } }

namespace std {

template<>
inline void swap(
    dogen::quilt::cpp::formattables::model& lhs,
    dogen::quilt::cpp::formattables::model& rhs) {
    lhs.swap(rhs);
}

}

#endif
