// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2022 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <memory>
#include <Gui/MDIView.h>
#include <CXX/Objects.hxx>


namespace Gui
{

class MDIViewPyWrapImp;
class GuiExport MDIViewPyWrap: public MDIView
{
    Q_OBJECT

    TYPESYSTEM_HEADER_WITH_OVERRIDE();

public:
    /** View constructor
     * Attach the view to the given document. If the document is zero
     * the view will attach to the active document. Be aware, there isn't
     * always an active document.
     */
    explicit MDIViewPyWrap(
        const Py::Object& py,
        Gui::Document* pcDocument,
        QWidget* parent = nullptr,
        Qt::WindowFlags wflags = Qt::WindowFlags()
    );
    /** View destructor
     * Detach the view from the document, if attached.
     */
    ~MDIViewPyWrap() override;

    /// Message handler
    bool onMsg(const char* pMsg, const char** ppReturn) override;
    /// Message handler test
    bool onHasMsg(const char* pMsg) const override;
    /// overwrite when checking on close state
    bool canClose() override;
    PyObject* getPyObject() override;
    /** @name Printing */
    //@{
public Q_SLOTS:
    void print(QPrinter* printer) override;

public:
    /** Print content of view */
    void print() override;
    /** Print to PDF file */
    void printPdf() override;
    /** Show a preview dialog */
    void printPreview() override;
    //@}

    /** @name Undo/Redo actions */
    //@{
    QStringList undoActions() const override;
    QStringList redoActions() const override;
    //@}

private:
    std::unique_ptr<MDIViewPyWrapImp> ptr;
};

}  // namespace Gui
