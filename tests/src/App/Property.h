// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2025 Pieter Hijma <info@pieterhijma.net>
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
#pragma once

#include <gtest/gtest.h>

#include <App/Document.h>
#include <App/PropertyStandard.h>
#include <App/VarSet.h>

#include <src/App/InitApplication.h>

class RenameProperty: public ::testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        tests::initApplication();
        _docName = App::GetApplication().getUniqueDocumentName("test");
        _doc = App::GetApplication().newDocument(_docName.c_str(), "testUser");
    }

    void SetUp() override
    {
        varSet = freecad_cast<App::VarSet*>(_doc->addObject("App::VarSet", "VarSet"));
        prop = freecad_cast<App::PropertyInteger*>(
            varSet->addDynamicProperty("App::PropertyInteger", "Variable", "Variables")
        );
        prop->setValue(Value);
    }

    void TearDown() override
    {
        _doc->removeObject(varSet->getNameInDocument());
    }

    static void TearDownTestSuite()
    {
        App::GetApplication().closeDocument(_docName.c_str());
    }

    const long Value = 123;
    App::VarSet* varSet {};
    App::PropertyInteger* prop {};

    static std::string _docName;
    static App::Document* _doc;
};
