// SPDX-FileCopyrightText: 2014 Luke Parry <l.parry@warwick.ac.uk>
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

#include <Mod/TechDraw/App/DrawProjGroupItem.h>

#include "ViewProviderViewPart.h"


namespace TechDrawGui {


class TechDrawGuiExport ViewProviderProjGroupItem: public ViewProviderViewPart
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderProjGroupItem);

public:

     ViewProviderProjGroupItem();
     ~ViewProviderProjGroupItem() override;

    bool useNewSelectionModel() const override {return false;}

    /// Is called by the tree if the user double click on the object
    bool doubleClicked() override;
    void setupContextMenu(QMenu*, QObject*, const char*) override;
    void updateData(const App::Property*) override;
    void updateIcon();

    TechDraw::DrawProjGroupItem* getViewObject() const override;
    TechDraw::DrawProjGroupItem* getObject() const;
    void unsetEdit(int ModNum) override;
    bool onDelete(const std::vector<std::string> &) override;
    bool canDelete(App::DocumentObject* obj) const override;

protected:
    bool setEdit(int ModNum) override;

};

} // namespace TechDrawGui