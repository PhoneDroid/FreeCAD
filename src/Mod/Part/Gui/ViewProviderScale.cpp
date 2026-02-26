// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2023 Wanderer Fan <wandererfan@gmail.com>
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


#include "ViewProviderScale.h"
#include <Mod/Part/App/FeatureScale.h>


using namespace PartGui;

PROPERTY_SOURCE(PartGui::ViewProviderScale, PartGui::ViewProviderPart)

ViewProviderScale::ViewProviderScale()
{
    sPixmap = "Part_Scale.svg";
}

ViewProviderScale::~ViewProviderScale() = default;

std::vector<App::DocumentObject*> ViewProviderScale::claimChildren() const
{
    std::vector<App::DocumentObject*> temp;
    temp.push_back(getObject<Part::Scale>()->Base.getValue());

    return temp;
}
