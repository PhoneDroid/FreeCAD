# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: WandererFan <wandererfan@gmail.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export

from App.DocumentObjectExtension import DocumentObjectExtension


@export(
    Include="Mod/TechDraw/App/CosmeticExtension.h",
    Namespace="TechDraw",
)
class CosmeticExtension(DocumentObjectExtension):
    """
    This object represents cosmetic features for a DrawViewPart.

    License: LGPL-2.1-or-later
    """
