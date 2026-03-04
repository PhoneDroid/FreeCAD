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

#include <QPlainTextEdit>

#include <App/TextDocument.h>
#include <Gui/MDIView.h>


namespace Gui
{

class GuiExport TextDocumentEditorView: public MDIView
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(TextDocumentEditorView)
    TYPESYSTEM_HEADER_WITH_OVERRIDE();  // NOLINT

public:
    TextDocumentEditorView(App::TextDocument* textDocument, QPlainTextEdit* editor, QWidget* parent);
    ~TextDocumentEditorView() override;
    const char* getName() const override
    {
        return "TextDocumentEditorView";
    }
    bool onMsg(const char* msg, const char** output) override;
    bool onHasMsg(const char* msg) const override;

    QPlainTextEdit* getEditor() const
    {
        return editor;
    }
    App::TextDocument* getTextObject() const
    {
        return textDocument;
    }
    QStringList undoActions() const override;
    QStringList redoActions() const override;

protected:
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private:
    void setupEditor();
    void setupConnection();
    void saveToObject();
    void sourceChanged();
    void textChanged();
    void labelChanged();
    void refresh();

private:
    QPlainTextEdit* const editor;
    App::TextDocument* const textDocument;
    fastsignals::advanced_connection textConnection;
    fastsignals::connection labelConnection;
    bool aboutToClose = false;
};

}  // namespace Gui
