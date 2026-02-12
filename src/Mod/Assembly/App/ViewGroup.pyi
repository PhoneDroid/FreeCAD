# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Ondsel <development@ondsel.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export

from App.DocumentObjectGroup import DocumentObjectGroup

@export(Include="Mod/Assembly/App/ViewGroup.h", Namespace="Assembly")
class ViewGroup(DocumentObjectGroup):
    """
    This class is a group subclass for joints.

    License: LGPL-2.1-or-later
    """
