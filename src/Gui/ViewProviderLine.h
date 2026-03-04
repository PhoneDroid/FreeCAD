// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2012 Jürgen Riegel <juergen.riegel@web.de>
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

#include "ViewProviderDatum.h"

#include "ParamHandler.h"

class SoCoordinate3;
class SoTranslation;

namespace Gui
{
class SoFrameLabel;
}

namespace Gui
{

class GuiExport ViewProviderLine: public ViewProviderDatum
{
    PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderLine);

public:
    /// Constructor
    ViewProviderLine();
    ~ViewProviderLine() override;

    void attach(App::DocumentObject*) override;

private:
    void updateLineSize();

protected:
    CoinPtr<SoFrameLabel> pLabel;
    CoinPtr<SoCoordinate3> pCoords;
    CoinPtr<SoTranslation> pLabelTranslation;

    ParamHandlers handlers;
};

}  // namespace Gui
