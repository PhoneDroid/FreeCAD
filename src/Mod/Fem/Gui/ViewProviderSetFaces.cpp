// SPDX-FileCopyrightText: 2013 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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


#include "ViewProviderSetFaces.h"


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderSetFaces, Gui::ViewProviderGeometryObject)

bool ViewProviderSetFaces::doubleClicked()
{
    // Gui::TaskView::TaskDialog* dlg = new TaskDlgCreateNodeSet(getObject<Fem::FemSetNodesObject
    // >()); Gui::Control().showDialog(dlg);
    return true;
}


bool ViewProviderSetFaces::setEdit(int)
{
    // Gui::TaskView::TaskDialog* dlg = new TaskDlgCreateNodeSet(getObject<Fem::FemSetNodesObject
    // >()); Gui::Control().showDialog(dlg);
    return true;
}

void ViewProviderSetFaces::unsetEdit(int)
{}
