// SPDX-FileCopyrightText: 2019 Wanderer Fan <wandererfan@gmail.com>
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
#include "ViewProviderTile.h"

using namespace TechDrawGui;

PROPERTY_SOURCE(TechDrawGui::ViewProviderTile, Gui::ViewProviderDocumentObject)

//**************************************************************************
// Construction/Destruction

ViewProviderTile::ViewProviderTile()
{
    sPixmap = "actions/TechDraw_Tile";
}

ViewProviderTile::~ViewProviderTile()
{
}

//TechDraw::DrawTile* ViewProviderTile::getViewObject() const
//{
//    return dynamic_cast<TechDraw::DrawTile*>(pcObject);
//}

bool ViewProviderTile::canDelete(App::DocumentObject *obj) const
{
    // deletions of Tile objects don't destroy anything
    // thus we can pass this action
    // that the deletion of its parent weld symbol is not possible
    // is done in its onDelete() function
    Q_UNUSED(obj)
    return true;
}

TechDraw::DrawTile* ViewProviderTile::getFeature() const
{
    return dynamic_cast<TechDraw::DrawTile*>(pcObject);
}
