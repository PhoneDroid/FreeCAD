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

#include "gtest/gtest.h"
#include <src/App/InitApplication.h>
#include <Mod/Mesh/App/MeshFeature.h>

class MeshFeatureTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }

    void SetUp() override
    {}

    void TearDown() override
    {}
};

// NOLINTBEGIN(cppcoreguidelines-*,readability-*)
TEST_F(MeshFeatureTest, getElementTypes)
{
    Mesh::Feature mf;
    std::vector<const char*> types = mf.getElementTypes();

    EXPECT_EQ(types.size(), 2);
    EXPECT_STREQ(types[0], "Mesh");
    EXPECT_STREQ(types[1], "Segment");
}

TEST_F(MeshFeatureTest, getComplexElementTypes)
{
    Mesh::MeshObject mf;
    std::vector<const char*> types = mf.getElementTypes();

    EXPECT_EQ(types.size(), 2);
    EXPECT_STREQ(types[0], "Mesh");
    EXPECT_STREQ(types[1], "Segment");
}
// NOLINTEND(cppcoreguidelines-*,readability-*)
