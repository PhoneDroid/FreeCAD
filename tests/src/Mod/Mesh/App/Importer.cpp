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
#include <Base/FileInfo.h>
#include <Mod/Mesh/App/Core/IO/Reader3MF.h>
#include <Mod/Mesh/App/Core/IO/ReaderOBJ.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <zipios++/fcoll.h>

class ImporterTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        XERCES_CPP_NAMESPACE::XMLPlatformUtils::Initialize();
    }
};

// NOLINTBEGIN(cppcoreguidelines-*,readability-*)
TEST_F(ImporterTest, Test3MF)
{
    std::string file(DATADIR);
    file.append("/tests/mesh.3mf");

    MeshCore::Reader3MF reader(file);
    EXPECT_EQ(reader.Load(), true);

    std::vector<int> ids = reader.GetMeshIds();
    std::sort(ids.begin(), ids.end());

    EXPECT_EQ(ids.size(), 2);

    const MeshCore::MeshKernel& mesh1 = reader.GetMesh(ids[0]);
    EXPECT_EQ(mesh1.CountPoints(), 8);
    EXPECT_EQ(mesh1.CountEdges(), 18);
    EXPECT_EQ(mesh1.CountFacets(), 12);

    const MeshCore::MeshKernel& mesh2 = reader.GetMesh(ids[1]);
    EXPECT_EQ(mesh2.CountPoints(), 652);
    EXPECT_EQ(mesh2.CountEdges(), 1950);
    EXPECT_EQ(mesh2.CountFacets(), 1300);
}

TEST_F(ImporterTest, TestOBJ)
{
    std::string file(DATADIR);
    file.append("/tests/mesh.obj");

    MeshCore::MeshKernel kernel;
    MeshCore::ReaderOBJ reader(kernel, nullptr);
    EXPECT_EQ(reader.Load(file), true);

    EXPECT_EQ(kernel.CountPoints(), 8);
    EXPECT_EQ(kernel.CountFacets(), 12);
}
// NOLINTEND(cppcoreguidelines-*,readability-*)
