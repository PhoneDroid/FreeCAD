// SPDX-FileCopyrightText: 2013 Luke Parry <l.parry@warwick.ac.uk>
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

#include <Mod/TechDraw/App/DrawProjGroup.h>

#include "ViewProviderDrawingView.h"


namespace TechDrawGui {

class TechDrawGuiExport ViewProviderProjGroup : public ViewProviderDrawingView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderProjGroup);

public:

     ViewProviderProjGroup();  /// constructor
     ~ViewProviderProjGroup() override = default; /// destructor

    bool useNewSelectionModel() const override {return false;}

    /// Claim all the views for the group
    std::vector<App::DocumentObject*> claimChildren() const override;

    /// Is called by the tree if the user double click on the object
    bool doubleClicked() override;

    TechDraw::DrawProjGroup* getObject() const;
    TechDraw::DrawProjGroup* getViewObject() const override;
    bool onDelete(const std::vector<std::string> &parms) override;
    bool canDelete(App::DocumentObject* obj) const override;

    void regroupSubViews();
    void updateData(const App::Property* prop) override;
    void onChangeAutoDistribute();


protected:
    bool setEdit(int ModNum) override;

};

} // namespace TechDrawGui