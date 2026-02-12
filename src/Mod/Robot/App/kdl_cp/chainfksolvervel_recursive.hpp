// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2007 Ruben Smits <ruben.smits@mech.kuleuven.be>
// SPDX-FileNotice: Part of the FreeCAD project.

// Version: 1.0
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once

#include "chainfksolver.hpp"

namespace KDL
{
    /**
     * Implementation of a recursive forward position and velocity
     * kinematics algorithm to calculate the position and velocity
     * transformation from joint space to Cartesian space of a general
     * kinematic chain (KDL::Chain).
     *
     * @ingroup KinematicFamily
     */
    class ChainFkSolverVel_recursive : public ChainFkSolverVel
    {
    public:
        ChainFkSolverVel_recursive(const Chain& chain);
        ~ChainFkSolverVel_recursive();

        virtual int JntToCart(const JntArrayVel& q_in,FrameVel& out,int segmentNr=-1);
    private:
        const Chain chain;
    };
}