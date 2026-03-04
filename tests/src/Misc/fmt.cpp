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

#include <fmt/format.h>
#include <fmt/printf.h>
#include <gtest/gtest.h>
#include <stdexcept>

// NOLINTBEGIN
TEST(fmt, fail)
{
    EXPECT_NE("abc", fmt::format("{}{}", "a", "b"));
}

TEST(fmt, pass)
{
    EXPECT_EQ("ab", fmt::format("{}{}", "a", "b"));
}

TEST(fmt, print_pass)
{
    EXPECT_EQ("12", fmt::sprintf("%s%d", "1", 2));
    EXPECT_EQ("x", fmt::sprintf("%c", 'x'));
    EXPECT_EQ("1.23 2", fmt::sprintf("%.2f %d", 1.23456, 2));
    EXPECT_EQ("0.123456789012", fmt::sprintf("%.12f", 0.123456789012));
    EXPECT_EQ("-1234", fmt::sprintf("%li", -1234L));
    EXPECT_EQ("-1234567890", fmt::sprintf("%li", -1234567890L));
    EXPECT_EQ("1234567890", fmt::sprintf("%li", 1234567890UL));
}

TEST(fmt, print_fail)
{
    EXPECT_THROW(fmt::printf("%s%d", 1, 2), std::exception);
}
// NOLINTEND
