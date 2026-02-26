// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2010 Jürgen Riegel <juergen.riegel@web.de>
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


#include "FeatureGeometrySet.h"


using namespace Part;


PROPERTY_SOURCE(Part::FeatureGeometrySet, Part::Feature)


FeatureGeometrySet::FeatureGeometrySet()
{
    ADD_PROPERTY(GeometrySet, (nullptr));
}


App::DocumentObjectExecReturn* FeatureGeometrySet::execute()
{
    TopoShape result;

    const std::vector<Geometry*>& Geoms = GeometrySet.getValues();

    bool first = true;
    for (auto Geom : Geoms) {
        TopoDS_Shape sh = Geom->toShape();
        if (first) {
            first = false;
            result.setShape(sh);
        }
        else {
            result.setShape(result.fuse(sh));
        }
    }

    Shape.setValue(result);

    return App::DocumentObject::StdReturn;
}
