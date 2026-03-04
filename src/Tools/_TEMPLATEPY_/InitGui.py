# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2001 Jürgen Riegel
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

# _TEMPLATEPY_ gui init module

class _TEMPLATEPY_Workbench(Workbench):
    "_TEMPLATEPY_ workbench object"

    Icon = FreeCAD.getResourceDir() + "Mod/_TEMPLATEPY_/Resources/icons/_TEMPLATEPY_Workbench.svg"
    MenuText = "_TEMPLATEPY_"
    ToolTip = "_TEMPLATEPY_ workbench"

    def Initialize(self):
        # load the module
        import _TEMPLATEPY_Gui

        self.appendToolbar("_TEMPLATEPY_", ["_TEMPLATEPY__HelloWorld"])
        self.appendMenu("_TEMPLATEPY_", ["_TEMPLATEPY__HelloWorld"])

    def GetClassName(self):
        return "Gui::PythonWorkbench"


Gui.addWorkbench(_TEMPLATEPY_Workbench())
