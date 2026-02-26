# SPDX-FileCopyrightText: 2002,2003 Jürgen Riegel <juergen.riegel@web.de>
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

# TechDraw gui init module
#
# Gathering all the information to start FreeCAD
# This is the second one of three init scripts, the third one
# runs when the gui is up


class TechDrawWorkbench(Workbench):
    "Technical Drawing workbench object"

    def __init__(self):
        self.__class__.Icon = (
            FreeCAD.getResourceDir()
            + "Mod/TechDraw/Resources/icons/preferences-techdraw.svg"
        )
        self.__class__.MenuText = "TechDraw"
        self.__class__.ToolTip = "Technical Drawing workbench"

    def Initialize(self):
        # load the module

        import TechDrawGui

        try:
            import TechDrawTools
        except ImportError as err:
            FreeCAD.Console.PrintError(
                "Features from TechDrawTools package cannot be loaded. {err}\n".format(
                    err=str(err)
                )
            )

    def GetClassName(self):
        return "TechDrawGui::Workbench"


Gui.addWorkbench(TechDrawWorkbench())

# Append the export handler
FreeCAD.addExportType("Technical Drawing (*.svg *.dxf *.pdf)", "TechDrawGui")

FreeCAD.__unit_test__ += ["TestTechDrawGui"]

