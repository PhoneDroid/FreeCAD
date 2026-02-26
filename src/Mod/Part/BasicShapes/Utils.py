# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2023 Werner Mayer <wmayer@users.sourceforge.net>
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

__title__ = "BasicShapes.Utils"
__author__ = "Werner Mayer"
__url__ = "https://www.freecad.org"
__doc__ = "Utilities for shapes"


import Part


def makeCompoundFromPoints(geometry, distance=1.0):
    """Get sampled points from geometry and create a compound."""
    try:
        points = geometry.getPropertyOfGeometry().getPoints(distance)[0]
        return Part.makeCompound([Part.Point(m).toShape() for m in points])
    except AttributeError:
        return None


def showCompoundFromPoints(geometry, distance=1.0):
    """Create a compound from geometry and show it."""
    try:
        compound = makeCompoundFromPoints(geometry, distance)
        return Part.show(compound, geometry.Label + "_pts")
    except AttributeError:
        return None
