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
#include <Base/FileInfo.h>
#include <Base/Stream.h>
#include <Base/TimeInfo.h>

class FileInfoTest: public ::testing::Test
{
protected:
    FileInfoTest()
    {
        tmp.setFile(Base::FileInfo::getTempPath() + "fctest");
        tmp.createDirectory();

        file.setFile(tmp.filePath() + "/test.txt");
        dir.setFile(tmp.filePath() + "/subdir");
    }

    void SetUp() override
    {
        Base::ofstream str(file, std::ios::out);
        str << "Test\n";
        str.close();
        dir.createDirectory();
    }

    void TearDown() override
    {
        EXPECT_TRUE(file.deleteFile());
        EXPECT_TRUE(dir.deleteDirectory());
    }

protected:
    Base::FileInfo tmp;
    Base::FileInfo file;
    Base::FileInfo dir;
};

TEST_F(FileInfoTest, TestDirectoryPath)
{
    Base::FileInfo relfile("nofile.txt");
    relfile.setFile(relfile.dirPath());
    EXPECT_TRUE(relfile.exists());
}

TEST_F(FileInfoTest, TestExistsDirectory)
{
    EXPECT_TRUE(tmp.exists());
}

TEST_F(FileInfoTest, TestCreateDirectory)
{
    Base::FileInfo path;
    path.setFile(tmp.filePath() + "/subdir1/subdir2");
    EXPECT_FALSE(path.createDirectory());
}

TEST_F(FileInfoTest, TestDirectoryContent)
{
    auto content = tmp.getDirectoryContent();
    EXPECT_EQ(content.size(), 2);
    EXPECT_TRUE(content[0].exists());
    EXPECT_TRUE(content[1].exists());
}

TEST_F(FileInfoTest, TestCheckPermission)
{
    EXPECT_TRUE(file.isReadable());
    EXPECT_TRUE(file.isWritable());
}

TEST_F(FileInfoTest, TestCheckNoPermission)
{
    std::string path = tmp.filePath();
    Base::FileInfo nofile(path + "/nofile");
    EXPECT_FALSE(nofile.isReadable());
    EXPECT_FALSE(nofile.isWritable());
}

TEST_F(FileInfoTest, TestSetPermission)
{
    file.setPermissions(Base::FileInfo::ReadOnly);
    EXPECT_TRUE(file.isReadable());
    EXPECT_FALSE(file.isWritable());

    file.setPermissions(Base::FileInfo::WriteOnly);
    EXPECT_FALSE(file.isReadable());
    EXPECT_TRUE(file.isWritable());

    file.setPermissions(Base::FileInfo::ReadWrite);
    EXPECT_TRUE(file.isReadable());
    EXPECT_TRUE(file.isWritable());
}

TEST_F(FileInfoTest, TestCheckFile)
{
    EXPECT_TRUE(file.isFile());
    EXPECT_FALSE(dir.isFile());

    std::string path = tmp.filePath();
    Base::FileInfo file2(path + "/file2");
    EXPECT_TRUE(file2.isFile());
}

TEST_F(FileInfoTest, TestCheckDirectory)
{
    EXPECT_FALSE(file.isDir());
    EXPECT_TRUE(dir.isDir());

    std::string path = tmp.filePath();
    Base::FileInfo file2(path + "/file2");
    EXPECT_FALSE(file2.isDir());
}

TEST_F(FileInfoTest, TestSize)
{
    EXPECT_EQ(file.size(), 5);
}

TEST_F(FileInfoTest, TestLastModified)
{
    EXPECT_FALSE(file.lastModified().isNull());

    std::string path = tmp.filePath();
    Base::FileInfo nofile(path + "/nofile.txt");
    EXPECT_TRUE(nofile.lastModified().isNull());
}

TEST_F(FileInfoTest, TestDeleteFile)
{
    std::string path = tmp.filePath();
    Base::FileInfo file2(path + "/nofile.txt");
    EXPECT_FALSE(file2.deleteFile());
}

TEST_F(FileInfoTest, TestRenameFile)
{
    std::string path = tmp.filePath();
    Base::FileInfo file2(path + "/file2");
    EXPECT_FALSE(file2.renameFile((path + "/file3").c_str()));
    EXPECT_TRUE(file.renameFile((path + "/file2").c_str()));
}

TEST_F(FileInfoTest, TestCopyFile)
{
    std::string path = tmp.filePath();
    Base::FileInfo copy(path + "/copy.txt");
    EXPECT_TRUE(file.copyTo(copy.filePath().c_str()));
    EXPECT_TRUE(copy.deleteFile());
}
