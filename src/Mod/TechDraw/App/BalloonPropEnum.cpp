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


#include "BalloonPropEnum.h"


namespace TechDraw {

const int   BalloonPropEnum::BalloonCount = 8;
const char* BalloonPropEnum::BalloonTypeEnums[]= {
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Circular"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "None"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Triangle"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Inspection"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Hexagon"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Square"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Rectangle"),
    QT_TRANSLATE_NOOP("BalloonPropEnum", "Line"),
    nullptr};

const std::vector<std::string> BalloonPropEnum::BalloonTypeIcons = { ":icons/circular.svg",
                                            ":icons/none.svg",
                                            ":icons/triangle.svg",
                                            ":icons/inspection.svg",
                                            ":icons/hexagon.svg",
                                            ":icons/square.svg",
                                            ":icons/rectangle.svg",
                                            ":icons/bottomline.svg"};

}
