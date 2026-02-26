// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2024 Ondsel (PL Boyer) <development@ondsel.com>
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

#include <App/Document.h>
#include <App/DocumentObjectGroup.h>
#include <Gui/Application.h>
#include <Gui/Command.h>
#include <Gui/Control.h>
#include <Gui/View3DInventor.h>
#include <Gui/View3DInventorViewer.h>

#include "ViewProviderDatum.h"


using namespace PartGui;

PROPERTY_SOURCE_WITH_EXTENSIONS(PartGui::ViewProviderLine, Gui::ViewProviderLine)

ViewProviderLine::ViewProviderLine()
{
    PartGui::ViewProviderAttachExtension::initExtension(this);
}

bool ViewProviderLine::doubleClicked()
{
    showAttachmentEditor();
    return true;
}

PROPERTY_SOURCE_WITH_EXTENSIONS(PartGui::ViewProviderPlane, Gui::ViewProviderPlane)

ViewProviderPlane::ViewProviderPlane()
{
    PartGui::ViewProviderAttachExtension::initExtension(this);
}

bool ViewProviderPlane::doubleClicked()
{
    showAttachmentEditor();
    return true;
}


PROPERTY_SOURCE_WITH_EXTENSIONS(PartGui::ViewProviderPoint, Gui::ViewProviderPoint)

ViewProviderPoint::ViewProviderPoint()
{
    PartGui::ViewProviderAttachExtension::initExtension(this);
}

bool ViewProviderPoint::doubleClicked()
{
    showAttachmentEditor();
    return true;
}


PROPERTY_SOURCE_WITH_EXTENSIONS(PartGui::ViewProviderLCS, Gui::ViewProviderCoordinateSystem)

ViewProviderLCS::ViewProviderLCS()
{
    PartGui::ViewProviderAttachExtension::initExtension(this);
}

bool ViewProviderLCS::doubleClicked()
{
    showAttachmentEditor();
    return true;
}
