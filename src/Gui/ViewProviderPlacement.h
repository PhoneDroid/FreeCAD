// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2012 Jürgen Riegel <juergen.riegel@web.de>
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

#include "AxisOrigin.h"
#include "ViewProviderGeometryObject.h"
#include "ViewProviderFeaturePython.h"


class SoFontStyle;
class SoText2;
class SoBaseColor;
class SoTranslation;
class SoCoordinate3;
class SoIndexedLineSet;
class SoEventCallback;
class SoMaterial;

namespace Gui
{

class GuiExport ViewProviderPlacement: public ViewProviderGeometryObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderPlacement);

public:
    /// Constructor
    ViewProviderPlacement();
    ~ViewProviderPlacement() override;

    void attach(App::DocumentObject*) override;
    void updateData(const App::Property*) override;
    std::vector<std::string> getDisplayModes() const override;
    void setDisplayMode(const char* ModeName) override;

    /// indicates if the ViewProvider use the new Selection model
    bool useNewSelectionModel() const override
    {
        return true;
    }
    /// indicates if the ViewProvider can be selected
    bool isSelectable() const override;

    bool getElementPicked(const SoPickedPoint* pp, std::string& subname) const override;
    bool getDetailPath(const char*, SoFullPath*, bool, SoDetail*&) const override;

protected:
    void onChanged(const App::Property* prop) override;
};

using ViewProviderPlacementPython = ViewProviderFeaturePythonT<ViewProviderPlacement>;

}  // namespace Gui
