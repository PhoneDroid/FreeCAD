#!/usr/bin/env python
# SPDX-FileCopyrightText: 2024 Wanderer Fan <wandererfan@gmail.com>
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
#
# updates any leader lines in the current document from pre-v0.22 coordinates
# to v0.22+ coordinates.

# usage: open the document to be converted in FreeCAD then run this macro and
#        save the result.


import TechDraw

RezFactor = 10.0

for obj in FreeCAD.ActiveDocument.Objects:
    print("obj: {}".format(obj.Name))
    if obj.isDerivedFrom("TechDraw::DrawLeaderLine"):
        pointsAll = obj.WayPoints
        newPoints = list()
        for point in pointsAll:
            point = point / RezFactor
            newPoints.append(point)
        obj.WayPoints = newPoints

print("conversion complete")
