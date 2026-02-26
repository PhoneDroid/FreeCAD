// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2009 Jürgen Riegel <juergen.riegel@web.de>
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


#include "TaskWatcher.h"


using namespace RobotGui;

//**************************************************************************
//**************************************************************************
// TaskWatcher
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TaskWatcherRobot::TaskWatcherRobot()
    : Gui::TaskView::TaskWatcher("SELECT Robot::RobotObject COUNT 1")
{
    rob = new TaskRobot6Axis(nullptr);
    ctr = new TaskRobotControl(nullptr);

    Content.push_back(rob);
    Content.push_back(ctr);
}

//==== calls from the TaskView ===============================================================

bool TaskWatcherRobot::shouldShow()
{
    if (match()) {
        rob->setRobot((Robot::RobotObject*)Result[0][0].getObject());
        ctr->setRobot((Robot::RobotObject*)Result[0][0].getObject());
        return true;
    }
    return false;
}


#include "moc_TaskWatcher.cpp"
