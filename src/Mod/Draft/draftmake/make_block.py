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
"""Provides functions to create Block objects."""
## @package make_block
# \ingroup draftmake
# \brief Provides functions to create Block objects.

## \addtogroup draftmake
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils

from draftobjects.block import Block

if App.GuiUp:
    from draftviewproviders.view_base import ViewProviderDraftPart


def make_block(objectslist):
    """make_block(objectslist)

    Creates a Draft Block from the given objects.

    Parameters
    ----------
    objectlist : list
        Major radius of the ellipse.

    """
    if not App.ActiveDocument:
        App.Console.PrintError("No active document. Aborting\n")
        return
    obj = App.ActiveDocument.addObject("Part::FeaturePython", "Block")
    obj.addExtension("Part::AttachExtensionPython")
    Block(obj)
    obj.Components = objectslist
    if App.GuiUp:
        ViewProviderDraftPart(obj.ViewObject)
        for o in objectslist:
            o.ViewObject.Visibility = False
        gui_utils.select(obj)
    return obj


makeBlock = make_block

## @}
