# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Werner Mayer <wmayer@users.sourceforge.net>
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

from ViewProvider import ViewProvider
from typing import Any, Final

class ViewProviderDocumentObject(ViewProvider):
    """
    This is the ViewProvider base class

    Licence: LGPL
    """

    def update(self) -> None:
        """
        Update the view representation of the object
        """
        ...
    Object: Any = ...
    """Set/Get the associated data object"""

    ForceUpdate: bool = False
    """Reference count to force update visual"""

    Document: Final[Any] = ...
    """Return the document the view provider is part of"""
