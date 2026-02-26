// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2006 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Gui/ViewProviderExtensionPython.h>
#include <Mod/Part/PartGlobal.h>


namespace PartGui
{

class PartGuiExport ViewProviderAttachExtension: public Gui::ViewProviderExtension
{
    EXTENSION_PROPERTY_HEADER_WITH_OVERRIDE(PartGui::ViewProviderAttachExtension);

public:
    /// Constructor
    ViewProviderAttachExtension();
    ~ViewProviderAttachExtension() override = default;

    QIcon extensionMergeColorfullOverlayIcons(const QIcon& orig) const override;

    void extensionUpdateData(const App::Property*) override;
    void extensionSetupContextMenu(QMenu*, QObject*, const char*) override;

    void showAttachmentEditor(std::function<void()> onAccept = {}, std::function<void()> onReject = {});
};

using ViewProviderAttachExtensionPython
    = Gui::ViewProviderExtensionPythonT<PartGui::ViewProviderAttachExtension>;

}  // namespace PartGui
