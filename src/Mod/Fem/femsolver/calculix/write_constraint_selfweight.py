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

__title__ = "FreeCAD FEM calculix constraint selfweight"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"


def get_analysis_types():
    return ["buckling", "static", "thermomech"]


def get_constraint_title():
    return "Self weight Constraint"


def get_before_write_constraint():
    return ""


def get_after_write_constraint():
    return ""


def write_constraint(f, femobj, selwei_obj, ccxwriter):

    # floats read from ccx should use {:.13G}, see comment in writer module

    f.write("*DLOAD\n")
    f.write(
        # elset, GRAV, magnitude, direction x, dir y ,dir z
        "{},GRAV,{:.13G},{:.13G},{:.13G},{:.13G}\n".format(
            ccxwriter.ccx_eall,
            selwei_obj.GravityAcceleration.getValueAs(
                "mm/s^2"
            ).Value,  # actual magnitude of gravity vector
            selwei_obj.GravityDirection.x,  # coordinate x of normalized gravity vector
            selwei_obj.GravityDirection.y,  # y
            selwei_obj.GravityDirection.z,  # z
        )
    )
    f.write("\n")


# grav (erdbeschleunigung) is equal for all elements
# should be only one constraint
# different element sets for different density
# are written in the material element sets already
