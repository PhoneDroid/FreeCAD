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

"""Provides GUI tools to repair objects created with older versions."""
## @package gui_heal
# \ingroup draftguitools
# \brief Provides GUI tools to repair objects created with older versions.

## \addtogroup draftguitools
# @{
from PySide.QtCore import QT_TRANSLATE_NOOP

import FreeCADGui as Gui
import Draft
import draftguitools.gui_base as gui_base

from draftutils.translate import translate


class Heal(gui_base.GuiCommandSimplest):
    """The Draft Heal command definition.

    Heal faulty Draft objects saved with an earlier version of the program.

    It inherits `GuiCommandSimplest` to set up the document
    and other behavior. See this class for more information.
    """

    def __init__(self):
        super(Heal, self).__init__(name=translate("draft", "Heal"))

    def GetResources(self):
        """Set icon, menu and tooltip."""
        _tip = ()

        return {
            "Pixmap": "Draft_Heal",
            "MenuText": QT_TRANSLATE_NOOP("Draft_Heal", "Heal"),
            "ToolTip": QT_TRANSLATE_NOOP(
                "Draft_Heal",
                "Heals faulty Draft objects saved with an earlier version of FreeCAD.\nIf an object is selected it tries to heal only that object,\notherwise it tries to heal all objects in the active document.",
            ),
        }

    def Activated(self):
        """Execute when the command is called."""
        super(Heal, self).Activated()

        s = Gui.Selection.getSelection()
        self.doc.openTransaction("Heal")
        if s:
            Draft.heal(s)
        else:
            Draft.heal()
        self.doc.commitTransaction()


Gui.addCommand("Draft_Heal", Heal())

## @}
