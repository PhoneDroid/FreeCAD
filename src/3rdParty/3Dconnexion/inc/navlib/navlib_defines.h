// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2014-2023 3Dconnexion
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

// This header file defines the macros used in the 3dconnexion interface and header files.

#ifndef NAVLIB_DEFINES_H_INCLUDED_
#define NAVLIB_DEFINES_H_INCLUDED_

// Invalid handle
#define INVALID_NAVLIB_HANDLE 0

// Navlib facility used to generate error codes
// Note this is identical to FACILITY_ITF on windows
#define FACILITY_NAVLIB 4

// resources
#define NAVLIB_IDB_ManualPivot 0x6004
#define NAVLIB_IDB_AutoPivot 0x6005

#if defined(__cplusplus)
#define NAVLIB_BEGIN_ namespace navlib {
#define NAVLIB_END_ }
#define NAVLIB_ ::navlib::
#define USING_NAVLIB_ using namespace navlib;
#else
#define NAVLIB_BEGIN_
#define NAVLIB_END_
#define NAVLIB_
#define USING_NAVLIB_
#endif

#if defined(_MSC_VER) && defined(NAVLIB_EXPORTS)
#define NAVLIB_DLLAPI_ extern "C" __declspec(dllexport)
#elif defined(__cplusplus)
#define NAVLIB_DLLAPI_ extern "C"
#else
#define NAVLIB_DLLAPI_
#endif

#ifndef NOEXCEPT
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#ifdef _NOEXCEPT
#define NOEXCEPT _NOEXCEPT
#else
#define NOEXCEPT
#endif
#else
#define NOEXCEPT noexcept
#endif
#endif

#endif // NAVLIB_DEFINES_H_INCLUDED_
