# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Zheng Lei <realthunder.dev@gmail.com>
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

from Base.Metadata import export, constmethod, class_declarations
from Base.BaseClass import BaseClass
from typing import Any, Final, List


@export(
    Include="App/StringHasher.h",
    Reference=True,
)
@class_declarations("""private:
    friend class StringID;
    int _index = 0;
        """)
class StringID(BaseClass):
    """
    This is the StringID class

    Licence: LGPL
    """

    @constmethod
    def isSame(self, other: "StringID", /) -> bool:
        """
        Check if two StringIDs are the same
        """
        ...

    Value: Final[int] = 0
    """Return the integer value of this ID"""

    Related: Final[List[Any]] = []
    """Return the related string IDs"""

    Data: Final[str] = ""
    """Return the data associated with this ID"""

    IsBinary: Final[bool] = False
    """Check if the data is binary,"""

    IsHashed: Final[bool] = False
    """Check if the data is hash, if so 'Data' returns a base64 encoded string of the raw hash"""

    Index: int = 0
    """Geometry index. Only meaningful for geometry element name"""
