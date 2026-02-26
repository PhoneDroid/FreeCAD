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

__title__ = "FreeCAD FEM mesh region document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package mesh_region
#  \ingroup FEM
#  \brief mesh region object

from . import base_femmeshelement


class MeshRegion(base_femmeshelement.BaseFemMeshElement):
    """
    The FemMeshRegion object
    """

    Type = "Fem::MeshRegion"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyLength",
            "CharacteristicLength",
            "MeshRegionProperties",
            "set characteristic length of FEM elements for this refinement",
        )
        obj.setPropertyStatus("CharacteristicLength", "LockDynamic")
