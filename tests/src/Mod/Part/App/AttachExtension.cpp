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

#include <src/App/InitApplication.h>
#include <App/Document.h>
#include <Mod/Part/App/PrimitiveFeature.h>


class AttachExtensionTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }

    void SetUp() override
    {
        _docName = App::GetApplication().getUniqueDocumentName("test");
        _doc = App::GetApplication().newDocument(_docName.c_str(), "testUser");
    }

    void TearDown() override
    {
        App::GetApplication().closeDocument(_docName.c_str());
    }

    App::Document* getDocument() const
    {
        return _doc;
    }

private:
    std::string _docName;
    App::Document* _doc = nullptr;
};

TEST_F(AttachExtensionTest, testPlanePlane)
{
    auto plane1 = getDocument()->addObject<Part::Plane>("Plane1");
    auto plane2 = getDocument()->addObject<Part::Plane>("Plane2");

    ASSERT_TRUE(plane1);
    ASSERT_TRUE(plane2);

    getDocument()->recompute();

    plane2->MapReversed.setValue(false);
    plane2->AttachmentSupport.setValue(plane1);
    plane2->MapPathParameter.setValue(0.0);
    plane2->MapMode.setValue("FlatFace");

    getDocument()->recompute();
    EXPECT_TRUE(true);
}

TEST_F(AttachExtensionTest, testAttacherEngineType)
{
    auto plane = getDocument()->addObject<Part::Plane>("Plane");
    EXPECT_STREQ(plane->AttacherType.getValue(), "Attacher::AttachEngine3D");
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine 3D");

    plane->AttacherEngine.setValue(1L);
    EXPECT_STREQ(plane->AttacherType.getValue(), "Attacher::AttachEnginePlane");
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine Plane");

    plane->AttacherEngine.setValue(2L);
    EXPECT_STREQ(plane->AttacherType.getValue(), "Attacher::AttachEngineLine");
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine Line");

    plane->AttacherEngine.setValue(3L);
    EXPECT_STREQ(plane->AttacherType.getValue(), "Attacher::AttachEnginePoint");
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine Point");
}

TEST_F(AttachExtensionTest, testAttacherTypeEngine)
{
    auto plane = getDocument()->addObject<Part::Plane>("Plane");
    EXPECT_STREQ(plane->AttacherType.getValue(), "Attacher::AttachEngine3D");
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine 3D");

    plane->AttacherType.setValue("Attacher::AttachEnginePlane");
    plane->onExtendedDocumentRestored();
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine Plane");

    plane->AttacherType.setValue("Attacher::AttachEngineLine");
    plane->onExtendedDocumentRestored();
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine Line");

    plane->AttacherType.setValue("Attacher::AttachEnginePoint");
    plane->onExtendedDocumentRestored();
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine Point");

    plane->AttacherType.setValue("Attacher::AttachEngine3D");
    plane->onExtendedDocumentRestored();
    EXPECT_STREQ(plane->AttacherEngine.getValueAsString(), "Engine 3D");
}
