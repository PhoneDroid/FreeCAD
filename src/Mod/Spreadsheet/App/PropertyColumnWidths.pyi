# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Eivind Kvedalen <eivind@kvedalen.name>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export
from Base.Persistence import Persistence

@export(
    Include="Mod/Spreadsheet/App/PropertyColumnWidths.h",
    Namespace="Spreadsheet",
    Constructor=True,
)
class PropertyColumnWidths(Persistence):
    """
    Internal spreadsheet object

    License: LGPL-2.1-or-later
    """
