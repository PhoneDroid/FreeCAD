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
"""Provides functions to create Shape2DView objects."""
## @package make_shape2dview
# \ingroup draftmake
# \brief Provides functions to create Shape2DView objects.

## \addtogroup draftmake
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils

from draftobjects.shape2dview import Shape2DView

if App.GuiUp:
    from draftviewproviders.view_base import ViewProviderDraftAlt


def make_shape2dview(baseobj, projectionVector=None, facenumbers=[]):
    """make_shape2dview(object, [projectionVector], [facenumbers])

    Add a 2D shape to the document, which is a 2D projection of the given object.

    Parameters
    ----------
    object :
        TODO: Describe

    projectionVector : Base.Vector
        Custom vector for the projection

    facenumbers : [] TODO: Describe
        A list of face numbers to be considered in individual faces mode.
    """
    if not App.ActiveDocument:
        App.Console.PrintError("No active document. Aborting\n")
        return
    obj = App.ActiveDocument.addObject("Part::Part2DObjectPython", "Shape2DView")
    Shape2DView(obj)
    if App.GuiUp:
        ViewProviderDraftAlt(obj.ViewObject)
    obj.Base = baseobj
    if projectionVector:
        obj.Projection = projectionVector
    if facenumbers:
        obj.FaceNumbers = facenumbers
    gui_utils.select(obj)

    return obj


makeShape2DView = make_shape2dview

## @}
