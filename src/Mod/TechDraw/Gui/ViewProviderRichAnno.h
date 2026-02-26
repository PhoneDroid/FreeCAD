// SPDX-FileCopyrightText: 2004 Jürgen Riegel <juergen.riegel@web.de>
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

#include <App/PropertyUnits.h>
#include <Mod/TechDraw/App/DrawRichAnno.h>

#include "ViewProviderDrawingView.h"


namespace TechDraw {
class DrawRichAnno;
}

namespace TechDrawGui {

class TechDrawGuiExport ViewProviderRichAnno : public ViewProviderDrawingView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderRichAnno);

public:
    /// constructor
    ViewProviderRichAnno();
    /// destructor
    ~ViewProviderRichAnno() override = default;

    App::PropertyLength      LineWidth;
    App::PropertyEnumeration LineStyle;
    App::PropertyColor       LineColor;

    bool useNewSelectionModel() const override {return false;}
    void updateData(const App::Property* prop) override;
    void onChanged(const App::Property* prop) override;
    bool onDelete(const std::vector<std::string>&) override;
    bool doubleClicked() override;
    bool canDelete(App::DocumentObject* obj) const override;
    bool setEdit(int ModNum) override;

    static const char* LineStyleEnums[];

    TechDraw::DrawRichAnno* getViewObject() const override;
    TechDraw::DrawRichAnno* getFeature()  const;

    /// Claim any views that have this as a parent
    std::vector<App::DocumentObject*> claimChildren() const override;


protected:
    Base::Color getDefLineColor();
    std::string getDefFont();
    double getDefFontSize();
    double getDefLineWeight();
    void handleChangedPropertyType(Base::XMLReader &reader,
                                   const char *TypeName,
                                   App::Property * prop) override;

private:
    static App::PropertyIntegerConstraint::Constraints LineStyleRange;

};

} // namespace TechDrawGui