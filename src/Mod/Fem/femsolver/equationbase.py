# SPDX-FileCopyrightText: 2017 Markus Hovorka <m.hovorka@live.de>
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

__title__ = "FreeCAD FEM solver equation base object"
__author__ = "Markus Hovorka"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{

import FreeCAD

if FreeCAD.GuiUp:
    from pivy import coin


class BaseProxy:

    BaseType = "App::FeaturePython"

    def __init__(self, obj):
        obj.Proxy = self
        obj.addProperty("App::PropertyLinkSubList", "References", "Base", "", locked=True)

    def execute(self, obj):
        return True


class BaseViewProxy:

    def __init__(self, vobj):
        vobj.Proxy = self

    def attach(self, vobj):
        default = coin.SoGroup()
        vobj.addDisplayMode(default, "Default")

    def getDisplayModes(self, obj):
        "Return a list of display modes."
        modes = ["Default"]
        return modes

    def getDefaultDisplayMode(self):
        return "Default"

    def setDisplayMode(self, mode):
        return mode


class DeformationProxy(BaseProxy):
    pass


class DeformationViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationDeformation.svg"


class ElasticityProxy(BaseProxy):
    pass


class ElasticityViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationElasticity.svg"


class ElectricforceProxy(BaseProxy):
    pass


class ElectricforceViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationElectricforce.svg"


class ElectrostaticProxy(BaseProxy):
    pass


class ElectrostaticViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationElectrostatic.svg"


class FlowProxy(BaseProxy):
    pass


class FlowViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationFlow.svg"


class FluxProxy(BaseProxy):
    pass


class FluxViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationFlux.svg"


class HeatProxy(BaseProxy):
    pass


class HeatViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationHeat.svg"


class MagnetodynamicProxy(BaseProxy):
    pass


class MagnetodynamicViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationMagnetodynamic.svg"


class Magnetodynamic2DProxy(BaseProxy):
    pass


class Magnetodynamic2DViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationMagnetodynamic2D.svg"


class StaticCurrentProxy(BaseProxy):
    pass


class StaticCurrentViewProxy(BaseViewProxy):

    def getIcon(self):
        return ":/icons/FEM_EquationStaticCurrent.svg"


##  @}
