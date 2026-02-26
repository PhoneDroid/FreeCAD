// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2015 Stefan Tröger <stefantroeger@gmx.net>
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

class SoCoordinate3;
class SoFont;
class SoTranslation;

namespace Gui
{
class SoAutoZoomTranslation;
}

namespace PartDesignGui
{

class PartDesignGuiExport ViewProviderDatumCoordinateSystem: public PartDesignGui::ViewProviderDatum
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesignGui::ViewProviderDatumCoordinateSystem);

public:
    App::PropertyFloatConstraint Zoom;
    App::PropertyIntegerConstraint FontSize;
    App::PropertyBool ShowLabel;

    /// Constructor
    ViewProviderDatumCoordinateSystem();
    ~ViewProviderDatumCoordinateSystem() override;

    void attach(App::DocumentObject* obj) override;
    void updateData(const App::Property*) override;
    void onChanged(const App::Property*) override;

    void setExtents(Base::BoundBox3d bbox) override;

    SoDetail* getDetail(const char* subelement) const override;
    std::string getElement(const SoDetail* detail) const override;

private:
    void setupLabels();

private:
    SoCoordinate3* coord;
    SoTranslation* axisLabelXTrans;
    SoTranslation* axisLabelXToYTrans;
    SoTranslation* axisLabelYToZTrans;
    SoFont* font;
    SoSwitch* labelSwitch;
    Gui::SoAutoZoomTranslation* autoZoom;
};

}  // namespace PartDesignGui
