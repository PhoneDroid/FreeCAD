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

#include <QDialog>
#include <memory>

#include <Mod/Robot/App/RobotObject.h>
#include <Mod/Robot/App/Simulation.h>
#include <Mod/Robot/App/TrajectoryObject.h>

#include "ViewProviderRobotObject.h"


namespace RobotGui
{

class Ui_DlgTrajectorySimulate;

class TrajectorySimulate: public QDialog
{
    Q_OBJECT

public:
    TrajectorySimulate(
        Robot::RobotObject* pcRobotObject,
        Robot::TrajectoryObject* pcTrajectoryObject,
        QWidget* parent = nullptr
    );
    ~TrajectorySimulate() override;

private Q_SLOTS:
    void start();
    void stop();
    void run();
    void back();
    void forward();
    void end();

    void timerDone();
    void valueChanged(int value);
    void valueChanged(double d);

protected:
    void setTo();

    QTimer* timer;

    Robot::Simulation sim;

    ViewProviderRobotObject* ViewProv;

    bool Run;
    bool block;

    float timePos;
    float duration;

private:
    std::unique_ptr<Ui_DlgTrajectorySimulate> ui;
};

}  // namespace RobotGui
