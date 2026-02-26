// SPDX-FileCopyrightText: 2019 WandererFan <wandererfan@gmail.com>
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

#include <tuple>

#include <App/DocumentObject.h>
#include <App/PropertyLinks.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawViewDimension.h"


namespace TechDraw {

class TechDrawExport DrawViewDimExtent : public TechDraw::DrawViewDimension
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawViewDimExtent);

public:
    /// Constructor
    DrawViewDimExtent();
    ~DrawViewDimExtent() override = default;

    App::PropertyLinkSubList       Source;                       //DrawViewPart & SubElements(Edges)
                                                                 //Cosmetic End points are stored in DVD::References2d
    App::PropertyLinkSubList       Source3d;                     //Part::Feature & SubElements  TBI
    App::PropertyInteger           DirExtent;                    //Horizontal, Vertical, TBD
    App::PropertyStringList        CosmeticTags;                 //id of cosmetic end points.  obsolete!

    App::DocumentObjectExecReturn *execute() override;

    RefType getRefType() const override { return RefType::extent; }

    PyObject *getPyObject() override;

protected:
    virtual pointPair getPointsExtent(ReferenceVector references);
    bool checkReferences2D() const override;

private:
};

} //namespace TechDraw