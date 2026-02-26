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
#include <Mod/Robot/App/Edge2TracObject.h>


namespace App
{
class Property;
}

namespace Gui
{
class ViewProvider;
}

namespace RobotGui
{

class Ui_TaskEdge2TracParameter;
class TaskEdge2TracParameter: public Gui::TaskView::TaskBox
{
    Q_OBJECT

public:
    explicit TaskEdge2TracParameter(Robot::Edge2TracObject* pcObject, QWidget* parent = nullptr);
    ~TaskEdge2TracParameter() override;

    void setEdgeAndClusterNbr(int NbrEdges, int NbrClusters);

private Q_SLOTS:
    void hideShow();
    void sizingValueChanged(double Value);
    void orientationToggled(bool Value);

protected:
    Robot::Edge2TracObject* pcObject;
    App::DocumentObject* HideShowObj;

    void setHideShowObject();

private:
private:
    QWidget* proxy;
    Ui_TaskEdge2TracParameter* ui;
};

}  // namespace RobotGui
