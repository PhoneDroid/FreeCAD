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


#include "DrawWeldSymbol.h"
// inclusion of the generated files (generated out of DrawWeldSymbolPy.xml)
#include <Mod/TechDraw/App/DrawWeldSymbolPy.h>
#include <Mod/TechDraw/App/DrawWeldSymbolPy.cpp>


using namespace TechDraw;

// returns a string which represents the object e.g. when printed in python
std::string DrawWeldSymbolPy::representation() const
{
    return std::string("<DrawWeldSymbol object>");
}

//PyObject* DrawWeldSymbolPy::getTiles(PyObject *args)
//{
//    const char* fileSpec;
//    PyObject* pTile
//    if (!PyArg_ParseTuple(args, "O", &pTile)) {
//       throw Py::TypeError("getTiles expected DrawTile");
//    }
//    auto dws = getDrawWeldSymbolPtr();
////    auto dt  = pTile->getDrawTilePtr();
////TODO: finish this!
//    Py_Return;
//}

PyObject *DrawWeldSymbolPy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int DrawWeldSymbolPy::setCustomAttributes(const char* /*attr*/, PyObject* /*obj*/)
{
    return 0;
}
