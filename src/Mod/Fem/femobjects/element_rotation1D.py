# SPDX-FileCopyrightText: 2017 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "FreeCAD FEM element rotation 1D document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package element_rotation1D
#  \ingroup FEM
#  \brief element rotation 1D object

from . import base_femelement


class ElementRotation1D(base_femelement.BaseFemElement):
    """
    The ElementRotation1D object
    """

    Type = "Fem::ElementRotation1D"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyAngle", "Rotation", "BeamRotation", "Set the rotation of beam elements"
        )
        obj.setPropertyStatus("Rotation", "LockDynamic")
