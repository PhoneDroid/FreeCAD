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

__title__ = "FreeCAD FEM calculix constraint pressure"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

import FreeCAD


def get_analysis_types():
    return ["buckling", "static", "thermomech"]


def get_sets_name():
    return "constraints_pressure_element_face_loads"


def get_before_write_meshdata_constraint():
    return ""


def get_after_write_meshdata_constraint():
    return ""


def write_meshdata_constraint(f, femobj, prs_obj, ccxwriter):

    # floats read from ccx should use {:.13G}, see comment in writer module

    if prs_obj.EnableAmplitude:
        f.write(f"*DLOAD, AMPLITUDE={prs_obj.Name}\n")
    else:
        f.write("*DLOAD\n")
    rev = -1 if prs_obj.Reversed else 1
    # the pressure has to be output in MPa
    pressure = prs_obj.Pressure.getValueAs("MPa").Value
    pressure *= rev
    for feat, surf, is_sub_el in femobj["PressureFaces"]:
        f.write("** {0.Name}.{1[0]}\n".format(*feat))
        if is_sub_el:
            for elem, fno in surf:
                f.write(f"{elem},P{fno},{pressure}\n")
        else:
            for elem in surf:
                f.write(f"{elem},P,{-1*pressure}\n")
