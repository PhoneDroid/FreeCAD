// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2013 Thomas Anderson <blobfish@gmx.com>
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

#include <FCGlobal.h>
#include <Inventor/fields/SoMFColor.h>
#include <Inventor/engines/SoEngineOutput.h>

#include <Inventor/engines/SoSubEngine.h>
#include <Inventor/engines/SoEngine.h>
#include <Inventor/fields/SoSFColor.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFMatrix.h>
#include <Inventor/fields/SoSFRotation.h>
#include <Inventor/fields/SoSFString.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/nodekits/SoSeparatorKit.h>

class SoText2;
class SoTranslation;
class SoCoordinate3;
class SoIndexedLineSet;

namespace Gui
{


// /*used for generating points for arc display*/
class GuiExport ArcEngine: public SoEngine
{
    SO_ENGINE_HEADER(ArcEngine);

public:
    ArcEngine();
    static void initClass();

    SoSFFloat radius;
    SoSFFloat angle;
    SoSFFloat deviation;

    SoEngineOutput points;
    SoEngineOutput pointCount;
    SoEngineOutput midpoint;

protected:
    void evaluate() override;

private:
    ~ArcEngine() override
    {}
    void defaultValues();  // some non error values if something goes wrong.
};

}  // namespace Gui
