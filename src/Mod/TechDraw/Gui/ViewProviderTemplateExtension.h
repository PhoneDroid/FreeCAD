// SPDX-FileCopyrightText: 2022 WandererFan <wandererfan@gmail.com>
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

#include <Gui/ViewProviderExtension.h>
#include <Gui/ViewProviderExtensionPython.h>
#include <Mod/TechDraw/TechDrawGlobal.h>


namespace TechDrawGui
{
class ViewProviderTemplate;

class TechDrawGuiExport ViewProviderTemplateExtension: public Gui::ViewProviderExtension
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderTemplateExtension);

public:
    /// Constructor
    ViewProviderTemplateExtension();
    ~ViewProviderTemplateExtension() override;

    bool extensionCanDragObjects() const override;
    bool extensionCanDragObject(App::DocumentObject* docObj) const override;
    bool extensionCanDropObjects() const override;
    bool extensionCanDropObject(App::DocumentObject* docObj) const override;

    const ViewProviderTemplate* getViewProviderTemplate() const;
    const char* whoAmI() const;

private:
};

using ViewProviderTemplateExtensionPython =
    Gui::ViewProviderExtensionPythonT<TechDrawGui::ViewProviderTemplateExtension>;

}// namespace TechDrawGui