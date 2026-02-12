# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Abdullah Tahiri <abdullah.tahiri.yo@gmail.com>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import export
from ArcOfConic import ArcOfConic
from typing import Final

@export(
    Father="ArcOfConicPy",
    Name="ArcOfParabolaPy",
    PythonName="Part.ArcOfParabola",
    Twin="GeomArcOfParabola",
    TwinPointer="GeomArcOfParabola",
    Include="Mod/Part/App/Geometry.h",
    Namespace="Part",
    FatherInclude="Mod/Part/App/ArcOfConicPy.h",
    FatherNamespace="Part",
    Constructor=True,
)
class ArcOfParabola(ArcOfConic):
    """
    Describes a portion of a parabola

    Licence: LGPL
    """

    Focal: float = ...
    """The focal length of the parabola."""

    Parabola: Final[object] = ...
    """The internal parabola representation"""
