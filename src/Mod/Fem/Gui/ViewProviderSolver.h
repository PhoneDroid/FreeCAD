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
#include <Mod/Fem/FemGlobal.h>


class SoCoordinate3;
class SoDrawStyle;
class SoIndexedFaceSet;
class SoIndexedLineSet;
class SoShapeHints;
class SoMaterialBinding;

namespace FemGui
{

class FemGuiExport ViewProviderSolver: public Gui::ViewProviderDocumentObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(FemGui::ViewProviderSolver);

public:
    /// constructor
    ViewProviderSolver();

    /// destructor
    ~ViewProviderSolver() override;

    // shows solid in the tree
    bool isShow() const override
    {
        return Visibility.getValue();
    }
    /// A list of all possible display modes
    std::vector<std::string> getDisplayModes() const override;

    // handling when object is deleted
    bool onDelete(const std::vector<std::string>&) override;
    bool canDelete(App::DocumentObject* obj) const override;
};

using ViewProviderSolverPython = Gui::ViewProviderFeaturePythonT<ViewProviderSolver>;

}  // namespace FemGui
