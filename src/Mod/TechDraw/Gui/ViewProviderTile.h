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

#pragma once

#include <Mod/TechDraw/TechDrawGlobal.h>

#include <Gui/ViewProviderDocumentObject.h>
#include <Mod/TechDraw/App/DrawTile.h>

namespace TechDrawGui {

class TechDrawGuiExport ViewProviderTile : public Gui::ViewProviderDocumentObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderTile);

public:
    /// constructor
    ViewProviderTile();
    /// destructor
    ~ViewProviderTile() override;

    bool useNewSelectionModel() const override {return false;}
    bool canDelete(App::DocumentObject *obj) const override;

/*    virtual TechDraw::DrawTile* getViewObject() const;*/
    virtual TechDraw::DrawTile* getFeature() const;
};

} // namespace TechDrawGui