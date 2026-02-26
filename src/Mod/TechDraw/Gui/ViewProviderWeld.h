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

#include <Gui/ViewProviderFeature.h>

#include "ViewProviderDrawingView.h"
#include <Mod/TechDraw/App/DrawTile.h>
#include <Mod/TechDraw/App/DrawWeldSymbol.h>


namespace TechDrawGui {

class TechDrawGuiExport ViewProviderWeld : public ViewProviderDrawingView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderWeld);

public:
    /// constructor
    ViewProviderWeld();
    /// destructor
    ~ViewProviderWeld() override;

    App::PropertyString      Font;
    App::PropertyLength      FontSize;
    App::PropertyLength      TileFontSize;

    bool useNewSelectionModel() const override {return false;}
    void onChanged(const App::Property* p) override;
    std::vector<App::DocumentObject*> claimChildren() const override;
    bool setEdit(int ModNum) override;
    bool doubleClicked() override;

    TechDraw::DrawWeldSymbol* getViewObject() const override;
    virtual TechDraw::DrawWeldSymbol* getFeature() const;

    std::string prefFontName();
    double prefFontSize();
    double prefTileTextAdjust();
    bool onDelete(const std::vector<std::string> &) override;
    bool canDelete(App::DocumentObject* obj) const override;

};

} // namespace TechDrawGui