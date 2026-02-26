// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2017 Victor Titov (DeepSOIC) <vv.titov@gmail.com>
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


#include "ViewProvider.h"

// inclusion of the generated files (generated out of ViewProviderPy.xml)
#include "ViewProviderPy.h"
#include "ViewProviderPy.cpp"

using namespace PartDesignGui;

// returns a string which represent the object e.g. when printed in python
std::string ViewProviderPy::representation() const
{
    return {"<PartDesign::ViewProvider>"};
}

PyObject* ViewProviderPy::getCustomAttributes(const char*) const
{
    return nullptr;
}

int ViewProviderPy::setCustomAttributes(const char*, PyObject*)
{
    return 0;
}

PyObject* ViewProviderPy::setBodyMode(PyObject* args)
{
    PyObject* b_mode;
    if (!PyArg_ParseTuple(args, "O!", &PyBool_Type, &b_mode)) {
        return nullptr;
    }

    PartDesignGui::ViewProvider* base = getViewProviderPtr();
    base->setBodyMode(Base::asBoolean(b_mode));

    return Py::new_reference_to(Py::None());
}

PyObject* ViewProviderPy::makeTemporaryVisible(PyObject* args)
{
    PyObject* b_vis;
    if (!PyArg_ParseTuple(args, "O!", &PyBool_Type, &b_vis)) {
        return nullptr;
    }

    PartDesignGui::ViewProvider* base = getViewProviderPtr();
    base->makeTemporaryVisible(Base::asBoolean(b_vis));

    return Py::new_reference_to(Py::None());
}
