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
"""Provides functions to create an extrusion object from a profile."""
## @package extrude
# \ingroup draftfunctions
# \brief Provides functions to create an extrusion object from a profile.

## \addtogroup draftfunctions
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils


def extrude(obj, vector, solid=False):
    """extrude(object, vector, [solid])

    Create a Part::Extrusion object from a given object.

    Parameters
    ----------
    obj :

    vector : Base.Vector
        The extrusion direction and module.

    solid : bool
        TODO: describe.
    """
    if not App.ActiveDocument:
        App.Console.PrintError("No active document. Aborting\n")
        return
    newobj = App.ActiveDocument.addObject("Part::Extrusion", "Extrusion")
    newobj.Base = obj
    newobj.Dir = vector
    newobj.Solid = solid
    if App.GuiUp:
        obj.ViewObject.Visibility = False
        gui_utils.format_object(newobj, obj)
        gui_utils.select(newobj)

    return newobj


## @}
