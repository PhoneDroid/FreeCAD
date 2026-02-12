# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: WandererFan <wandererfan@gmail.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export
from TechDraw.DrawView import DrawView


@export(
    Include="Mod/TechDraw/App/DrawWeldSymbol.h",
    Namespace="TechDraw",
    FatherInclude="Mod/TechDraw/App/DrawViewPy.h",
)
class DrawWeldSymbol(DrawView):
    """
    Feature for adding welding tiles to leader lines

    License: LGPL-2.1-or-later
    """
