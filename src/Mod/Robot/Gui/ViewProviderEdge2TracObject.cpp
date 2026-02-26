// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2008 Jürgen Riegel <juergen.riegel@web.de>
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


#include <Gui/Control.h>
#include <Mod/Robot/Gui/TaskDlgEdge2Trac.h>

#include "ViewProviderEdge2TracObject.h"


using namespace Gui;
using namespace RobotGui;

PROPERTY_SOURCE(RobotGui::ViewProviderEdge2TracObject, RobotGui::ViewProviderTrajectory)

bool ViewProviderEdge2TracObject::doubleClicked()
{
    Gui::TaskView::TaskDialog* dlg = new TaskDlgEdge2Trac(getObject<Robot::Edge2TracObject>());
    Gui::Control().showDialog(dlg);
    return true;
}


bool ViewProviderEdge2TracObject::setEdit(int)
{
    Gui::TaskView::TaskDialog* dlg = new TaskDlgEdge2Trac(getObject<Robot::Edge2TracObject>());
    Gui::Control().showDialog(dlg);
    return true;
}

void ViewProviderEdge2TracObject::unsetEdit(int)
{}
