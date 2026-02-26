// SPDX-FileCopyrightText: 2022 Uwe Stöhr <uwestoehr@lyx.org>
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


// clang-format off
#include "ViewProviderFemPostPipeline.h"
// inclusion of the generated files (generated out of ViewProviderFemPostPipelinePy.xml)
#include "ViewProviderFemPostPipelinePy.h"
#include "ViewProviderFemPostPipelinePy.cpp"
// clang-format on


using namespace FemGui;

// returns a string which represents the object e.g. when printed in python
std::string ViewProviderFemPostPipelinePy::representation() const
{
    return {"<ViewProviderFemPostPipeline object>"};
}

PyObject* ViewProviderFemPostPipelinePy::updateColorBars(PyObject* args)
{
    if (!PyArg_ParseTuple(args, "")) {
        return nullptr;
    }

    this->getViewProviderFemPostPipelinePtr()->updateColorBars();

    Py_Return;
}

PyObject* ViewProviderFemPostPipelinePy::transformField(PyObject* args)
{
    char* FieldName;
    double FieldFactor;

    if (!PyArg_ParseTuple(args, "sd", &FieldName, &FieldFactor)) {
        return nullptr;
    }

    this->getViewProviderFemPostPipelinePtr()->transformField(FieldName, FieldFactor);

    Py_Return;
}

PyObject* ViewProviderFemPostPipelinePy::getCustomAttributes(const char* /*attr*/) const
{
    return nullptr;
}

int ViewProviderFemPostPipelinePy::setCustomAttributes(const char* /*attr*/, PyObject* /*obj*/)
{
    return 0;
}
