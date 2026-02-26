// SPDX-FileCopyrightText: 2023 WandererFan <wandererfan@gmail.com>
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

// a class for converting geometry into QPainterPaths


#pragma once

#include <Mod/TechDraw/TechDrawGlobal.h>

#include <Mod/TechDraw/App/Geometry.h>

#include "QGIViewPart.h"

namespace TechDrawGui {

class TechDrawGuiExport PathBuilder {
public:
    PathBuilder() {}
    PathBuilder(QGIViewPart* qvp) { m_qvp = qvp; }
    ~PathBuilder() = default;

    QPainterPath geomToPainterPath(TechDraw::BaseGeomPtr baseGeom, double rot) const;
    void pathArc(QPainterPath& path, double rx, double ry, double x_axis_rotation,
                          bool large_arc_flag, bool sweep_flag, double x, double y, double curx,
                          double cury) const;
    void pathArcSegment(QPainterPath& path, double xc, double yc, double th0, double th1,
                                 double rx, double ry, double xAxisRotation) const;

private:
    QGIViewPart* m_qvp;

};

} //end namespace TechDraw