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
#include <memory>
#include <zipios++/collcoll.h>

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
TEST(Collection, TestValidity)
{
    zipios::CollectionCollection cc;
    EXPECT_EQ(cc.isValid(), true);
    EXPECT_EQ(cc.entries().empty(), true);
    EXPECT_EQ(cc.getEntry("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(cc.getEntry("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(cc.getInputStream("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(cc.getInputStream("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(cc.getName(), "-");  // default name is "-"
    EXPECT_EQ(cc.size(), 0);
    cc.close();
    EXPECT_EQ(cc.isValid(), false);
}

TEST(Collection, TestCopy)
{
    zipios::CollectionCollection cc;
    zipios::CollectionCollection copy(cc);
    EXPECT_EQ(copy.isValid(), true);
    EXPECT_EQ(copy.entries().empty(), true);
    EXPECT_EQ(copy.getEntry("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(copy.getEntry("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(copy.getInputStream("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(copy.getInputStream("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(copy.getName(), "-");  // default name is "-"
    EXPECT_EQ(copy.size(), 0);
}

TEST(Collection, TestCopyAssign)
{
    zipios::CollectionCollection cc;
    zipios::CollectionCollection copy;
    copy = cc;
    EXPECT_EQ(copy.isValid(), true);
    EXPECT_EQ(copy.entries().empty(), true);
    EXPECT_EQ(copy.getEntry("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(copy.getEntry("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(copy.getInputStream("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(copy.getInputStream("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(copy.getName(), "-");  // default name is "-"
    EXPECT_EQ(copy.size(), 0);
}

TEST(Collection, TestClone)
{
    zipios::CollectionCollection cc;
    std::unique_ptr<zipios::FileCollection> pointer(cc.clone());
    EXPECT_EQ(pointer->isValid(), true);
    EXPECT_EQ(pointer->entries().empty(), true);
    EXPECT_EQ(pointer->getEntry("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(pointer->getEntry("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(pointer->getInputStream("inexistant", zipios::FileCollection::MatchPath::MATCH), nullptr);
    EXPECT_EQ(pointer->getInputStream("inexistant", zipios::FileCollection::MatchPath::IGNORE), nullptr);
    EXPECT_EQ(pointer->getName(), "-");  // default name is "-"
    EXPECT_EQ(pointer->size(), 0);
}

TEST(Collection, TestAdd)
{
    zipios::CollectionCollection cc;
    zipios::FileCollection* pointer(cc.clone());
    EXPECT_EQ(cc.addCollection(pointer), true);
    EXPECT_EQ(cc.addCollection(nullptr), false);
    EXPECT_EQ(cc.addCollection(cc), false);
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
