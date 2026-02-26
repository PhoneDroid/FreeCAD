// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2004 Jürgen Riegel <juergen.riegel@web.de>
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


#include "ViewProviderHelixParametric.h"

using namespace PartGui;


PROPERTY_SOURCE(PartGui::ViewProviderHelixParametric, PartGui::ViewProviderPrimitive)


ViewProviderHelixParametric::ViewProviderHelixParametric()
{
    sPixmap = "Part_Helix_Parametric";
    extension.initExtension(this);
}

ViewProviderHelixParametric::~ViewProviderHelixParametric() = default;

std::vector<std::string> ViewProviderHelixParametric::getDisplayModes() const
{
    // add your own modes
    std::vector<std::string> StrList;
    StrList.emplace_back("Wireframe");
    StrList.emplace_back("Points");

    return StrList;
}

void ViewProviderHelixParametric::setupContextMenu(QMenu* menu, QObject* receiver, const char* member)
{
    ViewProviderPrimitive::setupContextMenu(menu, receiver, member);
}

// ------------------------------------------------------------------

PROPERTY_SOURCE(PartGui::ViewProviderSpiralParametric, PartGui::ViewProviderPrimitive)


ViewProviderSpiralParametric::ViewProviderSpiralParametric()
{
    sPixmap = "Part_Spiral_Parametric";
    extension.initExtension(this);
}

ViewProviderSpiralParametric::~ViewProviderSpiralParametric() = default;

std::vector<std::string> ViewProviderSpiralParametric::getDisplayModes() const
{
    // add your own modes
    std::vector<std::string> StrList;
    StrList.emplace_back("Wireframe");
    StrList.emplace_back("Points");

    return StrList;
}

void ViewProviderSpiralParametric::setupContextMenu(QMenu* menu, QObject* receiver, const char* member)
{
    ViewProviderPrimitive::setupContextMenu(menu, receiver, member);
}
