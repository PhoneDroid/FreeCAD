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

#include <Base/Axis.h>
#include <Base/Placement.h>
#include <Base/Rotation.h>

#include <src/App/InitApplication.h>

class Axis: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }
};

TEST_F(Axis, TestDefault)
{
    Base::Axis axis;
    EXPECT_EQ(axis.getBase(), Base::Vector3d());
    EXPECT_EQ(axis.getDirection(), Base::Vector3d());
}

TEST_F(Axis, TestCustom)
{
    Base::Axis axis(Base::Vector3d(0, 0, 1), Base::Vector3d(1, 1, 1));
    EXPECT_EQ(axis.getBase(), Base::Vector3d(0, 0, 1));
    EXPECT_EQ(axis.getDirection(), Base::Vector3d(1, 1, 1));
}

TEST_F(Axis, TestSetter)
{
    Base::Axis axis;
    axis.setBase(Base::Vector3d(0, 0, 1));
    axis.setDirection(Base::Vector3d(1, 1, 1));
    EXPECT_EQ(axis.getBase(), Base::Vector3d(0, 0, 1));
    EXPECT_EQ(axis.getDirection(), Base::Vector3d(1, 1, 1));
}

TEST_F(Axis, TestAssign)
{
    Base::Axis axis;
    Base::Axis move;
    axis.setBase(Base::Vector3d(0, 0, 1));
    axis.setDirection(Base::Vector3d(1, 1, 1));
    move = std::move(axis);  // NOLINT
    EXPECT_EQ(move.getBase(), Base::Vector3d(0, 0, 1));
    EXPECT_EQ(move.getDirection(), Base::Vector3d(1, 1, 1));
}

TEST_F(Axis, TestReverse)
{
    Base::Axis axis(Base::Vector3d(0, 0, 1), Base::Vector3d(1, 1, 1));
    axis.reverse();
    EXPECT_EQ(axis.getBase(), Base::Vector3d(0, 0, 1));
    EXPECT_EQ(axis.getDirection(), Base::Vector3d(-1, -1, -1));
}

TEST_F(Axis, TestReversed)
{
    Base::Axis axis(Base::Vector3d(0, 0, 1), Base::Vector3d(1, 1, 1));
    Base::Axis rev(axis.reversed());
    EXPECT_EQ(axis.getDirection(), Base::Vector3d(1, 1, 1));
    EXPECT_EQ(rev.getBase(), Base::Vector3d(0, 0, 1));
    EXPECT_EQ(rev.getDirection(), Base::Vector3d(-1, -1, -1));
}

TEST_F(Axis, TestMove)
{
    Base::Axis axis(Base::Vector3d(0, 0, 1), Base::Vector3d(1, 1, 1));
    axis.move(Base::Vector3d(1, 2, 3));
    EXPECT_EQ(axis.getBase(), Base::Vector3d(1, 2, 4));
    EXPECT_EQ(axis.getDirection(), Base::Vector3d(1, 1, 1));
}

TEST_F(Axis, TestMult)
{
    Base::Axis axis(Base::Vector3d(0, 0, 1), Base::Vector3d(0, 0, 1));
    axis *= Base::Placement(Base::Vector3d(1, 1, 1), Base::Rotation(1, 0, 0, 0));
    EXPECT_EQ(axis.getBase(), Base::Vector3d(1, 1, 0));
    EXPECT_EQ(axis.getDirection(), Base::Vector3d(0, 0, -1));
}
