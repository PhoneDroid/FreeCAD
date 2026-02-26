// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2005 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Inventor/SbColor.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/nodes/SoSubNode.h>
#include <FCGlobal.h>


class SbColor;
class SoGLRenderAction;

namespace Gui
{

class GuiExport SoFCBackgroundGradient: public SoNode
{
    using inherited = SoNode;

    SO_NODE_HEADER(Gui::SoFCBackgroundGradient);

public:
    enum Gradient
    {
        LINEAR = 0,
        RADIAL = 1
    };
    static void initClass();
    static void finish();
    SoFCBackgroundGradient();

    void GLRender(SoGLRenderAction* action) override;
    void setGradient(Gradient grad);
    Gradient getGradient() const;
    void setColorGradient(const SbColor& fromColor, const SbColor& toColor);
    void setColorGradient(const SbColor& fromColor, const SbColor& toColor, const SbColor& midColor);

private:
    Gradient gradient;

protected:
    ~SoFCBackgroundGradient() override;

    SbColor fCol, tCol, mCol;
};

}  // namespace Gui
