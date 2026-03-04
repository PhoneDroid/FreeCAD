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
from BaseClass import BaseClass
from typing import Final

class Persistence(BaseClass):
    """
    Base.Persistence class.

    Class to dump and restore the content of an object.

    Licence: LGPL
    """

    Content: Final[str] = ""
    """Content of the object in XML representation."""

    MemSize: Final[int] = 0
    """Memory size of the object in bytes."""

    @constmethod
    def dumpContent(self, Compression: int = 3) -> bytearray:
        """
        Dumps the content of the object, both the XML representation and the additional
        data files required, into a byte representation.

        Compression : int
            Set the data compression level in the range [0,9]. Set to 0 for no compression.
        """
        ...

    def restoreContent(self, obj: object, /) -> None:
        # TODO: Starting with Python 3.12, collections.abc.Buffer can be used for type hinting
        """
        Restore the content of the object from a byte representation as stored by `dumpContent`.
        It could be restored from any Python object implementing the buffer protocol.

        obj : buffer
            Object with buffer protocol support.
        """
        ...
