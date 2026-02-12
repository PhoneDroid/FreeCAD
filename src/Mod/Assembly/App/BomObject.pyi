# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Ondsel <development@ondsel.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export
from Spreadsheet.Sheet import Sheet

@export(
    Include="Mod/Assembly/App/BomObject.h",
    FatherInclude="Mod/Spreadsheet/App/SheetPy.h",
    Namespace="Assembly",
)
class BomObject(Sheet):
    """
    This class is the BOM object of assemblies, it derives from Spreadsheet::Sheet.

    License: LGPL-2.1-or-later
    """
