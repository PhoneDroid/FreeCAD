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


#include "VoronoiCell.h"


using namespace Base;
using namespace Path;

TYPESYSTEM_SOURCE(Path::VoronoiCell, Base::Persistence)

VoronoiCell::VoronoiCell(Voronoi::diagram_type* d, long index)
    : dia(d)
    , index(index)
    , ptr(nullptr)
{
    if (dia && long(dia->num_cells()) > index) {
        ptr = &(dia->cells()[index]);
    }
}

VoronoiCell::VoronoiCell(Voronoi::diagram_type* d, const Voronoi::diagram_type::cell_type* e)
    : dia(d)
    , index(Voronoi::InvalidIndex)
    , ptr(e)
{
    if (d && e) {
        index = dia->index(e);
    }
}

VoronoiCell::~VoronoiCell()
{}

bool VoronoiCell::isBound() const
{
    if (ptr && dia.isValid() && index != Voronoi::InvalidIndex) {
        if (&(dia->cells()[index]) == ptr) {
            return true;
        }
    }
    ptr = nullptr;
    return false;
}

Voronoi::point_type VoronoiCell::sourcePoint() const
{
    int index = ptr->source_index();
    int category = ptr->source_category();
    if (category == boost::polygon::SOURCE_CATEGORY_SINGLE_POINT) {
        return dia->points[index];
    }
    if (category == boost::polygon::SOURCE_CATEGORY_SEGMENT_START_POINT) {
        return low(dia->segments[index - dia->points.size()]);
    }
    else {
        return high(dia->segments[index - dia->points.size()]);
    }
}

Voronoi::segment_type VoronoiCell::sourceSegment() const
{
    return dia->segments[ptr->source_index() - dia->points.size()];
}
