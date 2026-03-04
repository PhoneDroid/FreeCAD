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

#include <src/App/InitApplication.h>
#include <App/Document.h>
#include <Mod/Measure/App/MeasureDistance.h>
#include <Mod/Part/App/PartFeature.h>
#include <gtest/gtest.h>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <gp_Circ.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>

class MeasureDistance: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }

    void SetUp() override
    {
        document = App::GetApplication().newDocument("Measure");
    }

    void TearDown() override
    {
        App::GetApplication().closeDocument(document->getName());
    }

    App::Document* getDocument() const
    {
        return document;
    }

    TopoDS_Edge makeCircle(const gp_Pnt& pnt) const
    {
        gp_Circ circle;
        circle.SetLocation(pnt);
        circle.SetRadius(1.0);
        BRepBuilderAPI_MakeEdge mkEdge(circle);
        return mkEdge.Edge();
    }

private:
    App::Document* document {};
};

// NOLINTBEGIN
TEST_F(MeasureDistance, testCircleCircle)
{
    App::Document* doc = getDocument();
    auto p1 = doc->addObject<Part::Feature>("Shape1");
    p1->Shape.setValue(makeCircle(gp_Pnt(0.0, 0.0, 0.0)));
    auto p2 = doc->addObject<Part::Feature>("Shape2");
    p2->Shape.setValue(makeCircle(gp_Pnt(3.0, 4.0, 0.0)));

    auto md = doc->addObject<Measure::MeasureDistance>("Distance");
    md->Element1.setValue(p1, {"Edge1"});
    md->Element2.setValue(p2, {"Edge1"});

    doc->recompute();

    EXPECT_DOUBLE_EQ(md->Distance.getValue(), 5.0);
    EXPECT_DOUBLE_EQ(md->DistanceX.getValue(), 3.0);
    EXPECT_DOUBLE_EQ(md->DistanceY.getValue(), 4.0);
    EXPECT_DOUBLE_EQ(md->DistanceZ.getValue(), 0.0);
    EXPECT_EQ(md->Position1.getValue(), Base::Vector3d(0.0, 0.0, 0.0));
    EXPECT_EQ(md->Position2.getValue(), Base::Vector3d(3.0, 4.0, 0.0));
}
// NOLINTEND
