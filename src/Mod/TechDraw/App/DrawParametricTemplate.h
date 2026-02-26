// SPDX-FileCopyrightText: 2014 Luke Parry <l.parry@warwick.ac.uk>
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
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawTemplate.h"
#include "Geometry.h"


namespace TechDraw
{
    class BaseGeom;
}

//TODO: DrawParametricTemplate class is obsolete

namespace TechDraw
{

class TechDrawExport DrawParametricTemplate: public TechDraw::DrawTemplate
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawParametricTemplate);

public:
    DrawParametricTemplate(); /// Constructor
    ~DrawParametricTemplate() override;

    App::PropertyFile Template;

    /** @name methods override Feature */
    //@{
    /// recalculate the Feature
    App::DocumentObjectExecReturn *execute() override;
    //@}


    short mustExecute() const override;

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override {
        return "TechDrawGui::ViewProviderTemplate";
    }

    // from base class
    PyObject *getPyObject() override;
    unsigned int getMemSize() const override;

public:
    std::vector<TechDraw::BaseGeomPtr> getGeometry() { return geom; }
    int clearGeometry();

    // Template Drawing Methods
    int drawLine(double x1, double y1, double x2, double y2);

    double getHeight() const override;
    double getWidth() const override;

protected:
    void onChanged(const App::Property* prop) override;

protected:
    std::vector<TechDraw::BaseGeomPtr> geom;

private:
    static const char* OrientationEnums[];
};

using DrawParametricTemplatePython = App::FeaturePythonT<DrawParametricTemplate>;

} //namespace TechDraw