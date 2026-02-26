// SPDX-FileCopyrightText: 2024 Florian Foinant-Willig <ffw@2f2v.fr>
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

#include "ViewProviderExtensionPython.h"


namespace Gui
{

class GuiExport ViewProviderSuppressibleExtension: public ViewProviderExtension
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderSuppressibleExtension);

public:
    ViewProviderSuppressibleExtension();
    ~ViewProviderSuppressibleExtension() override;

    void extensionUpdateData(const App::Property* prop) override;

    void setSuppressedIcon(bool onoff);
    QIcon extensionMergeColorfullOverlayIcons(const QIcon& orig) const override;
    void extensionSetupContextMenu(QMenu* menu, QObject*, const char*) override;

private:
    bool isSetSuppressedIcon {false};
};

using ViewProviderSuppressibleExtensionPython
    = ViewProviderExtensionPythonT<Gui::ViewProviderSuppressibleExtension>;

}  // namespace Gui
