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
#include "src/App/InitApplication.h"

#include <memory>

#include <Mod/Spreadsheet/App/Sheet.h>
#include <Mod/Spreadsheet/App/PropertySheet.h>

class PropertySheetTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }
    void SetUp() override
    {
        _sheet = std::make_unique<Spreadsheet::Sheet>();
        _propertySheet = std::make_unique<Spreadsheet::PropertySheet>(_sheet.get());
    }
    void TearDown() override
    {
        _sheet.reset();
        _propertySheet.reset();
    }

    /// Get a non-owning pointer to the internal PropertySheet for this test
    Spreadsheet::PropertySheet* propertySheet()
    {
        return _propertySheet.get();
    }

private:
    std::unique_ptr<Spreadsheet::Sheet> _sheet;
    std::unique_ptr<Spreadsheet::PropertySheet> _propertySheet;
};

TEST_F(PropertySheetTest, isValidCellAddressNameValidNames)  // NOLINT
{
    std::vector<std::string> validAddressNames {"A1", "Z1024", "AA42", "ZZ4096"};
    for (const auto& name : validAddressNames) {
        EXPECT_TRUE(propertySheet()->isValidCellAddressName(name))
            << "\"" << name << "\" was not accepted as a cell name, and should be";
    }
}

TEST_F(PropertySheetTest, isValidCellAddressNameInvalidNames)  // NOLINT
{
    std::vector<std::string> invalidAddressNames {
        "Bork",
        "Bork_de_bork",
        "A",
        "42",
        "AAA1",     // Too many characters to start, AAA is not a valid column
        "ZZ123456"  // Too large a number to end, 123456 is not a valid row
    };
    for (const auto& name : invalidAddressNames) {
        EXPECT_FALSE(propertySheet()->isValidCellAddressName(name))
            << "\"" << name << "\" was accepted as a cell name, and should not be";
    }
}

TEST_F(PropertySheetTest, validAliases)  // NOLINT
{
    std::vector<std::string> validAliases {
        "Bork",
        "Bork_de_bork"
        "A",
        "AA123456"
    };
    for (const auto& name : validAliases) {
        EXPECT_TRUE(propertySheet()->isValidAlias(name))
            << "\"" << name << "\" was not accepted as an alias name, and should be";
    }
}

TEST_F(PropertySheetTest, invalidAliases)  // NOLINT
{
    std::vector<std::string>
        invalidAliases {"A1", "ZZ1234", "mm", "no spaces allowed", "\'NoLeadingQuotes"};

    for (const auto& name : invalidAliases) {
        EXPECT_FALSE(propertySheet()->isValidAlias(name))
            << "\"" << name << "\" was accepted as an alias name, and should not be";
    }
}
