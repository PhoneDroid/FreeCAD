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

__title__ = "FreeCAD FEM mesh boundary layer document object"
__author__ = "Bernd Hahnebach, Qingfeng Xia"
__url__ = "https://www.freecad.org"

## @package mesh_boundarylayer
#  \ingroup FEM
#  \brief mesh boundary layer object

from . import base_femmeshelement


class MeshBoundaryLayer(base_femmeshelement.BaseFemMeshElement):
    """
    The MeshBoundaryLayer object
    """

    Type = "Fem::MeshBoundaryLayer"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyInteger",
            "NumberOfLayers",
            "MeshBoundaryLayerProperties",
            "set number of inflation layers for this boundary",
        )
        obj.setPropertyStatus("NumberOfLayers", "LockDynamic")
        obj.NumberOfLayers = 3

        obj.addProperty(
            "App::PropertyLength",
            "MinimumThickness",
            "MeshBoundaryLayerProperties",
            "set minimum thickness,usually the first inflation layer",
        )
        obj.setPropertyStatus("MinimumThickness", "LockDynamic")
        # default to zero, user must specify a proper value for this property

        obj.addProperty(
            "App::PropertyFloat",
            "GrowthRate",
            "MeshBoundaryLayerProperties",
            "set growth rate of inflation layers for smooth transition",
        )
        obj.setPropertyStatus("GrowthRate", "LockDynamic")
        obj.GrowthRate = 1.5
