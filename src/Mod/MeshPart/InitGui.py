# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2002 Jürgen Riegel <juergen.riegel@web.de>
# SPDX-FileNotice: Part of the FreeCAD project.

# MeshPart gui init module
# (c) 2003 Jürgen Riegel
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
################################################################################/


class MeshPartWorkbench(Workbench):
    "MeshPart workbench object"

    Icon = """
            /* XPM */
            static const char *MeshPart_Box[]={
            "16 16 3 1",
            ". c None",
            "# c #000000",
            "a c #c6c642",
            "................",
            ".......#######..",
            "......#aaaaa##..",
            ".....#aaaaa###..",
            "....#aaaaa##a#..",
            "...#aaaaa##aa#..",
            "..#aaaaa##aaa#..",
            ".########aaaa#..",
            ".#aaaaa#aaaaa#..",
            ".#aaaaa#aaaa##..",
            ".#aaaaa#aaa##...",
            ".#aaaaa#aa##....",
            ".#aaaaa#a##... .",
            ".#aaaaa###......",
            ".########.......",
            "................"};
            """
    MenuText = "MeshPart"
    ToolTip = "MeshPart workbench"

    def Initialize(self):
        # load the module
        import MeshPartGui
        import MeshPart

    def GetClassName(self):
        return "MeshPartGui::Workbench"


# Gui.addWorkbench(MeshPartWorkbench())
