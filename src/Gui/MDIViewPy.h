// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2019 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Base/PyObjectBase.h>
#include <CXX/Extensions.hxx>
#include <QPointer>
#include <FCGlobal.h>

#include "MDIView.h"

namespace Gui
{
class MDIView;

class GuiExport MDIViewPy: public Py::PythonExtension<MDIViewPy>
{
public:
    static void init_type();  // announce properties and methods
    static PyObject* extension_object_new(PyTypeObject* subtype, PyObject* /*args*/, PyObject* /*kwds*/);

    static Py::Object type();
    static Py::ExtensionObject<MDIViewPy> create(MDIView* mdi);

    explicit MDIViewPy(MDIView* mdi);
    ~MDIViewPy() override;

    Py::Object repr() override;

    /** @name Printing */
    //@{
    Py::Object printView(const Py::Tuple&);
    Py::Object printPdf(const Py::Tuple&);
    Py::Object printPreview(const Py::Tuple&);
    //@}

    /** @name Undo/Redo actions */
    //@{
    Py::Object undoActions(const Py::Tuple&);
    Py::Object redoActions(const Py::Tuple&);
    //@}

    Py::Object sendMessage(const Py::Tuple&);
    Py::Object supportMessage(const Py::Tuple&);
    Py::Object fitAll(const Py::Tuple&);
    Py::Object setActiveObject(const Py::Tuple&);
    Py::Object getActiveObject(const Py::Tuple&);
    Py::Object cast_to_base(const Py::Tuple&);

    MDIView* getMDIViewPtr()
    {
        return _view.data();
    }

private:
    QPointer<MDIView> _view;
};

}  // namespace Gui
