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
#include <Mod/Robot/App/TrajectoryCompound.h>
#include <Mod/Robot/Gui/TaskDlgTrajectoryCompound.h>

#include "ViewProviderTrajectoryCompound.h"


using namespace Gui;
using namespace RobotGui;

PROPERTY_SOURCE(RobotGui::ViewProviderTrajectoryCompound, RobotGui::ViewProviderTrajectory)

// bool ViewProviderTrajectoryCompound::doubleClicked(void)
//{
//     Gui::TaskView::TaskDialog* dlg = new
//     TaskDlgTrajectoryCompound(getObject<Robot::TrajectoryCompound >());
//     Gui::Control().showDialog(dlg);
//     return true;
// }


bool ViewProviderTrajectoryCompound::setEdit(int)
{
    Gui::TaskView::TaskDialog* dlg = new TaskDlgTrajectoryCompound(
        getObject<Robot::TrajectoryCompound>()
    );
    Gui::Control().showDialog(dlg);
    return true;
}

void ViewProviderTrajectoryCompound::unsetEdit(int)
{
    // when pressing ESC make sure to close the dialog
    Gui::Control().closeDialog();
}

std::vector<App::DocumentObject*> ViewProviderTrajectoryCompound::claimChildren() const
{
    return getObject<Robot::TrajectoryCompound>()->Source.getValues();
}
