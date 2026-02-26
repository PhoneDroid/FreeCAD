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

__title__ = "FreeCAD FEM solver Elmer equation object Magnetodynamic2D"
__author__ = "Uwe Stöhr"
__url__ = "https://www.freecad.org"
#
## \addtogroup FEM
#  @{

from femtools import femutils
from . import nonlinear
from ... import equationbase


def create(doc, name="Magnetodynamic2D"):
    return femutils.createObject(doc, name, Proxy, ViewProxy)


class Proxy(nonlinear.Proxy, equationbase.Magnetodynamic2DProxy):

    Type = "Fem::EquationElmerMagnetodynamic2D"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyBool",
            "IsHarmonic",
            "Magnetodynamic2D",
            "If the magnetic source is harmonically driven",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyFrequency",
            "AngularFrequency",
            "Magnetodynamic2D",
            "Frequency of the driving current",
            locked=True,
        )
        obj.IsHarmonic = False
        obj.AngularFrequency = 0
        obj.Priority = 10

        # the post processor options
        obj.addProperty(
            "App::PropertyBool", "CalculateCurrentDensity", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateElectricField", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateElementalFields", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateHarmonicLoss", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateJouleHeating", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateMagneticFieldStrength",
            "Magnetodynamic2D",
            "",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateMaxwellStress", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateNodalFields", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateNodalForces", "Magnetodynamic2D", "", locked=True
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateNodalHeating", "Magnetodynamic2D", "", locked=True
        )
        obj.CalculateCurrentDensity = False
        obj.CalculateElectricField = False
        # FIXME: at the moment FreeCAD's post processor cannot display elementary field
        # results, therefore disable despite this is by default on in Elmer
        obj.CalculateElementalFields = False
        obj.CalculateHarmonicLoss = False
        obj.CalculateJouleHeating = False
        obj.CalculateMagneticFieldStrength = False
        obj.CalculateMaxwellStress = False
        obj.CalculateNodalFields = True
        obj.CalculateNodalForces = False
        obj.CalculateNodalHeating = False


class ViewProxy(nonlinear.ViewProxy, equationbase.Magnetodynamic2DViewProxy):
    pass


##  @}
