// SPDX-FileCopyrightText: 2007 Jürgen Riegel <juergen.riegel@web.de>
// SPDX-FileCopyrightText: 2013 Luke Parry <l.parry@warwick.ac.uk>
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

#include <App/DocumentObject.h>
#include <App/PropertyLinks.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawView.h"


namespace TechDraw
{

/** Base class for collection of view objects
 */
class TechDrawExport DrawViewCollection : public DrawView
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawViewCollection);

public:
    App::PropertyLinkList Views;
public:
    /// Constructor
    DrawViewCollection();
    ~DrawViewCollection() override;
    short mustExecute() const override;

    int addView(App::DocumentObject* obj);
    int removeView(App::DocumentObject* obj);
    std::vector<App::DocumentObject*> getViews() const;
    void rebuildViewList();
    bool isUnsetting() { return nowUnsetting; }

    int countChildren();
    void lockChildren();

    void onDocumentRestored() override;
    App::DocumentObjectExecReturn *execute() override;
    void unsetupObject() override;

    /// returns the type name of the ViewProvider
    const char* getViewProviderName() const override {
        return "TechDrawGui::ViewProviderViewCollection";
    }
    QRectF getRect() const override;

protected:
    void onChanged(const App::Property* prop) override;
    bool nowUnsetting;
};

} //namespace TechDraw