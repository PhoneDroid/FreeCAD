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

__title__ = "FreeCAD FEM calculix constraint temperature"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

import FreeCAD


def get_analysis_types():
    return ["thermomech"]


# name must substitute underscores for whitespace (#7360)
def get_sets_name():
    return "constraints_temperature_node_sets"


def get_constraint_title():
    return "Fixed temperature constraint applied"


def write_meshdata_constraint(f, femobj, temp_obj, ccxwriter):
    f.write(f"*NSET,NSET={temp_obj.Name}\n")
    for n in femobj["Nodes"]:
        f.write(f"{n},\n")


def get_before_write_meshdata_constraint():
    return ""


def get_after_write_meshdata_constraint():
    return ""


def get_before_write_constraint():
    return ""


def get_after_write_constraint():
    return ""


def write_constraint(f, femobj, temp_obj, ccxwriter):

    # floats read from ccx should use {:.13G}, see comment in writer module

    NumberOfNodes = len(femobj["Nodes"])
    if temp_obj.EnableAmplitude:
        temp_amplitude = f", AMPLITUDE={temp_obj.Name}"
    else:
        temp_amplitude = ""
    if temp_obj.ConstraintType == "Temperature":
        f.write(f"*BOUNDARY{temp_amplitude}\n")
        f.write(
            "{},11,11,{}\n".format(
                temp_obj.Name, FreeCAD.Units.Quantity(temp_obj.Temperature.getValueAs("K"))
            )
        )
        f.write("\n")
    elif temp_obj.ConstraintType == "CFlux":
        f.write(f"*CFLUX{temp_amplitude}\n")
        # CFLUX has to be specified in mW
        f.write(
            "{},11,{}\n".format(
                temp_obj.Name,
                FreeCAD.Units.Quantity(temp_obj.CFlux.getValueAs("mW")) / NumberOfNodes,
            )
        )
        f.write("\n")
