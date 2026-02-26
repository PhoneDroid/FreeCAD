// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2013 Yorik van Havre <yorik@uncreated.net>

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

#include <QDomDocument>

#include <App/DocumentObject.h>
#include <App/FeaturePython.h>
#include <Base/BoundBox.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawView.h"


namespace TechDraw
{
class DrawPage;

class TechDrawExport DrawViewSymbol : public TechDraw::DrawView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawViewSymbol);

public:
    /// Constructor
    DrawViewSymbol();
    ~DrawViewSymbol() override;

    App::PropertyString       Symbol;
    App::PropertyStringList   EditableTexts;
    App::PropertyLink         Owner;

    short mustExecute() const override;
    /** @name methods override Feature */
    //@{
    /// recalculate the Feature
    App::DocumentObjectExecReturn *execute() override;
    //@}

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override {
        return "TechDrawGui::ViewProviderSymbol";
    }
    QRectF getRect() const override;
    bool checkFit(TechDraw::DrawPage* p) const override;

    App::PropertyLink *getOwnerProperty() override { return &Owner; }

    //return PyObject as DrawViewSymbolPy
    PyObject *getPyObject() override;

protected:
    void onChanged(const App::Property* prop) override;
    Base::BoundBox3d bbox;

    std::vector<std::string> getEditableFields();
    void updateFieldsInSymbol();
    bool loadQDomDocument(QDomDocument& symbolDocument);
};

using DrawViewSymbolPython = App::FeaturePythonT<DrawViewSymbol>;


} //namespace TechDraw