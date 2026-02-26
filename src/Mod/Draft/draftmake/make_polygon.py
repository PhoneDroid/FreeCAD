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
"""Provides functions to create Polygon objects."""
## @package make_polygon
# \ingroup draftmake
# \brief Provides functions to create Polygon objects.

## \addtogroup draftmake
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils

from draftobjects.polygon import Polygon
from draftviewproviders.view_base import ViewProviderDraft


def make_polygon(nfaces, radius=1, inscribed=True, placement=None, face=None, support=None):
    """makePolgon(edges,[radius],[inscribed],[placement],[face])

    Creates a polygon object with the given number of edges and radius.

    Parameters
    ----------
    edges : int
        Number of edges of the polygon.

    radius :
        Radius of the control circle.

    inscribed : bool
        Defines is the polygon is inscribed or not into the control circle.

    placement : Base.Placement
        If placement is given, it is used.

    face : bool
        If face is True, the resulting shape is displayed as a face,
        otherwise as a wireframe.

    support :
        TODO: Describe
    """
    if not App.ActiveDocument:
        App.Console.PrintError("No active document. Aborting\n")
        return
    if nfaces < 3:
        return None
    obj = App.ActiveDocument.addObject("Part::Part2DObjectPython", "Polygon")
    Polygon(obj)
    obj.FacesNumber = nfaces
    obj.Radius = radius
    if face is not None:
        obj.MakeFace = face
    if inscribed:
        obj.DrawMode = "inscribed"
    else:
        obj.DrawMode = "circumscribed"
    obj.AttachmentSupport = support
    if placement:
        obj.Placement = placement
    if App.GuiUp:
        ViewProviderDraft(obj.ViewObject)
        gui_utils.format_object(obj)
        gui_utils.select(obj)

    return obj


makePolygon = make_polygon

## @}
