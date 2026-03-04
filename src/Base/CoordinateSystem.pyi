# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Jürgen Riegel <FreeCAD@juergen-riegel.net>
# SPDX-FileNotice: Part of the FreeCAD project.

################################################################################
#                                                                              #
#   FreeCAD is free software: you can redistribute it and/or modify            #
#   it under the terms of the GNU Lesser General Public License as             #
#   published by the Free Software Foundation, either version 2.1              #
#   of the License, or (at your option) any later version.                     #
#                                                                              #
#   FreeCAD is distributed in the hope that it will be useful,                 #
#   but WITHOUT ANY WARRANTY; without even the implied warranty                #
#   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                    #
#   See the GNU Lesser General Public License for more details.                #
#                                                                              #
#   You should have received a copy of the GNU Lesser General Public           #
#   License along with FreeCAD. If not, see https://www.gnu.org/licenses       #
#                                                                              #
################################################################################

from __future__ import annotations

from Metadata import export, constmethod
from PyObjectBase import PyObjectBase
from Axis import Axis as AxisPy
from Vector import Vector
from Placement import Placement
from Rotation import Rotation
from typing import Union

@export(
    Constructor=True,
    Delete=True,
)
class CoordinateSystem(PyObjectBase):
    """
    Base.CoordinateSystem class.

    An orthonormal right-handed coordinate system in 3D space.

    CoordinateSystem()
    Empty constructor.

    Licence: LGPL
    """

    Axis: AxisPy = None
    """Set or get axis."""

    XDirection: Vector = None
    """Set or get X-direction."""

    YDirection: Vector = None
    """Set or get Y-direction."""

    ZDirection: Vector = None
    """Set or get Z-direction."""

    Position: Vector = None
    """Set or get position."""

    def setAxes(self, axis: Union[AxisPy, Vector], xDir: Vector, /) -> None:
        """
        Set axis or Z-direction, and X-direction.
        The X-direction is determined from the orthonormal compononent of `xDir`
        with respect to `axis` direction.

        axis : Base.Axis, Base.Vector
        xDir : Base.Vector
        """
        ...

    @constmethod
    def displacement(self, coordSystem2: "CoordinateSystem", /) -> Placement:
        """
        Computes the placement from this to the passed coordinate system `coordSystem2`.

        coordSystem2 : Base.CoordinateSystem
        """
        ...

    def transformTo(self, vector: Vector, /) -> Vector:
        """
        Computes the coordinates of the point in coordinates of this coordinate system.

        vector : Base.Vector
        """
        ...

    def transform(self, trans: Union[Rotation, Placement], /) -> None:
        """
        Applies a transformation on this coordinate system.

        trans : Base.Rotation, Base.Placement
        """
        ...

    def setPlacement(self, placement: Placement, /) -> None:
        """
        Set placement to the coordinate system.

        placement : Base.Placement
        """
        ...
