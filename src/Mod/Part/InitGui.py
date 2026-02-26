# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2002 Jürgen Riegel <juergen.riegel@web.de>
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
"""Initialization of the Part Workbench graphical interface."""

import FreeCAD as App
import FreeCADGui as Gui
import os


class PartWorkbench(Gui.Workbench):
    """Part workbench object."""

    def __init__(self):
        self.__class__.Icon = os.path.join(
            App.getResourceDir(), "Mod", "Part", "Resources", "icons", "PartWorkbench.svg"
        )
        self.__class__.MenuText = "Part"
        self.__class__.ToolTip = "Part workbench"

    def Initialize(self):
        # load the module
        import PartGui

        try:
            import BasicShapes.CommandShapes
        except ImportError as err:
            App.Console.PrintError(
                "'BasicShapes' package cannot be loaded. " "{err}\n".format(err=str(err))
            )

        try:
            import CompoundTools._CommandCompoundFilter
            import CompoundTools._CommandExplodeCompound
        except ImportError as err:
            App.Console.PrintError(
                "'CompoundTools' package cannot be loaded. " "{err}\n".format(err=str(err))
            )

        try:
            bop = __import__("BOPTools")
            bop.importAll()
            bop.addCommands()
            PartGui.BOPTools = bop
        except Exception as err:
            App.Console.PrintError(
                "'BOPTools' package cannot be loaded. " "{err}\n".format(err=str(err))
            )

    def GetClassName(self):
        return "PartGui::Workbench"


Gui.addWorkbench(PartWorkbench())

App.__unit_test__ += ["TestPartGui"]
