// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2016 York van Havre <yorik@uncreated.net>

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

#include <App/DocumentObject.h>
#include <App/PropertyLinks.h>
#include <Base/BoundBox.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawViewSymbol.h"


namespace TechDraw
{

class TechDrawExport DrawViewArch : public TechDraw::DrawViewSymbol
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawViewArch);

public:
    /// Constructor
    DrawViewArch();
    ~DrawViewArch() override = default;

    App::PropertyLink         Source;
    App::PropertyBool         AllOn;
    App::PropertyEnumeration  RenderMode; // "Wireframe", "Solid"
    App::PropertyBool         FillSpaces;
    App::PropertyBool         ShowHidden;
    App::PropertyBool         ShowFill;
    App::PropertyFloat        LineWidth;
    App::PropertyFloat        FontSize;
    App::PropertyFloat        CutLineWidth;
    App::PropertyBool         JoinArch;
    App::PropertyFloat        LineSpacing;


    /** @name methods override Feature */
    //@{
    /// recalculate the Feature
    App::DocumentObjectExecReturn *execute() override;
    //@}

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override {
        return "TechDrawGui::ViewProviderArch";
    }

    short mustExecute() const override;


protected:
/*    virtual void onChanged(const App::Property* prop) override;*/
    Base::BoundBox3d bbox;
    std::string getSVGHead();
    std::string getSVGTail();

private:
    static const char* RenderModeEnums[];
};

} //namespace TechDraw