// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2020 sliptonic <shopinthewoods@gmail.com>
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

#include <Base/BaseClass.h>
#include "Voronoi.h"

namespace Path
{

class Voronoi;

class PathExport VoronoiCell: public Base::BaseClass
{
    TYPESYSTEM_HEADER_WITH_OVERRIDE();

public:
    VoronoiCell(Voronoi::diagram_type* dia = nullptr, long index = Voronoi::InvalidIndex);
    VoronoiCell(Voronoi::diagram_type* dia, const Voronoi::diagram_type::cell_type* cell);
    ~VoronoiCell() override;

    bool isBound() const;

    Voronoi::point_type sourcePoint() const;
    Voronoi::segment_type sourceSegment() const;

    Base::Reference<Voronoi::diagram_type> dia;
    long index;
    mutable const Voronoi::diagram_type::cell_type* ptr;
};

}  // namespace Path
