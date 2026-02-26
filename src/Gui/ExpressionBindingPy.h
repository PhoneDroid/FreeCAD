// SPDX-FileCopyrightText: 2020 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <CXX/Extensions.hxx>

class QWidget;
namespace Gui
{
class ExpressionBinding;

class ExpressionBindingPy: public Py::PythonClass<ExpressionBindingPy>
{
public:
    static void init_type();  // announce properties and methods

    ExpressionBindingPy(Py::PythonClassInstance* self, Py::Tuple& args, Py::Dict& kwds);
    ~ExpressionBindingPy() override;

    Py::Object repr() override;

    Py::Object bind(const Py::Tuple&);
    Py::Object isBound();
    Py::Object apply(const Py::Tuple&);
    Py::Object hasExpression();
    Py::Object autoApply();
    Py::Object setAutoApply(const Py::Tuple&);

private:
    static ExpressionBinding* asBinding(QWidget*);

private:
    ExpressionBinding* expr;
};

}  // namespace Gui
