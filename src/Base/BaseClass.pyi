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

from __future__ import annotations

from Metadata import constmethod
from PyObjectBase import PyObjectBase
from typing import List, Final

class BaseClass(PyObjectBase):
    """
    This is the base class

    Licence: LGPL
    """

    TypeId: Final[str] = ""
    """Is the type of the FreeCAD object with module domain"""

    Module: Final[str] = ""
    """Module in which this class is defined"""

    @constmethod
    def isDerivedFrom(self, typeName: str, /) -> bool:
        """
        Returns true if given type is a father
        """
        ...

    @constmethod
    def getAllDerivedFrom(self) -> List[object]:
        """
        Returns all descendants
        """
        ...
