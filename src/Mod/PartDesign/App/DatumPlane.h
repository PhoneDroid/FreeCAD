// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2013 Jan Rheinländer <jrheinlaender@users.sourceforge.net>
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

#include <Mod/Part/App/DatumFeature.h>
#include <Mod/PartDesign/PartDesignGlobal.h>
#include <App/PropertyUnits.h>

namespace PartDesign
{

class PartDesignExport Plane: public Part::Datum
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesign::Plane);

public:
    Plane();
    ~Plane() override;

    App::PropertyEnumeration ResizeMode;
    App::PropertyLength Length;
    App::PropertyLength Width;

    void onChanged(const App::Property* prop) override;
    const char* getViewProviderName() const override
    {
        return "PartDesignGui::ViewProviderDatumPlane";
    }

    Base::Vector3d getNormal();

protected:
    void Restore(Base::XMLReader& reader) override;

private:
    static const char* ResizeModeEnums[];
};

}  // namespace PartDesign
