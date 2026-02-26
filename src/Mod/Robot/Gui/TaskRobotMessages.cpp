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


#include <Gui/BitmapFactory.h>

#include "TaskRobotMessages.h"
#include "ui_TaskRobotMessages.h"


using namespace RobotGui;
using namespace Gui;

TaskRobotMessages::TaskRobotMessages(Robot::RobotObject* pcRobotObject, QWidget* parent)
    : TaskBox(Gui::BitmapFactory().pixmap("document-new"), tr("TaskRobotMessages"), true, parent)
    , pcRobot(pcRobotObject)
{
    // we need a separate container widget to add all controls to
    proxy = new QWidget(this);
    ui = new Ui_TaskRobotMessages();
    ui->setupUi(proxy);
    QMetaObject::connectSlotsByName(this);

    this->groupLayout()->addWidget(proxy);
}

TaskRobotMessages::~TaskRobotMessages()
{
    delete ui;
}


#include "moc_TaskRobotMessages.cpp"
