// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2004 Jürgen Riegel <juergen.riegel@web.de>
// SPDX-FileCopyrightText: 2012 Luke Parry <l.parry@warwick.ac.uk>
// SPDX-FileCopyrightText: 2019 Franck Jullien <franck.jullien@gmail.com>

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
#include <Mod/TechDraw/App/DrawViewBalloon.h>

#include "ViewProviderDrawingView.h"


namespace TechDrawGui {


class TechDrawGuiExport ViewProviderBalloon : public ViewProviderDrawingView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderBalloon);

public:
    /// constructor
    ViewProviderBalloon();
    /// destructor
    ~ViewProviderBalloon() override = default;

    App::PropertyFont   Font;
    App::PropertyLength Fontsize;
    App::PropertyLength LineWidth;
    App::PropertyBool   LineVisible;
    App::PropertyColor  Color;

    bool useNewSelectionModel() const override {return false;}
    void updateData(const App::Property* prop) override;
    void onChanged(const App::Property* prop) override;
    void setupContextMenu(QMenu* menu, QObject* receiver, const char* member) override;
    bool setEdit(int ModNum) override;
    bool doubleClicked() override;
    bool canDelete(App::DocumentObject* obj) const override;
    bool onDelete(const std::vector<std::string> & parms) override;

    TechDraw::DrawViewBalloon* getViewObject() const override;

    std::vector<App::DocumentObject*> claimChildren() const override;

protected:
    void handleChangedPropertyType(Base::XMLReader &reader, const char *TypeName, App::Property * prop) override;
};

} // namespace TechDrawGui