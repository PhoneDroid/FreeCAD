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

#include <QApplication>


#include <Gui/Application.h>
#include <Gui/Document.h>
#include <Gui/TaskView/TaskSelectLinkProperty.h>

#include "TaskDlgTrajectoryCompound.h"


using namespace RobotGui;

//**************************************************************************
//**************************************************************************
// TaskDialog
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TaskDlgTrajectoryCompound::TaskDlgTrajectoryCompound(Robot::TrajectoryCompound* obj)
    : TaskDialog()
    , TrajectoryCompound(obj)
{
    select = new Gui::TaskView::TaskSelectLinkProperty(
        "SELECT Robot::TrajectoryObject COUNT 1..",
        &(obj->Source)
    );

    Content.push_back(select);
}

//==== calls from the TaskView ===============================================================


void TaskDlgTrajectoryCompound::open()
{
    select->activate();
}


bool TaskDlgTrajectoryCompound::accept()
{
    if (select->isSelectionValid()) {
        select->accept();
        TrajectoryCompound->execute();
        Gui::Document* doc = Gui::Application::Instance->activeDocument();
        if (doc) {
            doc->resetEdit();
        }
        return true;
    }
    else {
        QApplication::beep();
    }

    return false;
}

bool TaskDlgTrajectoryCompound::reject()
{
    select->reject();
    TrajectoryCompound->execute();
    Gui::Document* doc = Gui::Application::Instance->activeDocument();
    if (doc) {
        doc->resetEdit();
    }
    return true;
}

void TaskDlgTrajectoryCompound::helpRequested()
{}


#include "moc_TaskDlgTrajectoryCompound.cpp"
