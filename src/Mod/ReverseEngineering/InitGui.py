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
################################################################################/

# ReverseEngineering gui init module
#
# Gathering all the information to start FreeCAD
# This is the second one of three init scripts, the third one
# runs when the gui is up


class ReverseEngineeringWorkbench(Workbench):
    "ReverseEngineering workbench object"

    def __init__(self):
        self.__class__.Icon = (
            FreeCAD.getResourceDir()
            + "Mod/ReverseEngineering/Resources/icons/ReverseEngineeringWorkbench.svg"
        )
        self.__class__.MenuText = "Reverse Engineering"
        self.__class__.ToolTip = "Reverse Engineering workbench"

    def Initialize(self):
        # load the module
        import ReverseEngineeringGui
        import ReverseEngineering

    def GetClassName(self):
        return "ReverseEngineeringGui::Workbench"


Gui.addWorkbench(ReverseEngineeringWorkbench())
