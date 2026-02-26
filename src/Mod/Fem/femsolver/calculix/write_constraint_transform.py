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

__title__ = "FreeCAD FEM calculix constraint transform"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"


import FreeCAD

from femtools import geomtools


def get_analysis_types():
    return "all"  # write for all analysis types


def get_sets_name():
    return "constraints_transform_node_sets"


def get_constraint_title():
    return "Transform Constraints"


def get_before_write_meshdata_constraint():
    return ""


def get_after_write_meshdata_constraint():
    return ""


def get_before_write_constraint():
    return ""


def get_after_write_constraint():
    return ""


def write_meshdata_constraint(f, femobj, trans_obj, ccxwriter):
    if trans_obj.TransformType == "Rectangular":
        f.write(f"*NSET,NSET=Rect{trans_obj.Name}\n")
    elif trans_obj.TransformType == "Cylindrical":
        f.write(f"*NSET,NSET=Cylin{trans_obj.Name}\n")
    for n in femobj["Nodes"]:
        f.write(f"{n},\n")


def write_constraint(f, femobj, trans_obj, ccxwriter):

    # floats read from ccx should use {:.13G}, see comment in writer module

    trans_name = ""
    trans_type = ""
    if trans_obj.TransformType == "Rectangular":
        trans_name = "Rect"
        trans_type = "R"
        x = trans_obj.Rotation * FreeCAD.Vector(1, 0, 0)
        y = trans_obj.Rotation * FreeCAD.Vector(0, 1, 0)
        coords = list(x) + list(y)
    elif trans_obj.TransformType == "Cylindrical":
        trans_name = "Cylin"
        trans_type = "C"
        base = trans_obj.BasePoint
        axis = trans_obj.Axis
        coords = list(base) + list(base + axis)
    f.write(
        "*TRANSFORM, NSET={}{}, TYPE={}\n".format(
            trans_name,
            trans_obj.Name,
            trans_type,
        )
    )
    f.write(
        "{:.13G},{:.13G},{:.13G},{:.13G},{:.13G},{:.13G}\n".format(
            coords[0],
            coords[1],
            coords[2],
            coords[3],
            coords[4],
            coords[5],
        )
    )
