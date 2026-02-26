// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2014 Yorik van Havre <yorik@uncreated.net>
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


#include <Gui/BitmapFactory.h>
#include <Gui/Control.h>

#include "TaskDlgPathCompound.h"


using namespace Gui;
using namespace PathGui;

PROPERTY_SOURCE(PathGui::ViewProviderPathCompound, PathGui::ViewProviderPath)


bool ViewProviderPathCompound::setEdit(int ModNum)
{
    Q_UNUSED(ModNum);
    Gui::TaskView::TaskDialog* dlg = new TaskDlgPathCompound(this);
    Gui::Control().showDialog(dlg);
    return true;
}

void ViewProviderPathCompound::unsetEdit(int ModNum)
{
    Q_UNUSED(ModNum);
    // when pressing ESC make sure to close the dialog
    Gui::Control().closeDialog();
}

std::vector<App::DocumentObject*> ViewProviderPathCompound::claimChildren() const
{
    return std::vector<App::DocumentObject*>(getObject<Path::FeatureCompound>()->Group.getValues());
}

bool ViewProviderPathCompound::canDragObjects() const
{
    return true;
}

void ViewProviderPathCompound::dragObject(App::DocumentObject* obj)
{
    getObject<Path::FeatureCompound>()->removeObject(obj);
}

bool ViewProviderPathCompound::canDropObjects() const
{
    return true;
}

void ViewProviderPathCompound::dropObject(App::DocumentObject* obj)
{
    getObject<Path::FeatureCompound>()->addObject(obj);
}

QIcon ViewProviderPathCompound::getIcon() const
{
    return Gui::BitmapFactory().pixmap("CAM_Compound");
}

// Python object -----------------------------------------------------------------------

namespace Gui
{
/// @cond DOXERR
PROPERTY_SOURCE_TEMPLATE(PathGui::ViewProviderPathCompoundPython, PathGui::ViewProviderPathCompound)
/// @endcond

// explicit template instantiation
template class PathGuiExport ViewProviderFeaturePythonT<PathGui::ViewProviderPathCompound>;
}  // namespace Gui
