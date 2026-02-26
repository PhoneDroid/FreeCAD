// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2021 edi

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

#include <Mod/TechDraw/TechDrawGlobal.h>

namespace TechDraw
{
    class ReferenceEntry;
    class DrawViewDimension;
}

namespace TechDrawGui {
    TechDraw::DrawViewDimension* makeArcLengthDimension(const TechDraw::ReferenceEntry& ref);

    std::vector<TechDraw::DrawViewDimension*> makeObliqueChainDimension(std::vector<TechDraw::ReferenceEntry> refs);
    std::vector<TechDraw::DrawViewDimension*> makeObliqueCoordDimension(std::vector<TechDraw::ReferenceEntry> refs);
}