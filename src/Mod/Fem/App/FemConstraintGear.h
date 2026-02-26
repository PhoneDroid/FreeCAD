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

#include "FemConstraintBearing.h"


namespace Fem
{

class FemExport ConstraintGear: public Fem::ConstraintBearing
{
    PROPERTY_HEADER_WITH_OVERRIDE(Fem::ConstraintGear);

public:
    /// Constructor
    ConstraintGear();

    App::PropertyFloat Diameter;
    App::PropertyFloat Force;
    App::PropertyFloat ForceAngle;
    App::PropertyLinkSub Direction;
    App::PropertyBool Reversed;
    // Read-only (calculated values). These trigger changes in the ViewProvider
    App::PropertyVector DirectionVector;

    /// recalculate the object
    App::DocumentObjectExecReturn* execute() override;

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override
    {
        return "FemGui::ViewProviderFemConstraintGear";
    }

protected:
    void onChanged(const App::Property* prop) override;

private:
    Base::Vector3d naturalDirectionVector;
};

}  // namespace Fem
