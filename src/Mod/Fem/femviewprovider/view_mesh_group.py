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

__title__ = "FreeCAD FEM mesh group ViewProvider for the document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package view_mesh_group
#  \ingroup FEM
#  \brief view provider for mesh group object

from femtaskpanels import task_mesh_group
from . import view_base_femmeshelement


class VPMeshGroup(view_base_femmeshelement.VPBaseFemMeshElement):
    """
    A View Provider for the MeshGroup object
    """

    def setEdit(self, vobj, mode=0):
        return super().setEdit(vobj, mode, task_mesh_group._TaskPanel)
