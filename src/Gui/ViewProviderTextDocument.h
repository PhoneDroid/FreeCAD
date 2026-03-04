// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2017 Markus Hovorka <m.hovorka@live.de>
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

#include <QPointer>
#include "ViewProviderDocumentObject.h"


class QPlainTextEdit;

namespace Gui
{

class GuiExport ViewProviderTextDocument: public ViewProviderDocumentObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderTextDocument);

public:
    ViewProviderTextDocument();
    ~ViewProviderTextDocument() override = default;

    App::PropertyBool ReadOnly;
    App::PropertyFloat FontSize;
    App::PropertyFont FontName;
    App::PropertyEnumeration SyntaxHighlighter;

    bool doubleClicked() override;
    void setupContextMenu(QMenu* menu, QObject* receiver, const char* member) override;
    bool isShow() const override
    {
        return true;
    }

    void onChanged(const App::Property* prop) override;

    MDIView* getMDIView() const override;

private:
    bool activateView() const;

private:
    QPointer<QPlainTextEdit> editorWidget;
    static const char* SyntaxEnums[];
};

}  // namespace Gui
