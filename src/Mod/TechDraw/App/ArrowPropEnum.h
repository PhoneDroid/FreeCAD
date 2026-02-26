// SPDX-FileCopyrightText: 2020 WandererFan <wandererfan@gmail.com>
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
#include <QCoreApplication>

#include <Mod/TechDraw/TechDrawGlobal.h>


namespace TechDraw
{

//common definitions for line ends / arrows
enum class ArrowType : int {
    FILLED_ARROW = 0,
    OPEN_ARROW,
    TICK,
    DOT,
    OPEN_CIRCLE,
    FORK,
    FILLED_TRIANGLE,
    NONE
};

class TechDrawExport ArrowPropEnum {
    Q_DECLARE_TR_FUNCTIONS(TechDraw::ArrowPropEnum)

    public:
        static const char* ArrowTypeEnums[];
        static const int   ArrowCount;
        static const std::vector<std::string> ArrowTypeIcons;

private:

};

} //end namespace TechDraw