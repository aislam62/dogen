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
#include "dogen/test_models/database/hash/northwind/orders_hash.hpp"
#include "dogen/test_models/database/hash/northwind/order_id_hash.hpp"
#include "dogen/test_models/database/hash/northwind/customer_id_hash.hpp"
#include "dogen/test_models/database/hash/northwind/employee_id_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_boost_gregorian_date(const boost::gregorian::date& v) {
    std::size_t seed(0);
    combine(seed, v.modjulian_day());
    return seed;
}

}

namespace dogen {
namespace test_models {
namespace database {
namespace northwind {

std::size_t orders_hasher::hash(const orders& v) {
    std::size_t seed(0);

    combine(seed, v.order_id());
    combine(seed, v.customer_id());
    combine(seed, v.employee_id());
    combine(seed, hash_boost_gregorian_date(v.order_date()));
    combine(seed, hash_boost_gregorian_date(v.required_date()));
    combine(seed, hash_boost_gregorian_date(v.shipped_date()));
    combine(seed, v.ship_via());
    combine(seed, v.freight());
    combine(seed, v.ship_name());
    combine(seed, v.ship_address());
    combine(seed, v.ship_city());
    combine(seed, v.ship_region());
    combine(seed, v.ship_postal_code());
    combine(seed, v.ship_country());

    return seed;
}

} } } }
