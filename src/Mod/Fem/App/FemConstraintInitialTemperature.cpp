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


#include "FemConstraintInitialTemperature.h"


using namespace Fem;

PROPERTY_SOURCE(Fem::ConstraintInitialTemperature, Fem::Constraint)

ConstraintInitialTemperature::ConstraintInitialTemperature()
{
    ADD_PROPERTY(initialTemperature, (300.0));
    ADD_PROPERTY(EnableFinalTemperature, (false));
    ADD_PROPERTY(FinalTemperature, (300.0));
    ADD_PROPERTY_TYPE(
        EnableAmplitude,
        (false),
        "",
        (App::PropertyType)(App::Prop_None),
        "Amplitude of the final temperature field"
    );
    ADD_PROPERTY_TYPE(
        AmplitudeValues,
        (std::vector<std::string> {"0, 0", "1, 1"}),
        "",
        (App::PropertyType)(App::Prop_None),
        "Amplitude values"
    );
}

App::DocumentObjectExecReturn* ConstraintInitialTemperature::execute()
{
    return Constraint::execute();
}

const char* ConstraintInitialTemperature::getViewProviderName() const
{
    return "FemGui::ViewProviderFemConstraintInitialTemperature";
}

void ConstraintInitialTemperature::handleChangedPropertyType(
    Base::XMLReader& reader,
    const char* TypeName,
    App::Property* prop
)
{
    // property initialTemperature had App::PropertyFloat, was changed to App::PropertyTemperature
    if (prop == &initialTemperature && strcmp(TypeName, "App::PropertyFloat") == 0) {
        App::PropertyFloat initialTemperatureProperty;
        // restore the PropertyFloat to be able to set its value
        initialTemperatureProperty.Restore(reader);
        initialTemperature.setValue(initialTemperatureProperty.getValue());
    }
    else {
        Constraint::handleChangedPropertyType(reader, TypeName, prop);
    }
}

void ConstraintInitialTemperature::onChanged(const App::Property* prop)
{
    Constraint::onChanged(prop);
}
