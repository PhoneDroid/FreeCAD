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
#include <Base/Tools3D.h>
#include <Base/Vector3D.h>

class Line3D: public ::testing::Test
{
protected:
    Line3D()
        : pt1(0, 0, 0)
        , pt2(3, 4, 0)
    {}
    void SetUp() override
    {}
    void TearDown() override
    {}
    Base::Vector3d GetFirst() const
    {
        return pt1;
    }
    Base::Vector3d GetSecond() const
    {
        return pt2;
    }
    Base::Line3d GetLine() const
    {
        Base::Line3d line(pt1, pt2);
        return line;
    }

private:
    Base::Vector3d pt1, pt2;
};

TEST_F(Line3D, TestLength)
{
    Base::Line3d line(GetLine());
    EXPECT_DOUBLE_EQ(line.Length(), 5.0);
}

TEST_F(Line3D, TestSqrLength)
{
    Base::Line3d line(GetLine());
    EXPECT_DOUBLE_EQ(line.SqrLength(), 25.0);
}

TEST_F(Line3D, TestPoints)
{
    Base::Line3d line(GetLine());
    EXPECT_EQ(line.GetBase(), GetFirst());
    EXPECT_EQ(line.GetDirection(), GetSecond());
}

TEST_F(Line3D, TestFromPos)
{
    Base::Line3d line(GetLine());
    EXPECT_EQ(line.FromPos(2.5), Base::Vector3d(1.5, 2, 0));
}

TEST_F(Line3D, TestContains)
{
    Base::Line3d line(GetLine());
    EXPECT_EQ(line.Contains(Base::Vector3d(1.5, 2, 0)), true);
}

TEST(Polygon3D, TestDefault)
{
    Base::Polygon3d poly;
    EXPECT_EQ(poly.GetSize(), 0);
}

TEST(Polygon3D, TestAdd)
{
    Base::Polygon3d poly;
    poly.Add(Base::Vector3d());
    EXPECT_EQ(poly.GetSize(), 1);
}

TEST(Polygon3D, TestRemove)
{
    Base::Polygon3d poly;
    poly.Add(Base::Vector3d());
    EXPECT_EQ(poly.GetSize(), 1);
    EXPECT_EQ(poly.Remove(1), false);
    EXPECT_EQ(poly.Remove(0), true);
    EXPECT_EQ(poly.GetSize(), 0);
}

TEST(Polygon3D, TestClear)
{
    Base::Polygon3d poly;
    poly.Add(Base::Vector3d());
    poly.Clear();
    EXPECT_EQ(poly.GetSize(), 0);
}
