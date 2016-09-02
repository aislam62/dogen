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
#include "dogen/utility/log/logger.hpp"
#include "dogen/yarn/io/model_io.hpp"
#include "dogen/yarn/types/frontend_workflow.hpp"
#include "dogen/yarn/types/expander.hpp"
#include "dogen/yarn/types/assembler.hpp"
#include "dogen/yarn/types/transformer.hpp"
#include "dogen/yarn/types/descriptor_factory.hpp"
#include "dogen/yarn/types/workflow.hpp"

namespace {

using namespace dogen::utility::log;
static logger lg(logger_factory("yarn.workflow"));

}

namespace dogen {
namespace yarn {

std::list<descriptor> workflow::obtain_descriptors_activity(
    const std::list<boost::filesystem::path>& dirs,
    const config::input_options& io) const {

    descriptor_factory f;
    return f.make(dirs, io);
}

std::list<intermediate_model> workflow::obtain_intermediate_models_activity(
    const dynamic::repository& drp, const std::list<descriptor>& d) const {
    frontend_workflow w(drp);
    return w.execute(d);
}

void workflow::expand_intermediate_models_activity(
    const dynamic::repository& drp,
    std::list<intermediate_model>& m) const {
    expander e(drp);
    for (auto& model : m)
        e.expand(model);
}

intermediate_model workflow::assemble_intermediate_models_activity(
    const std::list<intermediate_model>& m) const {
    assembler a;
    return a.assemble(m);
}

model workflow::transform_intermediate_model_activity(
    const intermediate_model& m) const {
    transformer t;
    return t.transform(m);
}

model workflow::execute(const dynamic::repository& drp,
    const std::list<boost::filesystem::path>& dirs,
    const config::input_options& io) const {

    const auto d(obtain_descriptors_activity(dirs, io));
    auto im(obtain_intermediate_models_activity(drp, d));
    expand_intermediate_models_activity(drp, im);
    const auto m(assemble_intermediate_models_activity(im));
    const auto r(transform_intermediate_model_activity(m));

    BOOST_LOG_SEV(lg, debug) << "Final model: " << r;
    return r;
}

} }
