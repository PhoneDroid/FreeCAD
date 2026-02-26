// SPDX-FileCopyrightText: 2015 Qingfeng Xia <FreeCAD@iesensor.com>
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

#include <App/FeaturePython.h>
#include <App/PropertyFile.h>
#include <Mod/Fem/FemGlobal.h>

namespace Fem
{
/// Father of all result data in a Fem Analysis
class FemExport FemSolverObject: public App::DocumentObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(Fem::FemSolverObject);

public:
    /// Constructor
    FemSolverObject();
    ~FemSolverObject() override;

    App::PropertyLinkList Results;
    App::PropertyPythonObject Tool;
    App::PropertyPath WorkingDirectory;
    // Attributes are implemented in the FemSolverObjectPython

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override
    {
        return "FemGui::ViewProviderSolver";
    }
    App::DocumentObjectExecReturn* execute() override
    {
        return App::DocumentObject::StdReturn;
    }
    short mustExecute() const override;
    PyObject* getPyObject() override;
};

using FemSolverObjectPython = App::FeaturePythonT<FemSolverObject>;

}  // namespace Fem
