// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2008 Werner Mayer <wmayer@users.sourceforge.net>
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


#include "ViewProviderExtrusion.h"
#include <Mod/Part/App/FeatureExtrusion.h>


using namespace PartGui;

PROPERTY_SOURCE(PartGui::ViewProviderExtrusion, PartGui::ViewProviderPart)

ViewProviderExtrusion::ViewProviderExtrusion()
{
    sPixmap = "Part_Extrude.svg";
}

ViewProviderExtrusion::~ViewProviderExtrusion() = default;

std::vector<App::DocumentObject*> ViewProviderExtrusion::claimChildren() const
{
    std::vector<App::DocumentObject*> temp;
    temp.push_back(getObject<Part::Extrusion>()->Base.getValue());

    return temp;
}
