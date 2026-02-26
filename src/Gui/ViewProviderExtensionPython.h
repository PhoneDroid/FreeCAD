// SPDX-FileCopyrightText: 2016 Stefan Tröger <stefantroeger@gmx.net>
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


#pragma once

#include "ViewProviderExtension.h"
#include <App/PropertyPythonObject.h>

namespace Gui
{

/**
 * Generic Python extension class which allows one to behave every extension
 * derived class as Python extension -- simply by subclassing.
 */
template<class ExtensionT>
class ViewProviderExtensionPythonT: public ExtensionT  // NOLINT
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderExtensionPythonT<ExtensionT>);

public:
    using Inherited = ExtensionT;

    ViewProviderExtensionPythonT()
    {
        ExtensionT::m_isPythonExtension = true;
        ExtensionT::initExtensionType(ViewProviderExtensionPythonT::getExtensionClassTypeId());
    }
    ~ViewProviderExtensionPythonT() override = default;

    ViewProviderExtensionPythonT(const ViewProviderExtensionPythonT&) = delete;
    ViewProviderExtensionPythonT(ViewProviderExtensionPythonT&&) = delete;
    ViewProviderExtensionPythonT& operator=(const ViewProviderExtensionPythonT&) = delete;
    ViewProviderExtensionPythonT& operator=(ViewProviderExtensionPythonT&&) = delete;
};

using ViewProviderExtensionPython = ViewProviderExtensionPythonT<Gui::ViewProviderExtension>;

}  // namespace Gui
