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

#include <App/Application.h>
#include <App/Document.h>
#include <App/Origin.h>
#include "Mod/Part/App/Attacher.h"
#include "Mod/PartDesign/App/Body.h"
#include "Mod/PartDesign/App/DatumPlane.h"

class DatumPlaneTest: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
    }

    void SetUp() override
    {
        _docName = App::GetApplication().getUniqueDocumentName("test");
        _doc = App::GetApplication().newDocument(_docName.c_str(), "testUser");
        _body = _doc->addObject<PartDesign::Body>();
    }

    void TearDown() override
    {
        App::GetApplication().closeDocument(_docName.c_str());
    }

    App::Document* getDocument() const
    {
        return _doc;
    }

    PartDesign::Body* getBody() const
    {
        return _body;
    }

private:
    std::string _docName;
    App::Document* _doc = nullptr;
    PartDesign::Body* _body = nullptr;
};

TEST_F(DatumPlaneTest, attachDatumPlane)
{
    auto datumPlane = getDocument()->addObject<PartDesign::Plane>("Plane");
    ASSERT_TRUE(datumPlane);
    getBody()->addObject(datumPlane);
    auto origin = getBody()->getOrigin();

    App::PropertyLinkSubList support;
    std::vector<App::DocumentObject*> objs;
    std::vector<std::string> subs;
    objs.push_back(origin->getXY());
    subs.emplace_back();
    support.setValues(objs, subs);

    auto attach = datumPlane->getExtensionByType<Part::AttachExtension>();
    attach->attacher().setReferences(support);
    Attacher::SuggestResult sugr;
    attach->attacher().suggestMapModes(sugr);
    EXPECT_EQ(sugr.message, Attacher::SuggestResult::srOK);
}
