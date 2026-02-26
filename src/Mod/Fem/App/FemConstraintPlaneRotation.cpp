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


#include "FemConstraintPlaneRotation.h"


using namespace Fem;

PROPERTY_SOURCE(Fem::ConstraintPlaneRotation, Fem::Constraint)

ConstraintPlaneRotation::ConstraintPlaneRotation()
{}

App::DocumentObjectExecReturn* ConstraintPlaneRotation::execute()
{
    return Constraint::execute();
}

const char* ConstraintPlaneRotation::getViewProviderName() const
{
    return "FemGui::ViewProviderFemConstraintPlaneRotation";
}

void ConstraintPlaneRotation::onChanged(const App::Property* prop)
{
    Constraint::onChanged(prop);
}
