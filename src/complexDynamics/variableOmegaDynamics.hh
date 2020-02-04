/* This file is part of the Palabos library.
 *
 * Copyright (C) 2011-2017 FlowKit Sarl
 * Route d'Oron 2
 * 1010 Lausanne, Switzerland
 * E-mail contact: contact@flowkit.com
 *
 * The most recent release of Palabos can be downloaded at 
 * <http://www.palabos.org/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Orestis Malaspinas designed some of the classes and concepts contained
 * in this file. */

#ifndef VARIABLE_OMEGA_DYNAMICS_HH
#define VARIABLE_OMEGA_DYNAMICS_HH

#include "complexDynamics/variableOmegaDynamics.h"
#include "latticeBoltzmann/momentTemplates.h"

namespace plb {

template<typename T, template<typename U> class Descriptor>
VariableOmegaDynamics<T,Descriptor>::VariableOmegaDynamics (
        Dynamics<T,Descriptor>* baseDynamics_, bool automaticPrepareCollision_ )
    : CompositeDynamics<T,Descriptor>(baseDynamics_, automaticPrepareCollision_)
{ }

template<typename T, template<typename U> class Descriptor>
void VariableOmegaDynamics<T,Descriptor>::prepareCollision(Cell<T,Descriptor>& cell) {
    // Remember: it's the baseDynamics that holds omega=omega0+deltaOmega.
    // The value of this->getOmega() is omega0, and this should not be modified here.
    this->getBaseDynamics().setOmega(getOmegaFromCell(cell));
}

template<typename T, template<typename U> class Descriptor>
OmegaFromPiDynamics<T,Descriptor>::OmegaFromPiDynamics(Dynamics<T,Descriptor>* baseDynamics_, bool automaticPrepareCollision_)
    : VariableOmegaDynamics<T,Descriptor>(baseDynamics_, automaticPrepareCollision_)
{ }

template<typename T, template<typename U> class Descriptor>
T OmegaFromPiDynamics<T,Descriptor>::getOmegaFromCell(Cell<T,Descriptor> const& cell) const {
    Dynamics<T,Descriptor> const& dynamics=cell.getDynamics();

    T rhoBar;
    Array<T,Descriptor<T>::d> j;
    Array<T,SymmetricTensor<T,Descriptor>::n> PiNeq;
    dynamics.computeRhoBarJPiNeq(cell, rhoBar, j, PiNeq);
    return getOmegaFromPiAndRhoBar(PiNeq, rhoBar);
}

} // namespace plb

#endif  // VARIABLE_OMEGA_DYNAMICS_HH
