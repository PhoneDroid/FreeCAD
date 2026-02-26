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

__title__ = "FreeCAD FEM calculix write inpfile material and geometry sets"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"


def write_femelement_matgeosets(f, ccxwriter):

    # write mat_geo_sets to file
    f.write("\n{}\n".format(59 * "*"))
    f.write("** Element sets for materials and FEM element type (solid, shell, beam, fluid)\n")

    for matgeoset in ccxwriter.mat_geo_sets:

        f.write("*ELSET,ELSET={}\n".format(matgeoset["ccx_elset_name"]))

        if isinstance(matgeoset["ccx_elset"], str):
            f.write("{}\n".format(matgeoset["ccx_elset"]))
        else:
            for elid in matgeoset["ccx_elset"]:
                f.write(str(elid) + ",\n")
