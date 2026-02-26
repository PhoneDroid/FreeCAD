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

#include "Mod/Fem/App/FemConstraintTemperature.h"
#include "TaskFemConstraintTemperature.h"
#include "ViewProviderFemConstraintTemperature.h"
#include <Gui/Control.h>


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderFemConstraintTemperature, FemGui::ViewProviderFemConstraintOnBoundary)

ViewProviderFemConstraintTemperature::ViewProviderFemConstraintTemperature()
{
    sPixmap = "FEM_ConstraintTemperature";
    loadSymbol((resourceSymbolDir + "ConstraintTemperature.iv").c_str());
    ShapeAppearance.setDiffuseColor(1.0f, 0.0f, 0.0f);
}

ViewProviderFemConstraintTemperature::~ViewProviderFemConstraintTemperature() = default;

bool ViewProviderFemConstraintTemperature::setEdit(int ModNum)
{
    if (ModNum == ViewProvider::Default) {
        Gui::Control().closeDialog();
        // clear the selection (convenience)
        Gui::Selection().clearSelection();
        Gui::Control().showDialog(new TaskDlgFemConstraintTemperature(this));

        return true;
    }
    else {
        return ViewProviderFemConstraintOnBoundary::setEdit(ModNum);
    }
}

void ViewProviderFemConstraintTemperature::updateData(const App::Property* prop)
{
    ViewProviderFemConstraint::updateData(prop);
}
