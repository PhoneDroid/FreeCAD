// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2008 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Inventor/elements/SoReplacedElement.h>
#include <Inventor/fields/SoSFBool.h>
#include <Inventor/fields/SoSFInt32.h>
#include <Inventor/nodes/SoShape.h>
#include <Mod/Mesh/MeshGlobal.h>


namespace MeshGui
{

// NOLINTBEGIN
class MeshGuiExport SoPolygon: public SoShape
{
    using inherited = SoShape;

    SO_NODE_HEADER(SoPolygon);

public:
    static void initClass();
    SoPolygon();

    SoSFInt32 startIndex;
    SoSFInt32 numVertices;
    SoSFBool highlight;
    SoSFBool render;

protected:
    ~SoPolygon() override = default;
    void GLRender(SoGLRenderAction* action) override;
    void computeBBox(SoAction* action, SbBox3f& box, SbVec3f& center) override;
    void rayPick(SoRayPickAction* action) override;
    void generatePrimitives(SoAction* action) override;

private:
    void drawPolygon(const SbVec3f*, int32_t) const;
};
// NOLINTEND

}  // namespace MeshGui
