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

#include <memory>
#include <FCGlobal.h>

using PyObject = struct _object;

namespace Base
{

class BaseExport BindingManager
{
public:
    static BindingManager& instance();

    bool hasWrapper(const void* cptr);

    void registerWrapper(const void* cptr, PyObject* pyObj);
    void releaseWrapper(const void* cptr, PyObject* pyObj);

    PyObject* retrieveWrapper(const void* cptr);

    BindingManager(const BindingManager&) = delete;
    BindingManager(BindingManager&&) = delete;
    BindingManager& operator=(const BindingManager&) = delete;
    BindingManager& operator=(BindingManager&&) = delete;

private:
    BindingManager();
    ~BindingManager();

    struct BindingManagerPrivate;
    std::unique_ptr<BindingManagerPrivate> p;
};

}  // namespace Base
