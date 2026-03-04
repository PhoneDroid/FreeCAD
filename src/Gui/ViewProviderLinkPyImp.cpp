// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2017 Zheng Lei <realthunder.dev@gmail.com>
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

#include <Base/PlacementPy.h>

// generated out of ViewProviderLink.pyi
#include "ViewProviderLinkPy.h"
#include "ViewProviderLinkPy.cpp"

using namespace Gui;

// returns a string which represents the object e.g. when printed in python
std::string ViewProviderLinkPy::representation() const
{
    std::stringstream str;
    str << "<ViewProviderLink at " << getViewProviderLinkPtr() << ">";

    return str.str();
}

Py::Object ViewProviderLinkPy::getDraggingPlacement() const
{
    return Py::asObject(
        new Base::PlacementPy(new Base::Placement(getViewProviderLinkPtr()->getDraggerPlacement()))
    );
}

void ViewProviderLinkPy::setDraggingPlacement(Py::Object arg)
{
    if (!PyObject_TypeCheck(arg.ptr(), &Base::PlacementPy::Type)) {
        throw Py::TypeError("expects a placement");
    }
    getViewProviderLinkPtr()->setDraggerPlacement(
        *static_cast<Base::PlacementPy*>(arg.ptr())->getPlacementPtr()
    );
}

Py::Object ViewProviderLinkPy::getLinkView() const
{
    return Py::Object(getViewProviderLinkPtr()->getPyLinkView(), true);
}

PyObject* ViewProviderLinkPy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int ViewProviderLinkPy::setCustomAttributes(const char* /*attr*/, PyObject* /*obj*/)
{
    return 0;
}
