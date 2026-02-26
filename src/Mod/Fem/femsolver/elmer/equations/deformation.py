# SPDX-FileCopyrightText: 2023 Uwe Stöhr <uwestoehr@lyx.org>
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

__title__ = "FreeCAD FEM solver Elmer equation object Deformation"
__author__ = "Uwe Stöhr"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{

from femtools import femutils
from . import nonlinear
from ... import equationbase


def create(doc, name="Deformation"):
    return femutils.createObject(doc, name, Proxy, ViewProxy)


class Proxy(nonlinear.Proxy, equationbase.DeformationProxy):

    Type = "Fem::EquationElmerDeformation"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyBool",
            "CalculatePangle",
            "Deformation",
            "Compute principal stress angles",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculatePrincipal",
            "Deformation",
            "Compute principal stress components",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateStrains",
            "Deformation",
            "Compute the strain tensor",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateStresses",
            "Deformation",
            "Compute stress tensor and vanMises",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "InitializeStateVariables",
            "Deformation",
            "See Elmer manual for info",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "MixedFormulation",
            "Deformation",
            "See Elmer manual for info",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "NeoHookeanMaterial",
            "Deformation",
            ("Uses the neo-Hookean material model"),
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "PlaneStress",
            "Equation",
            (
                "Computes solution according to plane\nstress situation.\n"
                "Applies only for 2D geometry."
            ),
            locked=True,
        )
        obj.addProperty(
            "App::PropertyString",
            "Variable",
            "Deformation",
            "Only for a 2D model change the '3' to '2'",
            locked=True,
        )

        obj.Priority = 10
        obj.CalculatePrincipal = True
        obj.CalculateStresses = True
        obj.Variable = "-dofs 3 Displacement"


class ViewProxy(nonlinear.ViewProxy, equationbase.DeformationViewProxy):
    pass


##  @}
