# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileNotice: Part of the FreeCAD project.

################################################################################
#                                                                              #
#   FreeCAD is free software: you can redistribute it and/or modify            #
#   it under the terms of the GNU Lesser General Public License as             #
#   published by the Free Software Foundation, either version 2.1              #
#   of the License, or (at your option) any later version.                     #
#                                                                              #
#   FreeCAD is distributed in the hope that it will be useful,                 #
#   but WITHOUT ANY WARRANTY; without even the implied warranty                #
#   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                    #
#   See the GNU Lesser General Public License for more details.                #
#                                                                              #
#   You should have received a copy of the GNU Lesser General Public           #
#   License along with FreeCAD. If not, see https://www.gnu.org/licenses       #
#                                                                              #
################################################################################
"""Modules that contain functions that use and manipulate shapes.

These functions provide support for dealing with the custom objects
defined within the workbench.
The functions are meant to be used in the creation step of the objects,
or to manipulate the created shapes, principally by the functions
in the `draftmake` package.

These functions should deal with the internal shapes of the objects,
and their special properties; they shouldn't be very generic.

These functions may be useful for other programmers in their own macros
or workbenches. These functions may not necessarily be exposed as
part of the Draft workbench programming interface yet.

These functions were previously defined in the big `DraftGeomUtils` module.
"""
## \defgroup draftgeoutils draftgeoutils
# \ingroup DRAFT
# \brief Functions that are meant to handle different geometrical operations
