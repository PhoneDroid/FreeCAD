# SPDX-FileCopyrightText: 2016 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "FreeCAD FEM material mechanical nonlinear ViewProvider for the document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package view_material_mechanicalnonlinear
#  \ingroup FEM
#  \brief view provider for material mechanical nonlinear object

from . import view_base_femmaterial


class VPMaterialMechanicalNonlinear(view_base_femmaterial.VPBaseFemMaterial):
    """
    A View Provider for the MaterialMechanicalNonlinear object
    """

    pass
