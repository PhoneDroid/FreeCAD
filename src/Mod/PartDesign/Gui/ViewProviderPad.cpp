// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2010 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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


#include "TaskPadParameters.h"
#include "ViewProviderPad.h"

using namespace PartDesignGui;

PROPERTY_SOURCE(PartDesignGui::ViewProviderPad, PartDesignGui::ViewProviderExtrude)

ViewProviderPad::ViewProviderPad()
{
    sPixmap = "PartDesign_Pad.svg";
}

ViewProviderPad::~ViewProviderPad() = default;

void ViewProviderPad::setupContextMenu(QMenu* menu, QObject* receiver, const char* member)
{
    addDefaultAction(menu, QObject::tr("Edit Pad"));
    PartDesignGui::ViewProviderSketchBased::setupContextMenu(menu, receiver, member);
}

TaskDlgFeatureParameters* ViewProviderPad::getEditDialog()
{
    // TODO fix setting values from the history: now it doesn't work neither in
    //      the master and in the migrated branch  (2015-07-26, Fat-Zer)
    return new TaskDlgPadParameters(this);
}
