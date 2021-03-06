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
#include "dogen/upsilon/types/schema_ref.hpp"

namespace dogen {
namespace upsilon {

schema_ref::schema_ref(
    const std::string& name,
    const std::string& file)
    : name_(name),
      file_(file) { }

void schema_ref::swap(schema_ref& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(file_, other.file_);
}

bool schema_ref::operator==(const schema_ref& rhs) const {
    return name_ == rhs.name_ &&
        file_ == rhs.file_;
}

schema_ref& schema_ref::operator=(schema_ref other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::string& schema_ref::name() const {
    return name_;
}

std::string& schema_ref::name() {
    return name_;
}

void schema_ref::name(const std::string& v) {
    name_ = v;
}

void schema_ref::name(const std::string&& v) {
    name_ = std::move(v);
}

const std::string& schema_ref::file() const {
    return file_;
}

std::string& schema_ref::file() {
    return file_;
}

void schema_ref::file(const std::string& v) {
    file_ = v;
}

void schema_ref::file(const std::string&& v) {
    file_ = std::move(v);
}

} }
