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
"""Provides functions to create ShapeString objects."""
## @package make_shapestring
# \ingroup draftmake
# \brief Provides functions to create ShapeString objects.

## \addtogroup draftmake
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils

from draftobjects.shapestring import ShapeString

if App.GuiUp:
    from draftviewproviders.view_shapestring import ViewProviderShapeString


def make_shapestring(String, FontFile, Size=100, Tracking=0):
    """ShapeString(Text,FontFile,[Height],[Track])

    Turns a text string into a Compound Shape

    Parameters
    ----------
    majradius :
        Major radius of the ellipse.

    """
    if not App.ActiveDocument:
        App.Console.PrintError("No active document. Aborting\n")
        return

    obj = App.ActiveDocument.addObject("Part::Part2DObjectPython", "ShapeString")
    ShapeString(obj)
    obj.String = String
    obj.FontFile = FontFile
    obj.Size = Size
    obj.Tracking = Tracking

    if App.GuiUp:
        ViewProviderShapeString(obj.ViewObject)
        gui_utils.format_object(obj)
        obrep = obj.ViewObject
        if "PointSize" in obrep.PropertiesList:
            obrep.PointSize = 1  # hide the segment end points
        gui_utils.select(obj)
    obj.recompute()
    return obj


makeShapeString = make_shapestring

## @}
