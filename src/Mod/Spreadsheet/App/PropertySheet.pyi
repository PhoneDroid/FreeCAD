# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Eivind Kvedalen <eivind@kvedalen.name>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export, sequence_protocol
from Base.Persistence import Persistence

@export(
    Include="Mod/Spreadsheet/App/PropertySheet.h",
    Namespace="Spreadsheet",
    Constructor=True,
)
@sequence_protocol(
    mp_subscript="true",
)
class PropertySheet(Persistence):
    """
    Internal spreadsheet object

    License: LGPL-2.1-or-later
    """
