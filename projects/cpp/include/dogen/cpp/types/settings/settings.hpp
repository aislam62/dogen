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
#ifndef DOGEN_CPP_TYPES_SETTINGS_SETTINGS_HPP
#define DOGEN_CPP_TYPES_SETTINGS_SETTINGS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include <unordered_map>
#include "dogen/cpp/serialization/settings/settings_fwd_ser.hpp"
#include "dogen/cpp/types/settings/global_settings.hpp"
#include "dogen/cpp/types/settings/local_settings.hpp"

namespace dogen {
namespace cpp {
namespace settings {

class settings final {
public:
    settings() = default;
    settings(const settings&) = default;
    settings(settings&&) = default;
    ~settings() = default;

public:
    settings(
        const dogen::cpp::settings::global_settings& global_settings,
        const std::unordered_map<std::string, std::unordered_map<std::string, dogen::cpp::settings::local_settings> >& local_settings);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const settings& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, settings& v, unsigned int version);

public:
    const dogen::cpp::settings::global_settings& global_settings() const;
    dogen::cpp::settings::global_settings& global_settings();
    void global_settings(const dogen::cpp::settings::global_settings& v);
    void global_settings(const dogen::cpp::settings::global_settings&& v);

    const std::unordered_map<std::string, std::unordered_map<std::string, dogen::cpp::settings::local_settings> >& local_settings() const;
    std::unordered_map<std::string, std::unordered_map<std::string, dogen::cpp::settings::local_settings> >& local_settings();
    void local_settings(const std::unordered_map<std::string, std::unordered_map<std::string, dogen::cpp::settings::local_settings> >& v);
    void local_settings(const std::unordered_map<std::string, std::unordered_map<std::string, dogen::cpp::settings::local_settings> >&& v);

public:
    bool operator==(const settings& rhs) const;
    bool operator!=(const settings& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(settings& other) noexcept;
    settings& operator=(settings other);

private:
    dogen::cpp::settings::global_settings global_settings_;
    std::unordered_map<std::string, std::unordered_map<std::string, dogen::cpp::settings::local_settings> > local_settings_;
};

} } }

namespace std {

template<>
inline void swap(
    dogen::cpp::settings::settings& lhs,
    dogen::cpp::settings::settings& rhs) {
    lhs.swap(rhs);
}

}

#endif
