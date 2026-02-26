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


#include "MattingPropEnum.h"


namespace TechDraw {

const int   MattingPropEnum::MattingCount = 2;
const char* MattingPropEnum::MattingTypeEnums[]= {
    QT_TRANSLATE_NOOP("MattingPropEnum", "Circle"),
    QT_TRANSLATE_NOOP("MattingPropEnum", "Square"),
    nullptr};

const std::vector<std::string> MattingPropEnum::MattingTypeIcons = { ":icons/circular.svg",
                                            ":icons/square.svg"};

}
