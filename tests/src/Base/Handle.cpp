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
#include <Base/Handle.h>

class Data: public Base::Handled
{
    int myValue {};

public:
    int getValue() const
    {
        return myValue;
    }
    void setValue(int val)
    {
        myValue = val;
    }
};

TEST(Reference, TestNull)
{
    Base::Reference<Data> data;
    EXPECT_EQ(data.getRefCount(), 0);
}

TEST(Reference, TestConstructor)
{
    Base::Reference<Data> data(new Data);
    EXPECT_EQ(data.getRefCount(), 1);
}

TEST(Reference, TestCopy)
{
    Base::Reference<Data> data(new Data);
    Base::Reference<Data> copy(data);
    EXPECT_EQ(data.getRefCount(), 2);
    EXPECT_EQ(copy.getRefCount(), 2);
    EXPECT_EQ(data, copy);
    EXPECT_EQ(data.isValid(), true);
    EXPECT_EQ(copy.isValid(), true);
    EXPECT_EQ(data.isNull(), false);
    EXPECT_EQ(copy.isNull(), false);
}

TEST(Reference, TestAssignRaw)
{
    Base::Reference<Data> data = new Data();
    EXPECT_EQ(data->getValue(), 0);
    EXPECT_EQ(data.getRefCount(), 1);
}

TEST(Reference, TestAssignRef)
{
    Base::Reference<Data> data = new Data();
    Base::Reference<Data> copy;
    copy = data;
    EXPECT_EQ(data.getRefCount(), 2);
    EXPECT_EQ(copy.getRefCount(), 2);
    EXPECT_EQ(data, copy);
    EXPECT_EQ(data.isValid(), true);
    EXPECT_EQ(copy.isValid(), true);
    EXPECT_EQ(data.isNull(), false);
    EXPECT_EQ(copy.isNull(), false);
}

TEST(Reference, TestRefHandle)
{
    Base::Reference<Data> data = new Data();
    data->ref();
    EXPECT_EQ(data.getRefCount(), 2);
    data->unref();
    EXPECT_EQ(data.getRefCount(), 1);
}
