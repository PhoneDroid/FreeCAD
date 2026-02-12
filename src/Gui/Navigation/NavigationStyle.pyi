# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Werner Mayer <wmayer@users.sourceforge.net>
# SPDX-FileNotice: Part of the FreeCAD project.

from Base.Metadata import export
from Base.BaseClass import BaseClass

@export(
    Include="Gui/Navigation/NavigationStyle.h",
)
class NavigationStyle(BaseClass):
    """
    This is the base class for navigation styles

    Licence: LGPL
    """

    ...
