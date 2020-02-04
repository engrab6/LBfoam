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

/** \file
 * Helper functions for domain initialization -- header file.
 */
#ifndef NTENSOR_ANALYSIS_WRAPPER_3D_H
#define NTENSOR_ANALYSIS_WRAPPER_3D_H

#include "core/globalDefs.h"
#include "atomicBlock/dataField3D.h"
#include "multiBlock/multiDataField3D.h"
#include "dataProcessors/dataAnalysisFunctional3D.h"
#include <memory>


namespace plb {

template<typename T1, typename T2>
void copy( MultiNTensorField3D<T1>& field,
           MultiNTensorField3D<T2>& convertedField, Box3D domain );

template<typename T1, typename T2>
MultiNTensorField3D<T2>* copyConvert( MultiNTensorField3D<T1>& field,
                                      Box3D domain );

template<typename T>
void nTensorToScalar(MultiNTensorField3D<T>& nTensor, MultiScalarField3D<T>& scalar);

template<typename T>
void scalarToNTensor(MultiScalarField3D<T>& scalar, MultiNTensorField3D<T>& nTensor);

template<typename T>
std::unique_ptr<MultiNTensorField3D<T> > scalarToNTensor(MultiScalarField3D<T>& scalar);

template<typename T>
std::unique_ptr<MultiScalarField3D<T> > nTensorToScalar(MultiNTensorField3D<T>& nTensor);

}  // namespace plb

#endif  // NTENSOR_ANALYSIS_WRAPPER_3D_H

