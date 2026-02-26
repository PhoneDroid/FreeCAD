// SPDX-FileCopyrightText: 2015 Alexander Golubev <fatzer2@gmail.com>
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

#include "ViewProviderGeoFeatureGroup.h"


namespace Gui
{

class GuiExport ViewProviderOriginGroupExtension: public ViewProviderGeoFeatureGroupExtension
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderOriginGroupExtension);

public:
    /// Constructor
    ViewProviderOriginGroupExtension();
    ~ViewProviderOriginGroupExtension() override;

    std::vector<App::DocumentObject*> extensionClaimChildren() const override;
    std::vector<App::DocumentObject*> extensionClaimChildren3D() const override;

private:
    std::vector<App::DocumentObject*> constructChildren(
        const std::vector<App::DocumentObject*>& children
    ) const;
};

using ViewProviderOriginGroupExtensionPython
    = ViewProviderExtensionPythonT<Gui::ViewProviderOriginGroupExtension>;

}  // namespace Gui
