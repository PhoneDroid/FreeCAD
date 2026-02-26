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

#include <Mod/TechDraw/App/DrawViewAnnotation.h>

#include "ViewProviderDrawingView.h"


namespace TechDrawGui
{


class TechDrawGuiExport ViewProviderAnnotation: public ViewProviderDrawingView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDrawGui::ViewProviderAnnotation);

public:
    /// constructor
    ViewProviderAnnotation();
    /// destructor
    ~ViewProviderAnnotation() override;

    bool useNewSelectionModel() const override { return false; }
    void updateData(const App::Property*) override;

    std::vector<App::DocumentObject*> claimChildren(void) const override;

    TechDraw::DrawViewAnnotation* getViewObject() const override;

    bool doubleClicked() override;
    bool setEdit(int ModNum) override;
};

}// namespace TechDrawGui