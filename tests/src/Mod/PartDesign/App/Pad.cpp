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
#include "src/App/InitApplication.h"

#include <App/Application.h>
#include <App/Document.h>
#include <Mod/Part/App/Geometry.h>
#include <Mod/PartDesign/App/Body.h>
#include <Mod/PartDesign/App/FeaturePad.h>
#include <Mod/Sketcher/App/SketchObject.h>

// NOLINTBEGIN(readability-magic-numbers,cppcoreguidelines-avoid-magic-numbers)

class PadTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }

    void SetUp() override
    {
        _doc = App::GetApplication().newDocument("Pad_test", "testUser");
        _body = _doc->addObject<PartDesign::Body>();
        _sketch = _doc->addObject<Sketcher::SketchObject>("Sketch");
        _body->addObject(_sketch);

        _sketch->AttachmentSupport.setValue(_doc->getObject("XY_Plane"), "");
        _sketch->MapMode.setValue("FlatFace");
        Part::GeomCircle circle;
        circle.setRadius(10.0);
        _sketch->addGeometry(&circle, false);
    }

    void TearDown() override
    {
        App::GetApplication().closeDocument(_doc->getName());
    }

    App::Document* getDocument() const
    {
        return _doc;
    }

    PartDesign::Body* getBody() const
    {
        return _body;
    }

    Sketcher::SketchObject* getSketch() const
    {
        return _sketch;
    }

private:
    App::Document* _doc = nullptr;
    PartDesign::Body* _body = nullptr;
    Sketcher::SketchObject* _sketch = nullptr;
};

TEST_F(PadTest, TestMidPlaneTwoLength)
{
    auto doc = getDocument();
    auto body = getBody();
    auto sketch = getSketch();

    doc->recompute();

    auto pad = doc->addObject<PartDesign::Pad>("Pad");
    body->addObject(pad);
    pad->Profile.setValue(sketch, {""});
    pad->Direction.setValue(0.0, 0.0, 1.0);
    pad->Midplane.setValue(true);
    pad->Length.setValue(10.0);
    pad->Length2.setValue(20.0);

    pad->SideType.setValue("Two sides");

    doc->recompute();

    auto bbox = pad->Shape.getBoundingBox();

    EXPECT_DOUBLE_EQ(bbox.MaxX, 10.0);
    EXPECT_DOUBLE_EQ(bbox.MinX, -10.0);
    EXPECT_DOUBLE_EQ(bbox.MaxY, 10.0);
    EXPECT_DOUBLE_EQ(bbox.MinY, -10.0);
    EXPECT_DOUBLE_EQ(bbox.MaxZ, 10.0);
    EXPECT_DOUBLE_EQ(bbox.MinZ, -20.0);
}

// NOLINTEND(readability-magic-numbers,cppcoreguidelines-avoid-magic-numbers)
