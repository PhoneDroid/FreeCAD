# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Stefan Troeger <stefantroeger@gmx.net>
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

from Base.Metadata import export, constmethod
from PropertyContainer import PropertyContainer


@export(
    Initialization=True,
    Constructor=True,
)
class ExtensionContainer(PropertyContainer):
    """
    Base class for all objects which can be extended
    Licence: LGPL
    """

    def addExtension(self, identifier: str, /) -> None:
        """
        Adds an extension to the object. Requires the string identifier for the python extension as argument
        """
        ...

    @constmethod
    def hasExtension(self, identifier: str, /) -> bool:
        """
        Returns if this object has the specified extension
        """
        ...
