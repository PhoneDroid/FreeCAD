# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2004 Werner Mayer <werner.wm.mayer@gmx.de>
# SPDX-FileNotice: Part of the FreeCAD project.

# Mesh gui init module
#
# Gathering all the information to start FreeCAD
# This is the second one of three init scripts, the third one
# runs when the gui is up

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


class MeshWorkbench(Workbench):
    "Mesh workbench object"

    def __init__(self):
        self.__class__.Icon = (
            FreeCAD.getResourceDir() + "Mod/Mesh/Resources/icons/MeshWorkbench.svg"
        )
        self.__class__.MenuText = "Mesh"
        self.__class__.ToolTip = "Mesh workbench"

    def Initialize(self):
        import Mesh
        import MeshGui

        try:
            import flatmesh
            import MeshFlatteningCommand
        except ImportError as e:
            import FreeCAD

            FreeCAD.Console.PrintLog((str(e)))

    def GetClassName(self):
        return "MeshGui::Workbench"


Gui.addWorkbench(MeshWorkbench())
