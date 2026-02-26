# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileCopyrightText: 2020 FreeCAD Developers
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
"""Provides functions to split wires into separate wire objects."""
## @package split
# \ingroup draftfunctions
# \brief Provides functions to split wires into separate wire objects.

## \addtogroup draftfunctions
# @{
from draftmake import make_copy
from draftutils import utils


def split(wire, newPoint, edgeIndex):
    if utils.get_type(wire) != "Wire":
        return None
    if wire.Closed:
        return split_closed_wire(wire, edgeIndex)
    return split_open_wire(wire, newPoint, edgeIndex)


def split_closed_wire(wire, edgeIndex):
    wire.Closed = False
    new = make_copy.make_copy(wire)
    if edgeIndex == len(wire.Points):
        new.Points = [wire.Points[0], wire.Points[-1]]
    else:
        new.Points = [wire.Points[edgeIndex - 1], wire.Points[edgeIndex]]
        wire.Points = list(reversed(wire.Points[0:edgeIndex])) + list(
            reversed(wire.Points[edgeIndex:])
        )
    return new


splitClosedWire = split_closed_wire


def split_open_wire(wire, newPoint, edgeIndex):
    new = make_copy.make_copy(wire)
    wire1Points = []
    wire2Points = []
    for index, point in enumerate(wire.Points):
        if index == edgeIndex:
            edge = wire.getSubObject("Edge" + str(edgeIndex))
            newPoint = wire.Placement.inverse().multVec(edge.Curve.projectPoint(newPoint))
            wire1Points.append(newPoint)
            wire2Points.append(newPoint)
            wire2Points.append(point)
        elif index < edgeIndex:
            wire1Points.append(point)
        elif index > edgeIndex:
            wire2Points.append(point)
    wire.Points = wire1Points
    new.Points = wire2Points
    return new


splitOpenWire = split_open_wire

## @}
