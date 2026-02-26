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


#pragma once

#include <Gui/ViewProviderFeaturePython.h>

#include "ViewProviderFemMesh.h"


namespace FemGui
{

class FemGuiExport ViewProviderFemMeshShapeBase: public ViewProviderFemMesh
{
    PROPERTY_HEADER_WITH_OVERRIDE(FemGui::ViewProviderFemMeshShapeBase);

public:
    /// constructor.
    ViewProviderFemMeshShapeBase();

    /// destructor.
    ~ViewProviderFemMeshShapeBase() override;
};


class FemGuiExport ViewProviderFemMeshShape: public ViewProviderFemMeshShapeBase
{
    PROPERTY_HEADER_WITH_OVERRIDE(FemGui::ViewProviderFemMeshShape);

public:
    /// constructor.
    ViewProviderFemMeshShape();

    /// destructor.
    ~ViewProviderFemMeshShape() override;
};

using ViewProviderFemMeshShapeBasePython
    = Gui::ViewProviderFeaturePythonT<ViewProviderFemMeshShapeBase>;

}  // namespace FemGui
