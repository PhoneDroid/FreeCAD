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
#include <Mod/Robot/Gui/TaskDlgTrajectoryDressUp.h>

#include "ViewProviderTrajectoryDressUp.h"


using namespace Gui;
using namespace RobotGui;

PROPERTY_SOURCE(RobotGui::ViewProviderTrajectoryDressUp, RobotGui::ViewProviderTrajectory)

// bool ViewProviderTrajectoryDressUp::doubleClicked(void)
//{
//     Gui::TaskView::TaskDialog* dlg = new
//     TaskDlgTrajectoryDressUp(getObject<Robot::TrajectoryDressUpObject >());
//     Gui::Control().showDialog(dlg);
//     return true;
// }
//

bool ViewProviderTrajectoryDressUp::setEdit(int)
{
    Gui::TaskView::TaskDialog* dlg = new TaskDlgTrajectoryDressUp(
        getObject<Robot::TrajectoryDressUpObject>()
    );
    Gui::Control().showDialog(dlg);
    return true;
}

void ViewProviderTrajectoryDressUp::unsetEdit(int)
{
    // when pressing ESC make sure to close the dialog
    Gui::Control().closeDialog();
}

std::vector<App::DocumentObject*> ViewProviderTrajectoryDressUp::claimChildren() const
{
    std::vector<App::DocumentObject*> temp;
    temp.push_back(getObject<Robot::TrajectoryDressUpObject>()->Source.getValue());

    return temp;
}
