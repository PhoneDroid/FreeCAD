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

#include "Mod/Part/App/FeaturePartBoolean.h"
#include <src/App/InitApplication.h>

#include "PartTestHelpers.h"

class FeaturePartBooleanTest: public ::testing::Test, public PartTestHelpers::PartTestHelperClass
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }


    void SetUp() override
    {
        // createTestDoc();
        // _boolean = _doc->addObject<Part::Boolean>();
    }

    void TearDown() override
    {}

    Part::Boolean* _boolean;  // NOLINT Can't be private in a test framework
};

// This is completely tested in the FeaturePartCommon, FeaturePartCut, FeaturePartFuse and
// FeaturePartSection subclasses.  This class is unfortunately not usable unless initialized in one
// of those forms, so no testing at this level.
