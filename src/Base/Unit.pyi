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

from Metadata import export
from PyObjectBase import PyObjectBase
from Quantity import Quantity
from typing import Final, Tuple, overload

@export(
    NumberProtocol=True,
    RichCompare=True,
    Constructor=True,
    Delete=True,
)
class Unit(PyObjectBase):
    """
    Unit
    defines a unit type, calculate and compare.

    The following constructors are supported:
    Unit()                        -- empty constructor
    Unit(i1,i2,i3,i4,i5,i6,i7,i8) -- unit signature
    Unit(Quantity)                -- copy unit from Quantity
    Unit(Unit)                    -- copy constructor
    Unit(string)                  -- parse the string for units

    Licence: LGPL
    """

    @overload
    def __init__(self) -> None: ...
    @overload
    def __init__(
        self,
        i1: float,
        i2: float,
        i3: float,
        i4: float,
        i5: float,
        i6: float,
        i7: float,
        i8: float,
    ) -> None: ...
    @overload
    def __init__(self, quantity: Quantity) -> None: ...
    @overload
    def __init__(self, unit: Unit) -> None: ...
    @overload
    def __init__(self, string: str) -> None: ...

    Type: Final[str] = ...
    """holds the unit type as a string, e.g. 'Area'."""

    Signature: Final[Tuple] = ...
    """Returns the signature."""
