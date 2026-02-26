// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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


#include <QMenu>


#include "TaskRevolutionParameters.h"
#include "ViewProviderRevolution.h"

using namespace PartDesignGui;

PROPERTY_SOURCE(PartDesignGui::ViewProviderRevolution, PartDesignGui::ViewProviderSketchBased)

ViewProviderRevolution::ViewProviderRevolution()
{
    sPixmap = "PartDesign_Revolution.svg";
}

ViewProviderRevolution::~ViewProviderRevolution() = default;

void ViewProviderRevolution::setupContextMenu(QMenu* menu, QObject* receiver, const char* member)
{
    addDefaultAction(menu, QObject::tr("Edit Revolution"));
    PartDesignGui::ViewProviderSketchBased::setupContextMenu(menu, receiver, member);
}

TaskDlgFeatureParameters* ViewProviderRevolution::getEditDialog()
{
    return new TaskDlgRevolutionParameters(this);
}
