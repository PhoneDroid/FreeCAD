# SPDX-FileCopyrightText: 2020 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "FreeCAD FEM constraint tie document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package constraint_tie
#  \ingroup FEM
#  \brief constraint tie object

from . import base_fempythonobject

import FreeCAD

_PropHelper = base_fempythonobject._PropHelper


class ConstraintTie(base_fempythonobject.BaseFemPythonObject):
    """
    The ConstraintTie object
    """

    Type = "Fem::ConstraintTie"

    def __init__(self, obj):
        super().__init__(obj)

        for prop in self._get_properties():
            prop.add_to_object(obj)

    def _get_properties(self):
        prop = []

        prop.append(
            _PropHelper(
                type="App::PropertyLength",
                name="Tolerance",
                group="Geometry",
                doc="Set max gap between tied faces",
                value="0.0 mm",
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyBool",
                name="Adjust",
                group="Geometry",
                doc="Adjust connected nodes",
                value=False,
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyBool",
                name="CyclicSymmetry",
                group="Geometry",
                doc="Define cyclic symmetry model",
                value=False,
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyPlacement",
                name="SymmetryAxis",
                group="Geometry",
                doc="Placement of axis of symmetry",
                value=FreeCAD.Placement(),
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyInteger",
                name="Sectors",
                group="Geometry",
                doc="Number of sectors",
                value=0,
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyInteger",
                name="ConnectedSectors",
                group="Geometry",
                doc="Number of connected sectors used for results display",
                value=1,
            )
        )

        return prop

    def onDocumentRestored(self, obj):
        # update old project with new properties
        for prop in self._get_properties():
            try:
                obj.getPropertyByName(prop.name)
            except FreeCAD.Base.PropertyError:
                prop.add_to_object(obj)
