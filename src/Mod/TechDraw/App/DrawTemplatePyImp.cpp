// SPDX-FileCopyrightText: 2014 Luke Parry <l.parry@warwick.ac.uk>
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


#include "DrawTemplate.h"
// inclusion of the generated files (generated out of DrawTemplateSFPy.xml)
#include <Mod/TechDraw/App/DrawTemplatePy.h>
#include <Mod/TechDraw/App/DrawTemplatePy.cpp>


using namespace TechDraw;

// returns a string which represents the object e.g. when printed in python
std::string DrawTemplatePy::representation() const
{
    return "<TechDraw::DrawTemplate>";
}

PyObject *DrawTemplatePy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int DrawTemplatePy::setCustomAttributes(const char* attr, PyObject* obj)
{
    // search in PropertyList
    App::Property *prop = getDrawTemplatePtr()->getPropertyByName(attr);
    if (!prop) {
        return 0;
    }

    // Read-only attributes must not be set over its Python interface
    short Type =  getDrawTemplatePtr()->getPropertyType(prop);
    if (Type & App::Prop_ReadOnly) {
        std::stringstream s;
        s << "Object attribute '" << attr << "' is read-only";
        throw Py::AttributeError(s.str());
    }

    prop->setPyObject(obj);
    return 1;
}
