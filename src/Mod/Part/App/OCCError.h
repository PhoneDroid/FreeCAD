// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2014 Sebastian Hoogen <github@sebastianhoogen.de>
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

#include <Standard_Failure.hxx>
#include <Standard_Version.hxx>

#include <Base/Exception.h>
#include <Mod/Part/PartGlobal.h>


namespace Part
{
PartExport extern PyObject* PartExceptionOCCError;
PartExport extern PyObject* PartExceptionOCCDomainError;
PartExport extern PyObject* PartExceptionOCCRangeError;
PartExport extern PyObject* PartExceptionOCCConstructionError;
PartExport extern PyObject* PartExceptionOCCDimensionError;


#define PY_TRY try

/// see docu of PY_TRY
#define _PY_CATCH_OCC(R) \
    catch (Standard_Failure & e) \
    { \
        std::string str; \
        Standard_CString msg = e.GetMessageString(); \
        str += typeid(e).name(); \
        str += " "; \
        if (msg) { \
            str += msg; \
        } \
        else { \
            str += "No OCCT Exception Message"; \
        } \
        _Py_Error(R, Part::PartExceptionOCCError, str.c_str()); \
    } \
    _PY_CATCH(R)
}  // namespace Part

#define PY_CATCH_OCC _PY_CATCH_OCC(return (NULL))
