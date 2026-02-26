// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2019 sliptonic <shopinthewoods@gmail.com>
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

#include <deque>

#include <Base/Vector3D.h>

#include "Path.h"


namespace Path
{

/**
 * PathSegmentVisitor is the companion class to PathSegmentWalker. Its members are called
 * with the segmented points of each command.
 */
class PathExport PathSegmentVisitor
{
public:
    virtual ~PathSegmentVisitor();

    virtual void setup(const Base::Vector3d& last);

    virtual void g0(
        int id,
        const Base::Vector3d& last,
        const Base::Vector3d& next,
        const std::deque<Base::Vector3d>& pts
    );
    virtual void g1(
        int id,
        const Base::Vector3d& last,
        const Base::Vector3d& next,
        const std::deque<Base::Vector3d>& pts
    );
    virtual void g23(
        int id,
        const Base::Vector3d& last,
        const Base::Vector3d& next,
        const std::deque<Base::Vector3d>& pts,
        const Base::Vector3d& center
    );
    virtual void g8x(
        int id,
        const Base::Vector3d& last,
        const Base::Vector3d& next,
        const std::deque<Base::Vector3d>& pts,
        const std::deque<Base::Vector3d>& p,
        const std::deque<Base::Vector3d>& q
    );
    virtual void g38(int id, const Base::Vector3d& last, const Base::Vector3d& next);
};

/**
 * PathSegmentWalker processes a path and splits all movement commands into straight segments and
 * calls the appropriate member of the provided PathSegmentVisitor. All non-movement commands are
 * processed accordingly if they affect the movement commands.
 */
class PathExport PathSegmentWalker
{
public:
    PathSegmentWalker(const Toolpath& tp_);


    void walk(PathSegmentVisitor& cb, const Base::Vector3d& startPosition);

private:
    const Toolpath& tp;
    int retract_mode;
};


}  // namespace Path
