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
#include <Base/XMLTools.h>

class TestXMLTools: public testing::Test
{
};


TEST_F(TestXMLTools, EscapeXmlEmptyString)
{
    EXPECT_EQ(XMLTools::escapeXml(""), "");
}

TEST_F(TestXMLTools, EscapeXmlNoChangesForSafeText)
{
    EXPECT_EQ(XMLTools::escapeXml("abcXYZ_123"), "abcXYZ_123");
    EXPECT_EQ(XMLTools::escapeXml("hello world"), "hello world");
    EXPECT_EQ(XMLTools::escapeXml("line1\nline2\tend"), "line1\nline2\tend");
}

TEST_F(TestXMLTools, EscapeXmlEscapesAmpersand)
{
    EXPECT_EQ(XMLTools::escapeXml("&"), "&amp;");
    EXPECT_EQ(XMLTools::escapeXml("a&b"), "a&amp;b");
}

TEST_F(TestXMLTools, EscapeXmlEscapesLessThanAndGreaterThan)
{
    EXPECT_EQ(XMLTools::escapeXml("<"), "&lt;");
    EXPECT_EQ(XMLTools::escapeXml(">"), "&gt;");
    EXPECT_EQ(XMLTools::escapeXml("a<b"), "a&lt;b");
    EXPECT_EQ(XMLTools::escapeXml("a>b"), "a&gt;b");
    EXPECT_EQ(XMLTools::escapeXml("a<b>c"), "a&lt;b&gt;c");
}

TEST_F(TestXMLTools, EscapeXmlEscapesQuotes)
{
    EXPECT_EQ(XMLTools::escapeXml("\""), "&quot;");
    EXPECT_EQ(XMLTools::escapeXml("'"), "&apos;");
    EXPECT_EQ(XMLTools::escapeXml("a\"b"), "a&quot;b");
    EXPECT_EQ(XMLTools::escapeXml("a'b"), "a&apos;b");
}

TEST_F(TestXMLTools, EscapeXmlEscapesAllFiveInOneString)
{
    // input:  & < > " '
    EXPECT_EQ(XMLTools::escapeXml("&<>\"'"), "&amp;&lt;&gt;&quot;&apos;");
}

TEST_F(TestXMLTools, EscapeXmlDoesNotDoubleEscapeNewlyInsertedEntities)
{
    // This test specifically catches the classic bug where you replace
    // '<' with "&lt;" and then later replace '&' with "&amp;" and end up with "&amp;lt;".
    EXPECT_EQ(XMLTools::escapeXml("<"), "&lt;");
    EXPECT_EQ(XMLTools::escapeXml(">"), "&gt;");
    EXPECT_EQ(XMLTools::escapeXml("\""), "&quot;");
    EXPECT_EQ(XMLTools::escapeXml("'"), "&apos;");
}

TEST_F(TestXMLTools, EscapeXmlComplexMixedContent)
{
    const std::string in = "Tom & Jerry <\"fun\"> 'n' games";
    const std::string out = "Tom &amp; Jerry &lt;&quot;fun&quot;&gt; &apos;n&apos; games";
    EXPECT_EQ(XMLTools::escapeXml(in), out);
}

TEST_F(TestXMLTools, EscapeXmlMultipleAdjacentCharacters)
{
    EXPECT_EQ(XMLTools::escapeXml("&&&&"), "&amp;&amp;&amp;&amp;");
    EXPECT_EQ(XMLTools::escapeXml("<<<<"), "&lt;&lt;&lt;&lt;");
    EXPECT_EQ(XMLTools::escapeXml("\"\"''"), "&quot;&quot;&apos;&apos;");
}

TEST_F(TestXMLTools, EscapeXmlPreservesWhitespaceAndControlCommonInText)
{
    EXPECT_EQ(XMLTools::escapeXml(" a \r\n b \t c "), " a \r\n b \t c ");
}
