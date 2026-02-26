// SPDX-FileCopyrightText: 2016 WandererFan <wandererfan@gmail.com>
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

#include <App/DocumentObject.h>
#include <App/FeaturePython.h>
#include <App/PropertyLinks.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawViewSymbol.h"


namespace TechDraw
{

class TechDrawExport DrawViewSpreadsheet : public TechDraw::DrawViewSymbol
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawViewSpreadsheet);

public:
    DrawViewSpreadsheet();
    ~DrawViewSpreadsheet() override;
    App::PropertyLink         Source;
    App::PropertyString       CellStart;
    App::PropertyString       CellEnd;
    App::PropertyFont         Font;
    App::PropertyColor        TextColor;
    App::PropertyFloat        LineWidth;
    App::PropertyFloat        TextSize;

    App::PropertyLink         Owner;

    App::DocumentObjectExecReturn *execute() override;
    short mustExecute() const override;

    App::PropertyLink *getOwnerProperty() override { return &Owner; }

    std::string getSheetImage();

    const char* getViewProviderName() const override {
        return "TechDrawGui::ViewProviderSpreadsheet";
    }

protected:
    void onChanged(const App::Property* prop) override;
    std::vector<std::string> getAvailColumns();
    std::string getSVGHead();
    std::string getSVGTail();
    int colInList(const std::vector<std::string>& list,
                   const std::string& toFind);

private:
};

using DrawViewSpreadsheetPython = App::FeaturePythonT<DrawViewSpreadsheet>;


} //namespace TechDraw