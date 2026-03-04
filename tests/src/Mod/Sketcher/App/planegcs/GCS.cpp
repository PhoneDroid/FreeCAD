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

#include "Mod/Sketcher/App/planegcs/GCS.h"

class SystemTest: public GCS::System
{
public:
    size_t getNumberOfConstraints(int tagID = -1)
    {
        return _getNumberOfConstraints(tagID);
    }
};

class GCSTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        _system = std::make_unique<SystemTest>();
    }

    void TearDown() override
    {
        _system.reset();
    }

    SystemTest* System()
    {
        return _system.get();
    }

private:
    std::unique_ptr<SystemTest> _system;
};

TEST_F(GCSTest, clearConstraints)  // NOLINT
{
    // Arrange
    const size_t numConstraints {100};
    for (size_t i = 0; i < numConstraints; ++i) {
        System()->addConstraint(new GCS::Constraint());
    }
    ASSERT_EQ(numConstraints, System()->getNumberOfConstraints());

    // Act
    System()->clear();

    // Assert
    EXPECT_EQ(0, System()->getNumberOfConstraints());
}
