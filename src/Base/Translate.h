// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2018 Werner Mayer <wmayer@users.sourceforge.net>
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
#include <QTranslator>
#include <memory>
#include <list>
#include <FCGlobal.h>

namespace Py
{
class Object;
class Tuple;
}  // namespace Py

namespace Base
{

class BaseExport Translate: public Py::ExtensionModule<Translate>  // NOLINT
{
public:
    Translate();
    ~Translate() override;

private:
    Py::Object translate(const Py::Tuple& args);
    Py::Object translateNoop(const Py::Tuple& args);
    Py::Object translateNoop3(const Py::Tuple& args);
    Py::Object trNoop(const Py::Tuple& args);
    Py::Object installTranslator(const Py::Tuple& args);
    Py::Object removeTranslators(const Py::Tuple& args);

private:
    std::list<std::shared_ptr<QTranslator>> translators;
};

}  // namespace Base
