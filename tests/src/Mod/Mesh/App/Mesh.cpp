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
#include <Mod/Mesh/App/Mesh.h>
#include <Mod/Mesh/App/Core/Grid.h>

#include <src/App/InitApplication.h>

class MeshTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }
};

// NOLINTBEGIN(cppcoreguidelines-*,readability-*)
TEST_F(MeshTest, TestDefault)
{
    MeshCore::MeshKernel kernel;
    Base::Vector3f p1 {0, 0, 0};
    Base::Vector3f p2 {0, 0, 1};
    Base::Vector3f p3 {0, 1, 0};
    kernel.AddFacet(MeshCore::MeshGeomFacet(p1, p2, p3));

    EXPECT_EQ(kernel.CountPoints(), 3);
    EXPECT_EQ(kernel.CountEdges(), 3);
    EXPECT_EQ(kernel.CountFacets(), 1);
}

TEST_F(MeshTest, TestGrid1OfPlanarMesh)
{
    MeshCore::MeshKernel kernel;
    Base::Vector3f p1 {0, 0, 0};
    Base::Vector3f p2 {1, 0, 0};
    Base::Vector3f p3 {0, 1, 0};
    Base::Vector3f p4 {1, 1, 0};
    kernel.AddFacet(MeshCore::MeshGeomFacet(p1, p2, p3));
    kernel.AddFacet(MeshCore::MeshGeomFacet(p3, p2, p4));

    MeshCore::MeshFacetGrid grid(kernel, 10);
    unsigned long countX {};
    unsigned long countY {};
    unsigned long countZ {};
    grid.GetCtGrids(countX, countY, countZ);
    EXPECT_EQ(countX, 1);
    EXPECT_EQ(countY, 1);
    EXPECT_EQ(countZ, 1);
}

TEST_F(MeshTest, TestGrid2OfPlanarMesh)
{
    MeshCore::MeshKernel kernel;
    Base::Vector3f p1 {0, 0, 0};
    Base::Vector3f p2 {1, 0, 0};
    Base::Vector3f p3 {0, 1, 0};
    Base::Vector3f p4 {1, 1, 0};
    kernel.AddFacet(MeshCore::MeshGeomFacet(p1, p2, p3));
    kernel.AddFacet(MeshCore::MeshGeomFacet(p3, p2, p4));

    MeshCore::MeshFacetGrid grid(kernel);
    unsigned long countX {};
    unsigned long countY {};
    unsigned long countZ {};
    grid.GetCtGrids(countX, countY, countZ);
    EXPECT_EQ(countX, 1);
    EXPECT_EQ(countY, 1);
    EXPECT_EQ(countZ, 1);
}

TEST_F(MeshTest, TestGrid1OfAlmostPlanarMesh)
{
    MeshCore::MeshKernel kernel;
    Base::Vector3f p1 {0, 0, 0};
    Base::Vector3f p2 {1, 0, 0};
    Base::Vector3f p3 {0, 1, 0};
    Base::Vector3f p4 {1, 1, 1.0e-18F};
    kernel.AddFacet(MeshCore::MeshGeomFacet(p1, p2, p3));
    kernel.AddFacet(MeshCore::MeshGeomFacet(p3, p2, p4));

    MeshCore::MeshFacetGrid grid(kernel, 10);
    unsigned long countX {};
    unsigned long countY {};
    unsigned long countZ {};
    grid.GetCtGrids(countX, countY, countZ);
    EXPECT_EQ(countX, 1);
    EXPECT_EQ(countY, 1);
    EXPECT_EQ(countZ, 1);
}

TEST_F(MeshTest, TestGrid2OfAlmostPlanarMesh)
{
    MeshCore::MeshKernel kernel;
    Base::Vector3f p1 {0, 0, 0};
    Base::Vector3f p2 {1, 0, 0};
    Base::Vector3f p3 {0, 1, 0};
    Base::Vector3f p4 {1, 1, 1.0e-18F};
    kernel.AddFacet(MeshCore::MeshGeomFacet(p1, p2, p3));
    kernel.AddFacet(MeshCore::MeshGeomFacet(p3, p2, p4));

    MeshCore::MeshFacetGrid grid(kernel);
    unsigned long countX {};
    unsigned long countY {};
    unsigned long countZ {};
    grid.GetCtGrids(countX, countY, countZ);
    EXPECT_EQ(countX, 1);
    EXPECT_EQ(countY, 1);
    EXPECT_EQ(countZ, 1);
}
// NOLINTEND(cppcoreguidelines-*,readability-*)
