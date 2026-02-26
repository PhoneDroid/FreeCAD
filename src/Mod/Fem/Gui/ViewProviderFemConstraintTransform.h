// SPDX-FileCopyrightText: 2015 FreeCAD Developers
// SPDX-FileCopyrightText: Michael Hindley <hindlemp@eskom.co.za>
// SPDX-FileCopyrightText: Ruan Olwagen <olwager@eskom.co.za>
// SPDX-FileCopyrightText: Oswald van Ginkel <vginkeo@eskom.co.za>
// SPDX-FileCopyrightText: Ofentse Kgoa <kgoaot@eskom.co.za>
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

#include "ViewProviderFemConstraint.h"

namespace FemGui
{

class FemGuiExport ViewProviderFemConstraintTransform: public FemGui::ViewProviderFemConstraint
{
    PROPERTY_HEADER_WITH_OVERRIDE(FemGui::ViewProviderFemConstraintTransform);

public:
    ViewProviderFemConstraintTransform();
    ~ViewProviderFemConstraintTransform() override;
    void updateData(const App::Property*) override;

protected:
    bool setEdit(int ModNum) override;
    void transformSymbol(
        const Base::Vector3d& point,
        const Base::Vector3d& normal,
        SbMatrix& mat
    ) const override;
    void transformExtraSymbol() const override;
};

}  // namespace FemGui
