// SPDX-License-Identifier: LGPL-2.1-or-later
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

#include <gtest/gtest.h>

#include <FCConfig.h>


#include <App/Application.h>
#include <App/Document.h>
#include <App/Expression.h>
#include <App/ObjectIdentifier.h>
#include <Mod/Sketcher/App/GeoEnum.h>
#include <Mod/Sketcher/App/SketchObject.h>


class SketchObjectTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite();
    void SetUp() override;
    void TearDown() override;
    Sketcher::SketchObject* getObject();

private:
    // TODO: use shared_ptr or something else here?
    Sketcher::SketchObject* _sketchobj;
    std::string _docName;
    std::vector<const char*>
        allowedTypes {"Vertex", "Edge", "ExternalEdge", "H_Axis", "V_Axis", "RootPoint"};
};

namespace SketcherTestHelpers
{

using namespace Sketcher;

void setupLineSegment(Part::GeomLineSegment& lineSeg);

void setupCircle(Part::GeomCircle& circle);

void setupArcOfCircle(Part::GeomArcOfCircle& arcOfCircle);

void setupEllipse(Part::GeomEllipse& ellipse);

void setupArcOfHyperbola(Part::GeomArcOfHyperbola& arcOfHyperbola);

void setupArcOfParabola(Part::GeomArcOfParabola& aop);

std::unique_ptr<Part::GeomBSplineCurve> createTypicalNonPeriodicBSpline();

std::unique_ptr<Part::GeomBSplineCurve> createTypicalPeriodicBSpline();

int countConstraintsOfType(const Sketcher::SketchObject* obj, const Sketcher::ConstraintType cType);

// Get point at the parameter after scaling the range to [0, 1].
Base::Vector3d getPointAtNormalizedParameter(const Part::GeomCurve& curve, double param);

// TODO: How to set up B-splines here?
// It's not straightforward to change everything from a "default" one.
}  // namespace SketcherTestHelpers
