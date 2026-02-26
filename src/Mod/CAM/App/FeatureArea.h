// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2017 Zheng Lei <realthunder.dev@gmail.com>
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

#include <App/DocumentObject.h>
#include <App/FeaturePython.h>
#include <App/PropertyUnits.h>
#include "Mod/Part/App/PartFeature.h"

#include "Area.h"


namespace Path
{

class PathExport FeatureArea: public Part::Feature
{
    PROPERTY_HEADER_WITH_OVERRIDE(Path::FeatureArea);

public:
    /// Constructor
    FeatureArea();
    ~FeatureArea() override;

    Area& getArea();
    const std::vector<TopoDS_Shape>& getShapes();

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override
    {
        return "PathGui::ViewProviderArea";
    }
    App::DocumentObjectExecReturn* execute() override;
    short mustExecute() const override;
    PyObject* getPyObject() override;

    App::PropertyLinkList Sources;
    Part::PropertyPartShape WorkPlane;

    PARAM_PROP_DECLARE(AREA_PARAMS_ALL)

    void setWorkPlane(const TopoDS_Shape& shape)
    {
        WorkPlane.setValue(shape);
        myArea.setPlane(shape);
    }

private:
    Area myArea;
    std::vector<TopoDS_Shape> myShapes;
    bool myInited;
};

using FeatureAreaPython = App::FeaturePythonT<FeatureArea>;

class PathExport FeatureAreaView: public Part::Feature
{
    PROPERTY_HEADER_WITH_OVERRIDE(Path::FeatureAreaView);

public:
    /// Constructor
    FeatureAreaView();

    std::list<TopoDS_Shape> getShapes();

    const char* getViewProviderName() const override
    {
        return "PathGui::ViewProviderAreaView";
    }
    App::DocumentObjectExecReturn* execute() override;

    App::PropertyLink Source;
    App::PropertyInteger SectionIndex;
    App::PropertyInteger SectionCount;
};

using FeatureAreaViewPython = App::FeaturePythonT<FeatureAreaView>;

}  // namespace Path
