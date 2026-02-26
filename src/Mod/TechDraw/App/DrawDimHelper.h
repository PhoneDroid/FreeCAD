// SPDX-FileCopyrightText: 2019 WandererFan <wandererfan@gmail.com>
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

#include <string>
#include <vector>

#include <gp_Pnt.hxx>
#include <TopoDS_Edge.hxx>

#include <Base/Vector3D.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DimensionReferences.h"


namespace TechDraw
{
class BaseGeom;
class DrawViewPart;
class DrawViewDimension;

/// Additional functions for working with Dimensions
class TechDrawExport DrawDimHelper {
    public:

    static DrawViewDimension* makeExtentDim(DrawViewPart* dvp,
                                            const std::string& dimType,
                                            ReferenceVector references2d);

    static DrawViewDimension* makeExtentDim(DrawViewPart* dvp,
                              std::vector<std::string> edgeNames,
                              int direction);

    static void makeExtentDim3d(DrawViewPart* dvp,
                                const std::string& dimType,
                                ReferenceVector references2d);
    static void makeExtentDim3d(DrawViewPart* dvp,
                                ReferenceVector references,
                                int direction);

    static gp_Pnt findClosestPoint(std::vector<TopoDS_Edge> inEdges,
                                   TopoDS_Edge& boundary);


    static DrawViewDimension* makeDistDim(DrawViewPart* dvp,
                                                    std::string dimType,
                                                    Base::Vector3d refMin,
                                                    Base::Vector3d refMax,
                                                    bool extent = false);

    static std::pair<Base::Vector3d, Base::Vector3d> minMax(DrawViewPart* dvp,
                                                            std::vector<std::string> edgeNames,
                                                            int direction);
    static std::pair<Base::Vector3d, Base::Vector3d> minMax3d(DrawViewPart* dvp,
                                                      ReferenceVector references,
                                                       int direction);
};

} //end namespace TechDraw