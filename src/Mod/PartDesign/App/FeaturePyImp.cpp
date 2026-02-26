// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2007 Werner Mayer <wmayer@users.sourceforge.net>
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


// inclusion of the generated files (generated out of FeaturePy.xml)
#include "FeaturePy.h"
#include "FeaturePy.cpp"

using namespace PartDesign;

// returns a string which represent the object e.g. when printed in python
std::string FeaturePy::representation() const
{
    App::DocumentObject* object = this->getFeaturePtr();
    std::stringstream str;
    str << "<" << object->getTypeId().getName() << ">";
    return str.str();
}

PyObject* FeaturePy::getCustomAttributes(const char*) const
{
    return nullptr;
}

int FeaturePy::setCustomAttributes(const char*, PyObject*)
{
    return 0;
}

PyObject* FeaturePy::getBaseObject(PyObject* /*args*/)
{
    App::DocumentObject* base = getFeaturePtr()->getBaseObject();
    if (base) {
        return base->getPyObject();
    }
    else {
        return Py::new_reference_to(Py::None());
    }
}
