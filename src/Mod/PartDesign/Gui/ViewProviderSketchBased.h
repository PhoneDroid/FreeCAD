// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2015 Alexander Golubev <fatzer2@gmail.com>
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

#include "ViewProvider.h"

#include <Gui/ParamHandler.h>
#include <Gui/Inventor/SoToggleSwitch.h>

namespace PartDesignGui
{

/**
 * A common base class for Sketch based view providers
 */
class PartDesignGuiExport ViewProviderSketchBased: public ViewProvider
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesignGui::ViewProviderSketchBased);

public:
    /// constructor
    ViewProviderSketchBased();
    /// destructor
    ~ViewProviderSketchBased() override;

    /// grouping handling
    std::vector<App::DocumentObject*> claimChildren() const override;

    void attach(App::DocumentObject* pcObject) override;

protected:
    void updateData(const App::Property* prop) override;
    void updatePreview() override;

private:
    void updateProfileShape();

    Gui::CoinPtr<SoToggleSwitch> pcProfileToggle;
    Gui::CoinPtr<PartGui::SoPreviewShape> pcProfileShape;

    ParameterGrp::handle hGrp = App::GetApplication().GetParameterGroupByPath(
        "User parameter:BaseApp/Preferences/Mod/PartDesign/Preview"
    );
    Gui::ParamHandlers handlers;
};

}  // namespace PartDesignGui
