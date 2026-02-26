# SPDX-FileCopyrightText: 2021 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "FreeCAD FEM calculix write inpfile footer"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"


import os
import time


def write_footer(f, ccxwriter):

    f.write("\n{}\n".format(59 * "*"))
    f.write("** CalculiX Input file\n")
    f.write(
        "**   written by    --> FreeCAD {}.{}.{}\n".format(
            ccxwriter.fc_ver[0], ccxwriter.fc_ver[1], ccxwriter.fc_ver[2]
        )
    )
    f.write(f"**   written on    --> {time.ctime()}\n")
    f.write(f"**   file name     --> {os.path.basename(ccxwriter.document.FileName)}\n")
    f.write(f"**   analysis name --> {ccxwriter.analysis.Name}\n")
    f.write("**\n")
    f.write("**\n")
    f.write(ccxwriter.units_information)
    f.write("**\n")
