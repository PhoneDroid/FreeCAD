// SPDX-FileCopyrightText: 2024 Stefan Tröger <stefantroeger@gmx.net>
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


#include "FemPostFilter.h"
#include "FemPostGroupExtension.h"

#include <vtkSmartPointer.h>
#include <vtkAppendFilter.h>
#include <vtkPassThrough.h>


namespace Fem
{

class FemExport FemPostBranchFilter: public Fem::FemPostFilter, public FemPostGroupExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(Fem::FemPostBranchFilter);

public:
    /// Constructor
    FemPostBranchFilter();

    App::PropertyEnumeration Output;


    short mustExecute() const override;
    PyObject* getPyObject() override;

    const char* getViewProviderName() const override
    {
        return "FemGui::ViewProviderFemPostBranchFilter";
    }

    // Branch handling
    void filterChanged(FemPostFilter* filter) override;
    void filterPipelineChanged(FemPostFilter* filter) override;

protected:
    void onChanged(const App::Property* prop) override;

private:
    static const char* OutputEnums[];

    void setupPipeline();

    vtkSmartPointer<vtkAppendFilter> m_append;
    vtkSmartPointer<vtkPassThrough> m_passthrough;
};

}  // namespace Fem
