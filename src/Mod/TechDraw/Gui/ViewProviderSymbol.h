// SPDX-FileCopyrightText: 2004 Jürgen Riegel <juergen.riegel@web.de>
// SPDX-FileCopyrightText: 2012 Luke Parry <l.parry@warwick.ac.uk>
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

#include <Mod/TechDraw/App/DrawViewSymbol.h>

#include "ViewProviderDrawingView.h"


namespace TechDrawGui {

//NOLINTBEGIN
class TechDrawGuiExport ViewProviderSymbol : public ViewProviderDrawingView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderSymbol);
//NOLINTEND

public:
    /// constructor
    ViewProviderSymbol();
    /// destructor
    ~ViewProviderSymbol() override  = default ;

    App::PropertyBool LegacyScaling;

    bool useNewSelectionModel() const override {return false;}
    void updateData(const App::Property* prop) override;
    void onChanged(const App::Property* prop) override;

    TechDraw::DrawViewSymbol* getViewObject() const override;
};

//NOLINTBEGIN
class TechDrawGuiExport ViewProviderDraft : public ViewProviderSymbol
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderDraft);
//NOLINTEND

public:
    /// constructor
    ViewProviderDraft();
    /// destructor
    ~ViewProviderDraft() override = default ;
};


//NOLINTBEGIN
class TechDrawGuiExport ViewProviderArch : public ViewProviderSymbol
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderArch);
//NOLINTEND

public:
    /// constructor
    ViewProviderArch();
    /// destructor
    ~ViewProviderArch() override  = default ;
};

} // namespace TechDrawGui