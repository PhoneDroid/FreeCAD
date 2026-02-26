// SPDX-FileCopyrightText: 2004 Jürgen Riegel <juergen.riegel@web.de>
// SPDX-FileCopyrightText: 2017 WandererFan <wandererfan@gmail.com>
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

#include <App/PropertyStandard.h>
#include <Gui/ViewProviderDocumentObject.h>

namespace App {
    class DocumentObject;
}

namespace TechDraw{
    class DrawGeomHatch;
}

namespace TechDrawGui {


class TechDrawGuiExport ViewProviderGeomHatch : public Gui::ViewProviderDocumentObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderGeomHatch);

public:
    /// constructor
    ViewProviderGeomHatch();
    /// destructor
    ~ViewProviderGeomHatch() override;

    App::PropertyFloat       WeightPattern;
    App::PropertyColor       ColorPattern;

    void updateData(const App::Property*) override;
    void onChanged(const App::Property *prop) override;
    bool setEdit(int ModNum) override;
    bool doubleClicked(void) override;
    bool useNewSelectionModel(void) const override {return false;}
    void updateGraphic(void);
    void getParameters(void);
    bool canDelete(App::DocumentObject* obj) const override;

    TechDraw::DrawGeomHatch* getViewObject() const;

    Gui::MDIView *getMDIView() const override;
};

} // namespace TechDrawGui