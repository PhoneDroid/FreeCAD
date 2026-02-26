// SPDX-FileCopyrightText: 2025 Stefan Tröger <stefantroeger@gmx.net>
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

#include "ViewProviderFemPostObject.h"
#include <Gui/ViewProviderGroupExtension.h>


namespace Gui
{
class SelectionChanges;
class SoFCColorBar;
}  // namespace Gui

namespace FemGui
{

class TaskDlgPost;

class FemGuiExport ViewProviderFemPostBranchFilter: public ViewProviderFemPostObject,
                                                    public Gui::ViewProviderGroupExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(FemGui::ViewProviderFemPostBranchFilter);

public:
    ViewProviderFemPostBranchFilter();
    ~ViewProviderFemPostBranchFilter() override;

protected:
    virtual void setupTaskDialog(TaskDlgPost* dlg) override;

    // change default group drag/drop behaviour slightly
    bool acceptReorderingObjects() const override;
    bool canDragObjectToTarget(App::DocumentObject* obj, App::DocumentObject* target) const override;

    // override, to not show/hide children as the parent is shown/hidden like normal groups
    void extensionHide() override {};
    void extensionShow() override {};
};

}  // namespace FemGui
