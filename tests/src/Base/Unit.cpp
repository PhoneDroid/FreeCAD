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

#include "Base/Unit.h"
#include <gtest/gtest.h>
#include <Base/Exception.h>

// NOLINTBEGIN
using namespace Base;

TEST(Unit, string_simple_numerator_no_denominator)
{
    EXPECT_EQ(Unit::Length.getString(), "mm");
}

TEST(Unit, string_complex_numerator_no_denominator)
{
    EXPECT_EQ(Unit::Area.getString(), "mm^2");
}

TEST(Unit, string_complex_single_denominator)
{
    EXPECT_EQ(Unit::DissipationRate.getString(), "mm^2/s^3");
}

TEST(Unit, string_no_numerator)
{
    EXPECT_EQ(Unit::InverseArea.getString(), "1/mm^2");
}

TEST(Unit, string_complex_multi_denominator)
{
    EXPECT_EQ(Unit::MagneticFlux.getString(), "mm^2*kg/(s^2*A)");
}

TEST(Unit, type_string)
{
    EXPECT_EQ(Unit::MagneticFlux.getTypeString(), "MagneticFlux");
}

TEST(Unit, TestEqual)
{
    EXPECT_TRUE(Unit::Length == Unit::Length);
}

TEST(Unit, TestNotEqual)
{
    EXPECT_TRUE(Unit::Length != Unit::Area);
}

TEST(Unit, multiply_One_is_One)
{
    EXPECT_EQ(Unit::One * Unit::One, Unit::One);
}

TEST(Unit, TestMult)
{
    constexpr UnitExponents arr {1, 1, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(Unit::Mass * Unit::Length, Unit {arr});
}

TEST(Unit, div)
{
    EXPECT_EQ(Unit::Area / Unit::Length, Unit::Length);
}

TEST(Unit, div_by_One_does_nothing)
{
    EXPECT_EQ(Unit::Area / Unit::One, Unit::Area);
}

TEST(Unit, pow_0_is_One)
{
    EXPECT_EQ(Unit::Area.pow(0), Unit::One);
}

TEST(Unit, pow_1_leaves_unit_unchanged)
{
    EXPECT_EQ(Unit::Area.pow(1), Unit::Area);
}

TEST(Unit, pow_2_is_squared)
{
    EXPECT_EQ(Unit::Length.pow(2), Unit::Area);
}

TEST(Unit, pow_3_is_cubed)
{
    EXPECT_EQ(Unit::Length.pow(3), Unit::Volume);
}

TEST(Unit, pow_less_than_one)
{
    EXPECT_EQ(Unit::Volume.pow(1.0 / 3.0), Unit::Length);
}

TEST(Unit, one_still_one_after_pow)
{
    EXPECT_EQ(Unit::One.pow(2), Unit::One);
}

TEST(Unit, square_root)
{
    EXPECT_EQ(Unit::Area.root(2), Unit::Length);
}

TEST(Unit, cube_root)
{
    EXPECT_EQ(Unit::Volume.root(3), Unit::Length);
}

TEST(Unit, zero_root)
{
    EXPECT_THROW([[maybe_unused]] auto res = Unit::Area.root(0), UnitsMismatchError);
}

TEST(Unit, one_root)
{
    EXPECT_EQ(Unit::Area.root(1), Unit::Area);
}

TEST(Unit, TestPow3div2)
{
    EXPECT_THROW([[maybe_unused]] auto res = Unit::Volume.pow(3.0 / 2.0), UnitsMismatchError);
}

TEST(Unit, overflow)
{
    constexpr UnitExponents arr {99, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_THROW([[maybe_unused]] auto res = Unit {arr}, OverflowError);
}

TEST(Unit, underflow)
{
    constexpr UnitExponents arr {-99, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_THROW([[maybe_unused]] auto res = Unit {arr}, UnderflowError);
}

TEST(Unit, representation_simple)
{
    const std::string expect {"Unit: mm (1,0,0,0,0,0,0,0) [Length]"};
    const auto actual = Unit::Length.representation();
    EXPECT_EQ(actual, expect);
}

TEST(Unit, representation_complex)
{
    const std::string expect {"Unit: mm^2*kg/(s^2*A) (2,1,-2,-1,0,0,0,0) [MagneticFlux]"};
    const auto actual = Unit::MagneticFlux.representation();
    EXPECT_EQ(actual, expect);
}

TEST(Unit, representation_no_name)
{
    constexpr Unit unit {{1, 1}};
    const std::string expect {"Unit: mm*kg (1,1,0,0,0,0,0,0)"};
    const auto actual = unit.representation();
    EXPECT_EQ(actual, expect);
}
// NOLINTEND
