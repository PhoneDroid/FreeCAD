// SPDX-FileCopyrightText: 2019 WandererFan <wandererfan@gmail.com>
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


#include "Mod/TechDraw/App/CosmeticExtension.h"
// inclusion of the generated files (generated out of CosmeticExtensionPy.xml)
#include "CosmeticExtensionPy.h"
#include "CosmeticExtensionPy.cpp"


using namespace TechDraw;

// returns a string which represents the object e.g. when printed in python
std::string CosmeticExtensionPy::representation() const
{
    return std::string("<TechDraw::CosmeticObject>");
}

PyObject *CosmeticExtensionPy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int CosmeticExtensionPy::setCustomAttributes(const char* /*attr*/, PyObject* /*obj*/)
{
    return 0;
}


