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
#ifndef DOGEN_CPP_TYPES_FORMATTERS_CONTEXT_HPP
#define DOGEN_CPP_TYPES_FORMATTERS_CONTEXT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include <unordered_map>
#include "dogen/cpp/types/settings/bundle.hpp"
#include "dogen/cpp/types/formattables/formatter_properties.hpp"
#include "dogen/cpp/serialization/formatters/context_fwd_ser.hpp"

namespace dogen {
namespace cpp {
namespace formatters {

/**
 * @brief Supplies additional information required for formatting.
 */
class context final {
public:
    context() = default;
    context(const context&) = default;
    context(context&&) = default;
    ~context() = default;

public:
    context(
        const dogen::cpp::settings::bundle& bundle,
        const std::unordered_map<std::string, dogen::cpp::formattables::formatter_properties>& formatter_properties);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const context& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, context& v, unsigned int version);

public:
    const dogen::cpp::settings::bundle& bundle() const;
    dogen::cpp::settings::bundle& bundle();
    void bundle(const dogen::cpp::settings::bundle& v);
    void bundle(const dogen::cpp::settings::bundle&& v);

    const std::unordered_map<std::string, dogen::cpp::formattables::formatter_properties>& formatter_properties() const;
    std::unordered_map<std::string, dogen::cpp::formattables::formatter_properties>& formatter_properties();
    void formatter_properties(const std::unordered_map<std::string, dogen::cpp::formattables::formatter_properties>& v);
    void formatter_properties(const std::unordered_map<std::string, dogen::cpp::formattables::formatter_properties>&& v);

public:
    bool operator==(const context& rhs) const;
    bool operator!=(const context& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(context& other) noexcept;
    context& operator=(context other);

private:
    dogen::cpp::settings::bundle bundle_;
    std::unordered_map<std::string, dogen::cpp::formattables::formatter_properties> formatter_properties_;
};

} } }

namespace std {

template<>
inline void swap(
    dogen::cpp::formatters::context& lhs,
    dogen::cpp::formatters::context& rhs) {
    lhs.swap(rhs);
}

}

#endif
