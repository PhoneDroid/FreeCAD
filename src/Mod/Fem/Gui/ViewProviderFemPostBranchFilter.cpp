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

#include "TaskPostBoxes.h"
#include "ViewProviderFemPostBranchFilter.h"
#include <Mod/Fem/App/FemPostGroupExtension.h>
#include <Gui/BitmapFactory.h>


using namespace FemGui;


PROPERTY_SOURCE_WITH_EXTENSIONS(FemGui::ViewProviderFemPostBranchFilter, FemGui::ViewProviderFemPostObject)

ViewProviderFemPostBranchFilter::ViewProviderFemPostBranchFilter()
    : Gui::ViewProviderGroupExtension()
{
    Gui::ViewProviderGroupExtension::initExtension(this);
    sPixmap = "FEM_PostBranchFilter";
}

ViewProviderFemPostBranchFilter::~ViewProviderFemPostBranchFilter()
{}

void ViewProviderFemPostBranchFilter::setupTaskDialog(TaskDlgPost* dlg)
{
    // add the branch ui
    auto panel = new TaskPostBranch(this);
    dlg->addTaskBox(panel->windowIcon().pixmap(32), panel);

    // add the display options
    FemGui::ViewProviderFemPostObject::setupTaskDialog(dlg);
}

bool ViewProviderFemPostBranchFilter::acceptReorderingObjects() const
{
    return true;
}

bool ViewProviderFemPostBranchFilter::canDragObjectToTarget(
    App::DocumentObject*,
    App::DocumentObject* target
) const
{

    // allow drag only to other post groups
    if (target) {
        return target->hasExtension(Fem::FemPostGroupExtension::getExtensionClassTypeId());
    }
    else {
        return false;
    }
}
