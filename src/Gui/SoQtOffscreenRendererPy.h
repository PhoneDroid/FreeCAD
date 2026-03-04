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

#include <CXX/Extensions.hxx>

#include "SoFCOffscreenRenderer.h"


namespace Gui
{

class SoQtOffscreenRendererPy: public Py::PythonClass<SoQtOffscreenRendererPy>
{
public:
    static void init_type();

    SoQtOffscreenRendererPy(Py::PythonClassInstance* self, Py::Tuple& args, Py::Dict& kwds);
    ~SoQtOffscreenRendererPy() override;

    Py::Object repr() override;

    Py::Object setViewportRegion(const Py::Tuple&);
    Py::Object getViewportRegion();

    Py::Object setBackgroundColor(const Py::Tuple&);
    Py::Object getBackgroundColor();

    Py::Object setNumPasses(const Py::Tuple&);
    Py::Object getNumPasses();

    Py::Object setInternalTextureFormat(const Py::Tuple&);
    Py::Object getInternalTextureFormat();

    Py::Object render(const Py::Tuple&);

    Py::Object writeToImage(const Py::Tuple&);
    Py::Object getWriteImageFiletypeInfo();

private:
    SoQtOffscreenRenderer renderer;
};

}  // namespace Gui
