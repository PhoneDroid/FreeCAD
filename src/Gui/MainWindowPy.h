// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2021 Werner Mayer <wmayer@users.sourceforge.net>
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

namespace Gui
{
class MainWindow;

class GuiExport MainWindowPy: public Py::PythonExtension<MainWindowPy>
{
public:
    static void init_type();
    static PyObject* extension_object_new(PyTypeObject* subtype, PyObject* /*args*/, PyObject* /*kwds*/);

    static Py::Object createWrapper(MainWindow* mw);
    static Py::Object type();
    static Py::ExtensionObject<MainWindowPy> create(MainWindow* mw);

    explicit MainWindowPy(MainWindow* mw);
    ~MainWindowPy() override;

    Py::Object repr() override;

    Py::Object getWindows(const Py::Tuple&);
    Py::Object getWindowsOfType(const Py::Tuple&);
    Py::Object setActiveWindow(const Py::Tuple&);
    Py::Object getActiveWindow(const Py::Tuple&);
    Py::Object addWindow(const Py::Tuple&);
    Py::Object removeWindow(const Py::Tuple&);

    Py::Object showHint(const Py::Tuple&);
    Py::Object hideHint(const Py::Tuple&);

private:
    QPointer<MainWindow> _mw;
};

}  // namespace Gui
