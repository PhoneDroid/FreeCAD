# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Abdullah Tahiri <abdullah.tahiri.yo@gmail.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export
from GeometryExtension import GeometryExtension

@export(
    PythonName="Part.GeometryStringExtension",
    Include="Mod/Part/App/GeometryDefaultExtension.h",
    FatherInclude="Mod/Part/App/GeometryExtensionPy.h",
    Constructor=True,
)
class GeometryStringExtension(GeometryExtension):
    """
    A GeometryExtension extending geometry objects with a string.

    Licence: LGPL
    """

    Value: str = ...
    """returns the value of the GeometryStringExtension."""
