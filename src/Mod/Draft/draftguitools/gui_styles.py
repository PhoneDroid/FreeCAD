# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2010 Ken Cline <cline@frii.com>
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

"""Provides GUI tools to apply styles to objects."""
## @package gui_styles
# \ingroup draftguitools
# \brief Provides GUI tools to apply styles to objects.

## \addtogroup draftguitools
# @{
from PySide.QtCore import QT_TRANSLATE_NOOP

import FreeCADGui as Gui

from draftguitools import gui_base_original
from draftutils.translate import translate
from draftutils import groups


class ApplyStyle(gui_base_original.Modifier):
    """Gui Command for the ApplyStyle tool."""

    def GetResources(self):
        """Set icon, menu and tooltip."""
        return {
            "Pixmap": "Draft_Apply",
            "MenuText": QT_TRANSLATE_NOOP("Draft_ApplyStyle", "Apply Current Style"),
            "ToolTip": QT_TRANSLATE_NOOP(
                "Draft_ApplyStyle", "Applies the current style to the selected objects and groups"
            ),
        }

    def IsActive(self):
        return bool(Gui.Selection.getSelection())

    def Activated(self):
        """Execute when the command is called."""
        super().Activated(name="Apply style")
        objs = Gui.Selection.getSelection()
        if objs:
            objs = groups.get_group_contents(objs, addgroups=True, spaces=True, noarchchild=True)
            Gui.addModule("Draft")
            cmd_list = [
                "doc = FreeCAD.ActiveDocument",
                "Draft.apply_current_style(["
                + ", ".join(["doc." + obj.Name for obj in objs])
                + "])",
                "doc.recompute()",
            ]
            self.commit(translate("draft", "Change Style"), cmd_list)
        self.finish()


Gui.addCommand("Draft_ApplyStyle", ApplyStyle())

## @}
