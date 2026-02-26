// SPDX-FileCopyrightText: 2013 Jürgen Riegel <FreeCAD@juergen-riegel.net>
// SPDX-FileNotice: Part of the FreeCAD project.

/******************************************************************************
 *                                                                            *
 *   FreeCAD is free software: you can redistribute it and/or modify          *
 *   it under the terms of the GNU Lesser General Public License as           *
 *   published by the Free Software Foundation, either version 2.1            *
 *   of the License, or (at your option) any later version.                   *
 *                                                                            *
 *   FreeCAD is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty              *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 *   See the GNU Lesser General Public License for more details.              *
 *                                                                            *
 *   You should have received a copy of the GNU Lesser General Public         *
 *   License along with FreeCAD. If not, see https://www.gnu.org/licenses     *
 *                                                                            *
 ******************************************************************************/


#include "ViewProviderFemMeshShape.h"


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderFemMeshShapeBase, FemGui::ViewProviderFemMesh)

ViewProviderFemMeshShapeBase::ViewProviderFemMeshShapeBase() = default;

ViewProviderFemMeshShapeBase::~ViewProviderFemMeshShapeBase() = default;

// ------------------------------------------------------------------------

PROPERTY_SOURCE(FemGui::ViewProviderFemMeshShape, FemGui::ViewProviderFemMeshShapeBase)

ViewProviderFemMeshShape::ViewProviderFemMeshShape() = default;

ViewProviderFemMeshShape::~ViewProviderFemMeshShape() = default;


// Python feature ---------------------------------------------------------

namespace Gui
{

PROPERTY_SOURCE_TEMPLATE(FemGui::ViewProviderFemMeshShapeBasePython, FemGui::ViewProviderFemMeshShapeBase)

// explicit template instantiation
template class FemGuiExport ViewProviderFeaturePythonT<ViewProviderFemMeshShapeBase>;

}  // namespace Gui
