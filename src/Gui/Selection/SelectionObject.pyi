# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

from Base.Metadata import export
from Base.BaseClass import BaseClass
from typing import Any, Final, Tuple

@export(
    Include="Gui/Selection/SelectionObject.h",
    Delete=True,
)
class SelectionObject(BaseClass):
    """
    This class represents selections made by the user. It holds information about the object, document and sub-element of the selection.

    Licence: LGPL
    """

    def remove(self) -> None:
        """
        Remove this selection item from the selection.

        --
        This object becomes invalid.
        """
        ...

    def isObjectTypeOf(self, type: Any, /) -> bool:
        """
        Test for a certain father class.
        """
        ...
    ObjectName: Final[str] = ""
    """Name of the selected object"""

    SubElementNames: Final[Tuple[str, ...]] = ()
    """Name of the selected sub-element if any"""

    FullName: Final[str] = ""
    """Name of the selected object"""

    TypeName: Final[str] = ""
    """Type name of the selected object"""

    DocumentName: Final[str] = ""
    """Name of the document of the selected object"""

    Document: Final[Any] = ...
    """Document of the selected object"""

    Object: Final[Any] = ...
    """Selected object"""

    SubObjects: Final[Tuple[Any, ...]] = ()
    """Selected sub-element, if any"""

    PickedPoints: Final[Tuple[Any, ...]] = ()
    """Picked points for selection"""

    HasSubObjects: Final[bool] = False
    """Selected sub-element, if any"""
