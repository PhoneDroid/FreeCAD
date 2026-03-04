# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: David Friedli <david@friedli-be.ch>
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

from __future__ import annotations

from Base.Metadata import export, no_args
from Base.PyObjectBase import PyObjectBase
from typing import List, Tuple, TypeAlias

MeasureType: TypeAlias = object


@export(
    Constructor=False,
    Delete=True,
)
class MeasureManager(PyObjectBase):
    """
    MeasureManager class.

    The MeasureManager handles measure types and geometry handler across FreeCAD.

    Licence: LGPL
    DeveloperDocu: MeasureManager
    """

    @staticmethod
    def addMeasureType(id: str, label: str, measureType: MeasureType, /) -> None:
        """
        Add a new measure type.

        id : str
            Unique identifier of the measure type.
        label : str
            Name of the module.
        measureType : Measure.MeasureBasePython
            The actual measure type.
        """
        ...

    @staticmethod
    @no_args
    def getMeasureTypes() -> List[Tuple[str, str, MeasureType]]:
        """
        Returns a list of all registered measure types.
        """
        ...
