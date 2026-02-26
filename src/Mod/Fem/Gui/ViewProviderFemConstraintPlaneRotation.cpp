// SPDX-FileCopyrightText: 2015 FreeCAD Developers
// SPDX-FileCopyrightText: Michael Hindley <hindlemp@eskom.co.za>
// SPDX-FileCopyrightText: Ruan Olwagen <olwager@eskom.co.za>
// SPDX-FileCopyrightText: Oswald van Ginkel <vginkeo@eskom.co.za>
// SPDX-FileNotice: Part of the FreeCAD project.

// Based on Force constraint by Jan Rheinländer

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

#include "Mod/Fem/App/FemConstraintPlaneRotation.h"
#include <Gui/Control.h>

#include "TaskFemConstraintPlaneRotation.h"
#include "ViewProviderFemConstraintPlaneRotation.h"


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderFemConstraintPlaneRotation, FemGui::ViewProviderFemConstraint)

ViewProviderFemConstraintPlaneRotation::ViewProviderFemConstraintPlaneRotation()
{
    sPixmap = "FEM_ConstraintPlaneRotation";
    loadSymbol((resourceSymbolDir + "ConstraintPlaneRotation.iv").c_str());
    // Note change "planerotation" in line above to new constraint name, make sure it is the same as
    // in taskFem* cpp file
    ShapeAppearance.setDiffuseColor(0.2f, 0.3f, 0.2f);
}

ViewProviderFemConstraintPlaneRotation::~ViewProviderFemConstraintPlaneRotation() = default;

bool ViewProviderFemConstraintPlaneRotation::setEdit(int ModNum)
{
    if (ModNum == ViewProvider::Default) {
        Gui::Control().closeDialog();
        // clear the selection (convenience)
        Gui::Selection().clearSelection();
        Gui::Control().showDialog(new TaskDlgFemConstraintPlaneRotation(this));

        return true;
    }
    else {
        return ViewProviderFemConstraint::setEdit(ModNum);
    }
}

void ViewProviderFemConstraintPlaneRotation::updateData(const App::Property* prop)
{
    ViewProviderFemConstraint::updateData(prop);
}
