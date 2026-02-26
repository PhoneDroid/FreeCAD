// SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#include "ViewProviderGroupExtension.h"


namespace Gui
{

class GuiExport ViewProviderGeoFeatureGroupExtension: public ViewProviderGroupExtension
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderGeoFeatureGroupExtension);

public:
    /// Constructor
    ViewProviderGeoFeatureGroupExtension();
    ~ViewProviderGeoFeatureGroupExtension() override;

    std::vector<App::DocumentObject*> extensionClaimChildren3D() const override;
    std::vector<App::DocumentObject*> extensionClaimChildren() const override;
    SoSeparator* extensionGetFrontRoot() const override
    {
        return pcGroupFront;
    }
    SoSeparator* extensionGetBackRoot() const override
    {
        return pcGroupBack;
    }
    SoGroup* extensionGetChildRoot() const override
    {
        return pcGroupChildren;
    }
    void extensionAttach(App::DocumentObject* pcObject) override;
    void extensionSetDisplayMode(const char* ModeName) override;
    std::vector<std::string> extensionGetDisplayModes() const override;
    void extensionFinishRestoring() override;

    /// Show the object in the view: suppresses behavior of DocumentObjectGroup
    void extensionShow() override
    {
        ViewProviderExtension::extensionShow();  // clazy:exclude=skipped-base-method
    }
    /// Hide the object in the view: suppresses behavior of DocumentObjectGroup
    void extensionHide() override
    {
        ViewProviderExtension::extensionHide();  // clazy:exclude=skipped-base-method
    }

    void extensionUpdateData(const App::Property*) override;

protected:
    SoSeparator* pcGroupFront;
    SoSeparator* pcGroupBack;
    SoGroup* pcGroupChildren;
};

using ViewProviderGeoFeatureGroupExtensionPython
    = ViewProviderExtensionPythonT<Gui::ViewProviderGeoFeatureGroupExtension>;

}  // namespace Gui
