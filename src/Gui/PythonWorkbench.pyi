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
from Workbench import Workbench
from warnings import deprecated

@export(
    Twin="PythonBaseWorkbench",
    TwinPointer="PythonBaseWorkbench",
    Include="Gui/Workbench.h",
)
class PythonWorkbench(Workbench):
    """
    This is the class for Python workbenches

    Licence: LGPL
    """

    def appendMenu(self) -> None:
        """
        Append a new menu
        """
        ...

    def removeMenu(self) -> None:
        """
        Remove a menu
        """
        ...

    def appendContextMenu(self) -> None:
        """
        Append a new context menu item
        """
        ...

    def removeContextMenu(self) -> None:
        """
        Remove a context menu item
        """
        ...

    def appendToolbar(self) -> None:
        """
        Append a new toolbar
        """
        ...

    def removeToolbar(self) -> None:
        """
        Remove a toolbar
        """
        ...

    def appendCommandbar(self) -> None:
        """
        Append a new command bar
        """
        ...

    def removeCommandbar(self) -> None:
        """
        Remove a command bar
        """
        ...

    @deprecated
    def AppendMenu(self) -> None:
        """
        deprecated -- use appendMenu
        """
        ...

    @deprecated
    def RemoveMenu(self) -> None:
        """
        deprecated -- use removeMenu
        """
        ...

    @deprecated
    def ListMenus(self) -> None:
        """
        deprecated -- use listMenus
        """
        ...

    @deprecated
    def AppendContextMenu(self) -> None:
        """
        deprecated -- use appendContextMenu
        """
        ...

    @deprecated
    def RemoveContextMenu(self) -> None:
        """
        deprecated -- use removeContextMenu
        """
        ...

    @deprecated
    def AppendToolbar(self) -> None:
        """
        deprecated -- use appendToolbar
        """
        ...

    @deprecated
    def RemoveToolbar(self) -> None:
        """
        deprecated -- use removeToolbar
        """
        ...

    @deprecated
    def ListToolbars(self) -> None:
        """
        deprecated -- use listToolbars
        """
        ...

    @deprecated
    def AppendCommandbar(self) -> None:
        """
        deprecated -- use appendCommandBar
        """
        ...

    @deprecated
    def RemoveCommandbar(self) -> None:
        """
        deprecated -- use removeCommandBar
        """
        ...

    @deprecated
    def ListCommandbars(self) -> None:
        """
        deprecated -- use listCommandBars
        """
        ...
