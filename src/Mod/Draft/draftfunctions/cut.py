# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileCopyrightText: 2020 Eliud Cabrera Castillo <e.cabrera-castillo@tum.de>
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
"""Provides functions to create a cut object from two objects."""
## @package cut
# \ingroup draftfunctions
# \brief Provides functions to create a cut object from two objects.

## \addtogroup draftfunctions
# @{
import FreeCAD as App
import draftutils.gui_utils as gui_utils

from draftutils.translate import translate
from draftutils.messages import _err


def cut(object1, object2):
    """Return a cut object made from the difference of the 2 given objects.

    Parameters
    ----------
    object1: Part::Feature
        Any object with a `Part::TopoShape`.

    object2: Part::Feature
        Any object with a `Part::TopoShape`.

    Returns
    -------
    Part::Cut
        The resulting cut object.

    None
        If there is a problem and the new object can't be created.
    """
    if not App.activeDocument():
        _err(translate("draft", "No active document. Aborting."))
        return

    obj = App.activeDocument().addObject("Part::Cut", "Cut")
    obj.Base = object1
    obj.Tool = object2

    if App.GuiUp:
        gui_utils.format_object(obj, object1)
        gui_utils.select(obj)
        object1.ViewObject.Visibility = False
        object2.ViewObject.Visibility = False

    return obj


## @}
