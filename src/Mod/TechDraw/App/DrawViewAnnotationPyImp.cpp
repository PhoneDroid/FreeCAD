// SPDX-FileCopyrightText: 2018 WandererFan <wandererfan@gmail.com>
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


# include <sstream>


#include "DrawView.h"
#include "DrawViewAnnotation.h"

// inclusion of the generated files
#include <Mod/TechDraw/App/DrawViewPy.h>
#include <Mod/TechDraw/App/DrawViewAnnotationPy.h>
#include <Mod/TechDraw/App/DrawViewAnnotationPy.cpp>


using namespace TechDraw;

// returns a string which represents the object e.g. when printed in python
std::string DrawViewAnnotationPy::representation() const
{
    return std::string("<DrawViewAnnotation object>");
}

PyObject *DrawViewAnnotationPy::getCustomAttributes(const char* ) const
{
    return nullptr;
}

int DrawViewAnnotationPy::setCustomAttributes(const char* , PyObject *)
{
    return 0;
}
