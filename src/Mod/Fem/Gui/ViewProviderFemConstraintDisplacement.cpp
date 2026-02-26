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


#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSwitch.h>


#include "Mod/Fem/App/FemConstraintDisplacement.h"
#include "TaskFemConstraintDisplacement.h"
#include "ViewProviderFemConstraintDisplacement.h"
#include <Gui/Control.h>


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderFemConstraintDisplacement, FemGui::ViewProviderFemConstraintOnBoundary)

ViewProviderFemConstraintDisplacement::ViewProviderFemConstraintDisplacement()
{
    sPixmap = "FEM_ConstraintDisplacement";
    loadSymbol((resourceSymbolDir + "ConstraintDisplacement.iv").c_str());
    ShapeAppearance.setDiffuseColor(0.2f, 0.3f, 0.2f);

    // do not rotate symbol according to boundary normal
    setRotateSymbol(false);
}

ViewProviderFemConstraintDisplacement::~ViewProviderFemConstraintDisplacement() = default;

bool ViewProviderFemConstraintDisplacement::setEdit(int ModNum)
{
    if (ModNum == ViewProvider::Default) {
        Gui::Control().closeDialog();
        // clear the selection (convenience)
        Gui::Selection().clearSelection();
        Gui::Control().showDialog(new TaskDlgFemConstraintDisplacement(this));

        return true;
    }
    else {
        return ViewProviderFemConstraintOnBoundary::setEdit(ModNum);
    }
}

void ViewProviderFemConstraintDisplacement::updateData(const App::Property* prop)
{
    Fem::ConstraintDisplacement* pcConstraint = this->getObject<Fem::ConstraintDisplacement>();

    if (prop == &pcConstraint->xFree) {
        auto sw = static_cast<SoSwitch*>(getSymbolSeparator()->getChild(0));
        sw->whichChild.setValue((pcConstraint->xFree.getValue() ? -1 : 0));
    }
    else if (prop == &pcConstraint->yFree) {
        auto sw = static_cast<SoSwitch*>(getSymbolSeparator()->getChild(1));
        sw->whichChild.setValue((pcConstraint->yFree.getValue() ? -1 : 0));
    }
    else if (prop == &pcConstraint->zFree) {
        auto sw = static_cast<SoSwitch*>(getSymbolSeparator()->getChild(2));
        sw->whichChild.setValue((pcConstraint->zFree.getValue() ? -1 : 0));
    }
    else if (prop == &pcConstraint->rotxFree) {
        auto sw = static_cast<SoSwitch*>(getSymbolSeparator()->getChild(3));
        sw->whichChild.setValue((pcConstraint->rotxFree.getValue() ? -1 : 0));
    }
    else if (prop == &pcConstraint->rotyFree) {
        auto sw = static_cast<SoSwitch*>(getSymbolSeparator()->getChild(4));
        sw->whichChild.setValue((pcConstraint->rotyFree.getValue() ? -1 : 0));
    }
    else if (prop == &pcConstraint->rotzFree) {
        auto sw = static_cast<SoSwitch*>(getSymbolSeparator()->getChild(5));
        sw->whichChild.setValue((pcConstraint->rotzFree.getValue() ? -1 : 0));
    }
    else {
        ViewProviderFemConstraint::updateData(prop);
    }
}
