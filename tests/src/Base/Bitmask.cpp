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

#include <Base/Bitmask.h>

enum class TestFlagEnum
{
    Flag1,
    Flag2,
    Flag3
};

class BitmaskTest: public ::testing::Test
{
protected:
    // void SetUp() override {};
    // void TearDown() override {};
};

TEST_F(BitmaskTest, toUnderlyingType)
{
    // Arrange
    Base::Flags<TestFlagEnum> flag1 {TestFlagEnum::Flag1};

    // Act
    auto result = flag1.toUnderlyingType();

    // Assert
    EXPECT_EQ(typeid(result), typeid(int));
}
