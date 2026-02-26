# SPDX-FileCopyrightText: 2019 Bernd Hahnebach <bernd@bimstatik.org>
# SPDX-FileCopyrightText: 2024 Mario Passaglia <mpassaglia@cbc.uba.ar>
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

__title__ = "FreeCAD FEM reinforced material"
__author__ = "Bernd Hahnebach, Mario Passaglia"
__url__ = "https://www.freecad.org"

## @package material_reinforced
#  \ingroup FEM
#  \brief reinforced object

from . import material_common
from .base_fempythonobject import _PropHelper


class MaterialReinforced(material_common.MaterialCommon):
    """
    The MaterialReinforced object
    """

    Type = "Fem::MaterialReinforced"

    def __init__(self, obj):
        super().__init__(obj)

        # overwrite Category enumeration
        obj.Category = ["Solid"]

    def _get_properties(self):
        prop = super()._get_properties()

        prop.append(
            _PropHelper(
                type="App::PropertyMap",
                name="Reinforcement",
                group="Composites",
                doc="Reinforcement material properties",
                value={},
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyString",
                name="ReinforcementUUID",
                group="Composites",
                doc="Reinforcement material UUID",
                hidden=True,
                value="",
            )
        )

        return prop

    def onDocumentRestored(self, obj):
        super().onDocumentRestored(obj)

        # try update Reinforcement UUID from Reinforcement
        if not obj.ReinforcementUUID:
            obj.ReinforcementUUID = self._get_material_uuid(obj.Reinforcement)
