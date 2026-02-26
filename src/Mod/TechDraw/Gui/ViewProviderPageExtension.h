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
class ViewProviderPage;

class TechDrawGuiExport ViewProviderPageExtension: public Gui::ViewProviderExtension
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderPageExtension);

public:
    /// Constructor
    ViewProviderPageExtension();
    ~ViewProviderPageExtension() override;

    bool extensionCanDragObjects() const override;
    bool extensionCanDragObject(App::DocumentObject*) const override;
    void extensionDragObject(App::DocumentObject*) override;
    bool extensionCanDropObjects() const override;
    bool extensionCanDropObject(App::DocumentObject*) const override;
    bool extensionCanDropObjectEx(App::DocumentObject* obj, App::DocumentObject* owner,
        const char* subname,
        const std::vector<std::string>& elements) const override;
    void extensionDropObject(App::DocumentObject*) override;

    void dropObject(App::DocumentObject* docObj);

    const ViewProviderPage* getViewProviderPage() const;
    const char* whoAmI() const;

private:
};

using ViewProviderPageExtensionPython =
    Gui::ViewProviderExtensionPythonT<TechDrawGui::ViewProviderPageExtension>;

}// namespace TechDrawGui