# SPDX-FileCopyrightText: 2015 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "FreeCAD FEM element geometry 2D document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package element_geometry2D
#  \ingroup FEM
#  \brief element geometry 2D object

from . import base_femelement
from .base_fempythonobject import _PropHelper


class ElementGeometry2D(base_femelement.BaseFemElement):
    """
    The ElementGeometry2D object
    """

    Type = "Fem::ElementGeometry2D"

    def __init__(self, obj):
        super().__init__(obj)

    def _get_properties(self):
        prop = super()._get_properties()

        prop.append(
            _PropHelper(
                type="App::PropertyLength",
                name="Thickness",
                group="ShellThickness",
                doc="Set thickness of the shell elements",
                value="0 mm",
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyFloat",
                name="Offset",
                group="ShellThickness",
                doc="Set thickness offset of the shell elements",
                value=0.0,
            )
        )

        return prop

    def onDocumentRestored(self, obj):
        # update old project with new properties
        super().onDocumentRestored(obj)
