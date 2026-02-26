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


#include "VoronoiVertex.h"


using namespace Base;
using namespace Path;

TYPESYSTEM_SOURCE(Path::VoronoiVertex, Base::Persistence)

VoronoiVertex::VoronoiVertex(Voronoi::diagram_type* d, long index)
    : dia(d)
    , index(index)
    , ptr(nullptr)
{
    if (dia && long(dia->num_vertices()) > index) {
        ptr = &(dia->vertices()[index]);
    }
}

VoronoiVertex::VoronoiVertex(Voronoi::diagram_type* d, const Voronoi::diagram_type::vertex_type* v)
    : dia(d)
    , index(Voronoi::InvalidIndex)
    , ptr(v)
{
    if (dia && v) {
        index = dia->index(v);
    }
}

VoronoiVertex::~VoronoiVertex()
{}

bool VoronoiVertex::isBound() const
{
    if (ptr && dia.isValid() && index != Voronoi::InvalidIndex) {
        if (&(dia->vertices()[index]) == ptr) {
            return true;
        }
    }
    ptr = nullptr;
    return false;
}
