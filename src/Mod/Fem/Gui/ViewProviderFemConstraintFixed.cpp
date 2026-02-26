// SPDX-FileCopyrightText: 2013 Jan Rheinländer <jrheinlaender@users.sourceforge.net>
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

#include "Gui/Control.h"
#include <Mod/Fem/App/FemConstraintFixed.h>

#include "TaskFemConstraintFixed.h"
#include "ViewProviderFemConstraintFixed.h"


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderFemConstraintFixed, FemGui::ViewProviderFemConstraintOnBoundary)


ViewProviderFemConstraintFixed::ViewProviderFemConstraintFixed()
{
    sPixmap = "FEM_ConstraintFixed";
    loadSymbol((resourceSymbolDir + "ConstraintFixed.iv").c_str());
}

ViewProviderFemConstraintFixed::~ViewProviderFemConstraintFixed() = default;

bool ViewProviderFemConstraintFixed::setEdit(int ModNum)
{
    if (ModNum == ViewProvider::Default) {
        Gui::Control().closeDialog();
        // clear the selection (convenience)
        Gui::Selection().clearSelection();
        Gui::Control().showDialog(new TaskDlgFemConstraintFixed(this));

        return true;
    }
    else {
        return ViewProviderFemConstraintOnBoundary::setEdit(ModNum);
    }
}

void ViewProviderFemConstraintFixed::updateData(const App::Property* prop)
{
    ViewProviderFemConstraint::updateData(prop);
}
