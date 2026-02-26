// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2023 Wanderer Fan <wandererfan@gmail.com>
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

#include <App/PropertyStandard.h>
#include <App/PropertyUnits.h>

#include <Mod/Part/PartGlobal.h>

#include "FaceMakerCheese.h"
#include "PartFeature.h"


namespace Part
{

class PartExport Scale: public Part::Feature
{
    PROPERTY_HEADER_WITH_OVERRIDE(Part::Scale);

public:
    Scale();

    App::PropertyLink Base;
    App::PropertyBool Uniform;
    App::PropertyFloat UniformScale;
    App::PropertyFloat XScale;
    App::PropertyFloat YScale;
    App::PropertyFloat ZScale;

    /**
     * @brief The ScaleParameters struct is supposed to be filled with final
     * scale parameters and be passed to scaleShape.
     */
    struct ScaleParameters
    {
        bool uniform {true};
        double uniformScale {1.0};
        double XScale {1.0};
        double YScale {1.0};
        double ZScale {1.0};
    };

    /** @name methods override feature */
    //@{
    /// recalculate the feature
    App::DocumentObjectExecReturn* execute() override;
    short mustExecute() const override;
    /// returns the type name of the view provider
    const char* getViewProviderName() const override
    {
        return "PartGui::ViewProviderScale";
    }
    //@}
    Scale::ScaleParameters computeFinalParameters();

    /**
     * @brief scaleShape powers the extrusion feature.
     * @param source: the shape to be scaled
     * @param params: scale parameters
     * @return result of scaling
     */
    static TopoShape scaleShape(const TopoShape& source, const ScaleParameters& params);
    static TopoShape uniformScale(const TopoShape& source, const double& factor);
    static TopoShape nonuniformScale(const TopoShape& source, const Scale::ScaleParameters& params);
};

}  // namespace Part
