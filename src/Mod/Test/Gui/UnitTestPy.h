// SPDX-FileCopyrightText: 2006 Werner Mayer <wmayer@users.sourceforge.net>
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


namespace TestGui
{

class UnitTestDialog;
class UnitTestDialogPy: public Py::PythonExtension<UnitTestDialogPy>
{
public:
    static void init_type();  // announce properties and methods

    UnitTestDialogPy();
    ~UnitTestDialogPy() override;

    Py::Object repr() override;
    Py::Object getattr(const char*) override;
    int setattr(const char*, const Py::Object&) override;

    Py::Object clearErrorList(const Py::Tuple&);
    Py::Object insertError(const Py::Tuple&);
    Py::Object setUnitTest(const Py::Tuple&);
    Py::Object getUnitTest(const Py::Tuple&);
    Py::Object setStatusText(const Py::Tuple&);
    Py::Object setProgressFrac(const Py::Tuple&);
    Py::Object errorDialog(const Py::Tuple&);
    Py::Object setRunCount(const Py::Tuple&);
    Py::Object setFailCount(const Py::Tuple&);
    Py::Object setErrorCount(const Py::Tuple&);
    Py::Object setRemainCount(const Py::Tuple&);
    Py::Object updateGUI(const Py::Tuple&);
    Py::Object addUnitTest(const Py::Tuple&);
    Py::Object clearUnitTests(const Py::Tuple&);

private:
    using method_varargs_handler = PyObject* (*)(PyObject * _self, PyObject* _args);
    static method_varargs_handler pycxx_handler;
    static PyObject* method_varargs_ext_handler(PyObject* _self, PyObject* _args);
};

}  // namespace TestGui
