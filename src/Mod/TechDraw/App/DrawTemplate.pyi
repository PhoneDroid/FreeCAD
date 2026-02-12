# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Luke Parry <l.parry@warwick.ac.uk>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export

from App.DocumentObject import DocumentObject


@export(
    Include="Mod/TechDraw/App/DrawTemplate.h",
    Namespace="TechDraw",
)
class DrawTemplate(DocumentObject):
    """
    Feature for creating and manipulating Technical Drawing Templates

    License: LGPL-2.1-or-later
    """
