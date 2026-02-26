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

#include <Base/Placement.h>

#include <Mod/Robot/RobotGlobal.h>

#include "Robot6Axis.h"
#include "Trajectory.h"


namespace Robot
{

/** Algo class for projecting shapes and creating SVG output of it
 */
class RobotExport Simulation
{

public:
    /// Constructor
    Simulation(const Trajectory& Trac, Robot6Axis& Rob);
    virtual ~Simulation();

    double getLength()
    {
        return Trac.getLength();
    }
    double getDuration()
    {
        return Trac.getDuration();
    }

    Base::Placement getPosition()
    {
        return Trac.getPosition(Pos);
    }
    double getVelocity()
    {
        return Trac.getVelocity(Pos);
    }

    void step(double tick);
    void setToWaypoint(unsigned int n);
    void setToTime(float t);
    // apply the start axis angles and set to time 0. Restores the exact start position
    void reset();

    double Pos {0.0};
    double Axis[6] {};
    double startAxis[6] {};

    Trajectory Trac;
    Robot6Axis& Rob;
    Base::Placement Tool;
};


}  // namespace Robot
