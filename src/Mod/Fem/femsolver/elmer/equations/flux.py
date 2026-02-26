# SPDX-FileCopyrightText: 2017 Markus Hovorka <m.hovorka@live.de>
# SPDX-FileCopyrightText: 2020 Bernd Hahnebach <bernd@bimstatik.org>
# SPDX-FileCopyrightText: 2022 Uwe Stöhr <uwestoehr@lyx.org>
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

__title__ = "FreeCAD FEM solver Elmer equation object Flux"
__author__ = "Markus Hovorka, Uwe Stöhr"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{

from femtools import femutils
from ... import equationbase
from . import linear

COEFFICIENTS = ["Heat Conductivity", "None"]
VARIABLES = ["Potential", "Temperature"]


def create(doc, name="Flux"):
    return femutils.createObject(doc, name, Proxy, ViewProxy)


class Proxy(linear.Proxy, equationbase.FluxProxy):

    Type = "Fem::EquationElmerFlux"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyBool",
            "AverageWithinMaterials",
            "Flux",
            (
                "Enforces continuity within the same material\n"
                "in the 'Discontinuous Galerkin' discretization"
            ),
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool", "CalculateFlux", "Flux", "Computes flux vector", locked=True
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateFluxAbs",
            "Flux",
            "Computes absolute of flux vector",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateFluxMagnitude",
            "Flux",
            "Computes magnitude of flux vector field",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateGrad",
            "Flux",
            "Select calculation of gradient",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateGradAbs",
            "Flux",
            "Computes absolute of gradient field",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "CalculateGradMagnitude",
            "Flux",
            "Computes magnitude of gradient field",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "DiscontinuousGalerkin",
            "Flux",
            (
                "Enable if standard Galerkin approximation leads to\n"
                "unphysical results when there are discontinuities"
            ),
            locked=True,
        )
        obj.addProperty(
            "App::PropertyBool",
            "EnforcePositiveMagnitude",
            "Flux",
            (
                "If true, negative values of computed magnitude fields\n"
                "are a posteriori set to zero."
            ),
            locked=True,
        )
        obj.addProperty(
            "App::PropertyEnumeration",
            "FluxCoefficient",
            "Flux",
            "Proportionality coefficient\nto compute the flux",
            locked=True,
        )
        obj.addProperty(
            "App::PropertyEnumeration",
            "FluxVariable",
            "Flux",
            "Variable name for flux calculation",
            locked=True,
        )

        obj.CalculateFlux = True
        # set defaults according to the Elmer manual
        obj.FluxCoefficient = COEFFICIENTS
        obj.FluxCoefficient = "Heat Conductivity"
        obj.FluxVariable = VARIABLES
        obj.FluxVariable = "Temperature"
        # Electrostatic has priority 10, Heat has 20 and Flux needs
        # to be solved before these equations
        # therefore set priority to 25
        obj.Priority = 25


class ViewProxy(linear.ViewProxy, equationbase.FluxViewProxy):
    pass


##  @}
