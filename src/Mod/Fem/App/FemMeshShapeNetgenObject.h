// SPDX-FileCopyrightText: 2013 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#include "FemMeshShapeObject.h"
#include <App/PropertyStandard.h>

namespace Fem
{

class FemExport FemMeshShapeNetgenObject: public FemMeshShapeBaseObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(Fem::FemMeshShapeNetgenObject);

public:
    /// Constructor
    FemMeshShapeNetgenObject();
    ~FemMeshShapeNetgenObject() override;

    App::PropertyFloat MaxSize;
    App::PropertyFloat MinSize;
    App::PropertyBool SecondOrder;
    App::PropertyEnumeration Fineness;
    App::PropertyFloat GrowthRate;
    App::PropertyInteger NbSegsPerEdge;
    App::PropertyInteger NbSegsPerRadius;
    App::PropertyBool Optimize;

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override
    {
        return "FemGui::ViewProviderFemMeshShapeNetgen";
    }
    App::DocumentObjectExecReturn* execute() override;

    // virtual short mustExecute(void) const;
    // virtual PyObject *getPyObject(void);

    // App::PropertyLink Shape;

protected:
    /// get called by the container when a property has changed
    // virtual void onChanged (const App::Property* prop);
};

}  // namespace Fem
