// SPDX-FileCopyrightText: 2015 FreeCAD Developers
// SPDX-FileCopyrightText: Michael Hindley <hindlemp@eskom.co.za>
// SPDX-FileCopyrightText: Ruan Olwagen <olwager@eskom.co.za>
// SPDX-FileCopyrightText: Oswald van Ginkel <vginkeo@eskom.co.za>
// SPDX-FileNotice: Part of the FreeCAD project.

// Based on Force constraint by Jan Rheinländer

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

#include "FemConstraint.h"


namespace Fem
{

class FemExport ConstraintDisplacement: public Fem::Constraint
{
    PROPERTY_HEADER_WITH_OVERRIDE(Fem::ConstraintDisplacement);

public:
    /// Constructor
    ConstraintDisplacement();

    App::PropertyBool EnableAmplitude;
    App::PropertyStringList AmplitudeValues;

    // Displacement parameters
    App::PropertyDistance xDisplacement;
    App::PropertyDistance yDisplacement;
    App::PropertyDistance zDisplacement;
    App::PropertyAngle xRotation;
    App::PropertyAngle yRotation;
    App::PropertyAngle zRotation;
    App::PropertyString xDisplacementFormula;
    App::PropertyString yDisplacementFormula;
    App::PropertyString zDisplacementFormula;
    App::PropertyBool xFree;
    App::PropertyBool yFree;
    App::PropertyBool zFree;
    App::PropertyBool rotxFree;
    App::PropertyBool rotyFree;
    App::PropertyBool rotzFree;
    App::PropertyBool hasXFormula;
    App::PropertyBool hasYFormula;
    App::PropertyBool hasZFormula;
    App::PropertyBool useFlowSurfaceForce;

    /// recalculate the object
    App::DocumentObjectExecReturn* execute() override;

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override;

protected:
    void handleChangedPropertyType(
        Base::XMLReader& reader,
        const char* TypeName,
        App::Property* prop
    ) override;
    void onChanged(const App::Property* prop) override;
};

}  // namespace Fem
