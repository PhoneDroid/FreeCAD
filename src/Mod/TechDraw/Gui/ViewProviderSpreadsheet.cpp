// SPDX-FileCopyrightText: 2016 WandererFan <wandererfan@gmail.com>
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


#include <App/DocumentObject.h>
#include "ViewProviderSpreadsheet.h"

using namespace TechDrawGui;

PROPERTY_SOURCE(TechDrawGui::ViewProviderSpreadsheet, TechDrawGui::ViewProviderSymbol)

//**************************************************************************
// Construction/Destruction

ViewProviderSpreadsheet::ViewProviderSpreadsheet()
{
    sPixmap = "TechDraw_TreeSpreadsheet";
    ADD_PROPERTY_TYPE(ClaimSheetAsChild,
                      (false),
                      "Display Options",
                      App::Prop_None,
                      "Claim (or not) the spreadsheet source as a child of the view.");
    LegacyScaling.setValue(true);
}

ViewProviderSpreadsheet::~ViewProviderSpreadsheet()
{
}

TechDraw::DrawViewSpreadsheet* ViewProviderSpreadsheet::getViewObject() const
{
    return dynamic_cast<TechDraw::DrawViewSpreadsheet*>(pcObject);
}

std::vector<App::DocumentObject*> ViewProviderSpreadsheet::claimChildren() const
{
    std::vector<App::DocumentObject*> temp;

    if (ClaimSheetAsChild.getValue()) {
        temp.push_back(getViewObject()->Source.getValue());
    }

    return temp;
}
