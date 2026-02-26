// SPDX-FileCopyrightText: 2024 Ondsel <development@ondsel.com>
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

#include "ViewProviderDocumentObject.h"
#include "Dialogs/DlgAddProperty.h"

namespace Gui
{

/** View provider associated with an App::VarSet
 */
class GuiExport ViewProviderVarSet: public ViewProviderDocumentObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderVarSet);

public:
    ViewProviderVarSet();
    ~ViewProviderVarSet() override = default;

    bool isShow() const override
    {
        return true;
    }

    bool doubleClicked() override;

    void onFinished(int);

private:
    std::unique_ptr<Dialog::DlgAddProperty> dialog;
};

}  // namespace Gui
