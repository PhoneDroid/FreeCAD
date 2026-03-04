// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2020 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <sstream>

#include "ViewProviderDocumentObject.h"

// generated out of ViewProviderExtension.pyi
#include "ViewProviderExtensionPy.h"
#include "ViewProviderExtensionPy.cpp"

using namespace Gui;

// returns a string which represent the object e.g. when printed in python
std::string ViewProviderExtensionPy::representation() const
{
    return {"<view provider extension>"};
}

PyObject* ViewProviderExtensionPy::setIgnoreOverlayIcon(PyObject* args)
{
    PyObject* ignore;
    const char* name = nullptr;
    if (!PyArg_ParseTuple(args, "O!s", &PyBool_Type, &ignore, &name)) {
        return nullptr;
    }

    ViewProviderExtension* ext = getViewProviderExtensionPtr();
    if (name) {
        Base::Type type = Base::Type::fromName(name);
        ext = dynamic_cast<ViewProviderExtension*>(
            ext->getExtendedContainer()->getExtension(type, true, true)
        );
        if (!ext) {
            PyErr_SetString(PyExc_NameError, "no such extension");
            return nullptr;
        }
    }

    ext->setIgnoreOverlayIcon(Base::asBoolean(ignore));
    Py_Return;
}

PyObject* ViewProviderExtensionPy::ignoreOverlayIcon(PyObject* args) const
{
    const char* name = nullptr;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return nullptr;
    }

    ViewProviderExtension* ext = getViewProviderExtensionPtr();
    if (name) {
        Base::Type type = Base::Type::fromName(name);
        ext = dynamic_cast<ViewProviderExtension*>(
            ext->getExtendedContainer()->getExtension(type, true, true)
        );
        if (!ext) {
            PyErr_SetString(PyExc_NameError, "no such extension");
            return nullptr;
        }
    }

    bool ignore = ext->ignoreOverlayIcon();
    return Py_BuildValue("O", (ignore ? Py_True : Py_False));
}

PyObject* ViewProviderExtensionPy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int ViewProviderExtensionPy::setCustomAttributes(const char* /*attr*/, PyObject* /*obj*/)
{
    return 0;
}
