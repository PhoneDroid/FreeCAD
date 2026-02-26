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
"""Provides functions to join wires together into a single wire."""
## @package join
# \ingroup draftfunctions
# \brief Provides functions to join wires together into a single wire.

## \addtogroup draftfunctions
# @{
import FreeCAD as App
import DraftVecUtils


def join_wires(wires, joinAttempts=0):
    """join_wires(objects): merges a set of wires where possible, if any of those
    wires have a coincident start and end point"""
    wires = list(wires)
    if joinAttempts > len(wires):
        return
    joinAttempts += 1
    for wire1Index, wire1 in enumerate(wires):
        for wire2Index, wire2 in enumerate(wires):
            if wire2Index <= wire1Index:
                continue
            if join_two_wires(wire1, wire2):
                wires.pop(wire2Index)
                break
    join_wires(wires, joinAttempts)
    return wires


joinWires = join_wires


def join_two_wires(wire1, wire2):
    """join_two_wires(object, object): joins two wires if they share a common
    point as a start or an end.
    """
    wire1AbsPoints = [wire1.Placement.multVec(point) for point in wire1.Points]
    wire2AbsPoints = [wire2.Placement.multVec(point) for point in wire2.Points]
    if (
        DraftVecUtils.equals(wire1AbsPoints[0], wire2AbsPoints[-1])
        and DraftVecUtils.equals(wire1AbsPoints[-1], wire2AbsPoints[0])
    ) or (
        DraftVecUtils.equals(wire1AbsPoints[0], wire2AbsPoints[0])
        and DraftVecUtils.equals(wire1AbsPoints[-1], wire2AbsPoints[-1])
    ):
        wire2AbsPoints.pop()
        wire1.Closed = True
    elif DraftVecUtils.equals(wire1AbsPoints[0], wire2AbsPoints[0]):
        wire1AbsPoints = list(reversed(wire1AbsPoints))
    elif DraftVecUtils.equals(wire1AbsPoints[0], wire2AbsPoints[-1]):
        wire1AbsPoints = list(reversed(wire1AbsPoints))
        wire2AbsPoints = list(reversed(wire2AbsPoints))
    elif DraftVecUtils.equals(wire1AbsPoints[-1], wire2AbsPoints[-1]):
        wire2AbsPoints = list(reversed(wire2AbsPoints))
    elif DraftVecUtils.equals(wire1AbsPoints[-1], wire2AbsPoints[0]):
        pass
    else:
        return False
    wire2AbsPoints.pop(0)
    wire1.Points = [wire1.Placement.inverse().multVec(point) for point in wire1AbsPoints] + [
        wire1.Placement.inverse().multVec(point) for point in wire2AbsPoints
    ]
    App.ActiveDocument.removeObject(wire2.Name)
    return True


joinTwoWires = join_two_wires

## @}
