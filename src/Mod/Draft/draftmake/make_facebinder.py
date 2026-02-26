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
"""Provides functions to create Facebinder objects."""
## @package make_facebinder
# \ingroup draftmake
# \brief Provides functions to create Facebinder objects.

## \addtogroup draftmake
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils

from draftobjects.facebinder import Facebinder

if App.GuiUp:
    from draftviewproviders.view_facebinder import ViewProviderFacebinder


def make_facebinder(selectionset, name="Facebinder"):
    """make_facebinder(selectionset, [name])

    Creates a Facebinder object from a selection set.

    Parameters
    ----------
    selectionset :
        Only faces will be added.

    name : string (default = "Facebinder")
        Name of the created object
    """
    if not App.ActiveDocument:
        App.Console.PrintError("No active document. Aborting\n")
        return
    if not isinstance(selectionset, list):
        selectionset = [selectionset]
    fb = App.ActiveDocument.addObject("Part::FeaturePython", name)
    Facebinder(fb)
    if App.GuiUp:
        ViewProviderFacebinder(fb.ViewObject)
    faces = []  # unused variable?
    fb.Proxy.addSubobjects(fb, selectionset)
    gui_utils.select(fb)
    return fb


makeFacebinder = make_facebinder

## @}
