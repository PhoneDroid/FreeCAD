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
#include <Base/Placement.h>
#include <Base/ViewProj.h>

TEST(ViewProj, TestViewProjMatrix)
{
    Base::Matrix4D mat;
    Base::ViewProjMatrix proj(mat);

    Base::Vector3d vec(1, 2, 3);
    EXPECT_EQ(proj(vec), Base::Vector3d(1, 1.5, 2));
    EXPECT_EQ(proj.inverse(Base::Vector3d(1, 1.5, 2)), vec);
}

TEST(ViewProj, TestViewOrthoProjMatrix)
{
    Base::Matrix4D mat;
    Base::ViewOrthoProjMatrix proj(mat);

    Base::Vector3d vec(1, 2, 3);
    EXPECT_EQ(proj(vec), vec);
    EXPECT_EQ(proj.inverse(vec), vec);
}
