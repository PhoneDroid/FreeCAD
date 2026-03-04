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
#include <Base/TimeInfo.h>

TEST(TimeInfo, TestDefault)
{
    Base::TimeInfo ti;
    EXPECT_FALSE(ti.isNull());
}

TEST(TimeInfo, TestNull)
{
    Base::TimeInfo ti(Base::TimeInfo::null());
    EXPECT_TRUE(ti.isNull());
}

TEST(TimeInfo, TestCompare)
{
    Base::TimeInfo ti1;
    Base::TimeInfo ti2(ti1);
    ti2 += std::chrono::seconds(1);
    EXPECT_TRUE(ti1 == ti1);
    EXPECT_TRUE(ti1 != ti2);
    EXPECT_TRUE(ti1 < ti2);
    EXPECT_FALSE(ti1 > ti2);
    EXPECT_TRUE(ti1 <= ti1);
    EXPECT_TRUE(ti1 >= ti1);
}

TEST(TimeInfo, TestDiffTime)
{
    Base::TimeInfo ti1;
    Base::TimeInfo ti2(ti1);
    ti2 += std::chrono::seconds(1000);
    EXPECT_FLOAT_EQ(Base::TimeInfo::diffTimeF(ti1, ti2), 1000.0);
}
