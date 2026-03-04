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

#include "App/License.h"

TEST(License, isLicenseEmpty)
{
    EXPECT_EQ(App::findLicense(""), -1);
}

TEST(License, isLicenseNull)
{
    EXPECT_EQ(App::findLicense(nullptr), -1);
}

TEST(License, isLicenseYesStr)
{
    EXPECT_EQ(App::findLicense("CC_BY_40"), 1);
}

TEST(License, UnknownIdentifier)
{
    int index {App::findLicense("junk")};
    EXPECT_EQ(index, -1);
}

TEST(License, direct)
{
    int posn {App::findLicense("CC_BY_40")};
    App::TLicenseArr tt {
        "CC_BY_40",
        "Creative Commons Attribution 4.0",
        "https://creativecommons.org/licenses/by/4.0/"
    };
    EXPECT_STREQ(App::licenseItems.at(posn).at(0), tt.at(0));
    EXPECT_STREQ(App::licenseItems.at(posn).at(1), tt.at(1));
    EXPECT_STREQ(App::licenseItems.at(posn).at(2), tt.at(2));
}

TEST(License, findLicenseByIdent)
{
    App::TLicenseArr arr {App::licenseItems.at(App::findLicense("CC_BY_40"))};

    EXPECT_STREQ(arr.at(App::posnOfIdentifier), "CC_BY_40");
    EXPECT_STREQ(arr.at(App::posnOfFullName), "Creative Commons Attribution 4.0");
    EXPECT_STREQ(arr.at(App::posnOfUrl), "https://creativecommons.org/licenses/by/4.0/");
}
