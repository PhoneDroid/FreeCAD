# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: WandererFan <wandererfan@gmail.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export
from TechDraw.Drawview import DrawView


@export(
    Include="Mod/TechDraw/App/DrawViewAnnotation.h",
    Namespace="TechDraw",
    FatherInclude="Mod/TechDraw/App/DrawViewPy.h",
)
class DrawViewAnnotation(DrawView):
    """
    Feature for creating and manipulating Technical Drawing Annotation Views

    License: LGPL-2.1-or-later
    """
