# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Jürgen Riegel <juergen.riegel@web.de>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from typing import Any

from Base.Metadata import export
from Base.PyObjectBase import PyObjectBase

@export(
    Include="Mod/Import/App/StepShape.h",
    Namespace="Import",
    Constructor=True,
    Delete=True,
)
class StepShape(PyObjectBase):
    """
    StepShape in Import
    This class gives a interface to retrieve TopoShapes out of an loaded STEP file of any kind.

    License: LGPL-2.1-or-later
    """

    def read(self) -> Any:
        """
        Read a STEP file into memory and make it accessible
        """
        ...
