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

#pragma once

#include <Gui/TaskView/TaskView.h>
#include <Mod/Robot/App/TrajectoryDressUpObject.h>


namespace RobotGui
{

class Ui_TaskTrajectoryDressUpParameter;
class TaskTrajectoryDressUpParameter: public Gui::TaskView::TaskBox
{
    Q_OBJECT

public:
    explicit TaskTrajectoryDressUpParameter(
        Robot::TrajectoryDressUpObject* obj,
        QWidget* parent = nullptr
    );
    ~TaskTrajectoryDressUpParameter() override;

    /// this methode write the values from the Gui to the object, usually in accept()
    void writeValues();

private Q_SLOTS:
    /// edit the placement
    void createPlacementDlg();


protected:
    Base::Placement PosAdd;

    void viewPlacement();

private:
    QWidget* proxy;
    Ui_TaskTrajectoryDressUpParameter* ui;
    Robot::TrajectoryDressUpObject* pcObject;
};

}  // namespace RobotGui
