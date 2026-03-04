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

from Metadata import export, forward_declarations, constmethod
from PyObjectBase import PyObjectBase
from typing import List, Final

@export(
    Twin="BaseType",
    TwinPointer="BaseType",
    Delete=True,
)
@forward_declarations(
    """
namespace Base {
    using BaseType = Type;
}"""
)
class Type(PyObjectBase):
    """
    BaseTypePy class.

    This class provides functionality related to type management in the Base module. It's not intended for direct instantiation but for accessing type information and creating instances of various types. Instantiation is possible for classes that inherit from the Base::BaseClass class and are not abstract.

    Licence: LGPL
    """

    Name: Final[str] = ""
    """The name of the type id."""

    Key: Final[int] = 0
    """The key of the type id."""

    Module: Final[str] = ""
    """Module in which this class is defined."""

    @staticmethod
    def fromName(name: str, /) -> "Type":
        """
        Returns a type object by name.

        name : str
        """
        ...

    @staticmethod
    def fromKey(key: int, /) -> "Type":
        """
        Returns a type id object by key.

        key : int
        """
        ...

    @staticmethod
    def getNumTypes() -> int:
        """
        Returns the number of type ids created so far.
        """
        ...

    @staticmethod
    def getBadType() -> "Type":
        """
        Returns an invalid type id.
        """
        ...

    @staticmethod
    def getAllDerivedFrom(type: str, /) -> List[str]:
        """
        Returns all descendants from the given type id.

        type : str, Base.BaseType
        """
        ...

    @constmethod
    def getParent(self) -> "Type":
        """
        Returns the parent type id.
        """
        ...

    @constmethod
    def isBad(self) -> bool:
        """
        Checks if the type id is invalid.
        """
        ...

    @constmethod
    def isDerivedFrom(self, type: str, /) -> bool:
        """
        Returns true if given type id is a father of this type id.

        type : str, Base.BaseType
        """
        ...

    @constmethod
    def getAllDerived(self) -> List[object]:
        """
        Returns all descendants from this type id.
        """
        ...

    def createInstance(self) -> object:
        """
        Creates an instance of this type id.
        """
        ...

    @staticmethod
    def createInstanceByName(name: str, load: bool = False, /) -> object:
        """
        Creates an instance of the named type id.

        name : str
        load : bool
            Load named type id module.
        """
        ...
