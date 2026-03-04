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

from Base.Metadata import export
from Base.BaseClass import BaseClass
from typing import Any, List, Dict

@export(
    Include="Gui/Workbench.h",
)
class Workbench(BaseClass):
    """
    This is the base class for workbenches

    Licence: LGPL
    """

    def name(self) -> str:
        """
        Return the workbench name
        """
        ...

    def activate(self) -> None:
        """
        Activate this workbench
        """
        ...

    def listToolbars(self) -> List[Any]:
        """
        Show a list of all toolbars
        """
        ...

    def getToolbarItems(self) -> Dict[Any, Any]:
        """
        Show a dict of all toolbars and their commands
        """
        ...

    def listCommandbars(self) -> List[Any]:
        """
        Show a list of all command bars
        """
        ...

    def listMenus(self) -> List[Any]:
        """
        Show a list of all menus
        """
        ...

    @staticmethod
    def reloadActive() -> None:
        """
        Reload the active workbench after changing menus or toolbars
        """
        ...
