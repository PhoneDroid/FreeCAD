// SPDX-FileCopyrightText: 2007 Jürgen Riegel <juergen.riegel@web.de>
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

#include <FCConfig.h>

#ifdef FC_OS_WIN32
#endif

// standard
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

// STL
#include <algorithm>
#include <regex>
#include <string>
#include <vector>

#ifdef FC_OS_WIN32
# include <windows.h>
# undef small
#endif

// Qt Toolkit
#ifndef _QtAll__
# include <Gui/QtAll.h>
#endif

// OpenCasCade
#include <BRep_Tool.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepLProp_SLProps.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <TopExp.hxx>
#include <TopoDS_Shape.hxx>

// Open Inventor
#include <Inventor/SbVec3f.h>