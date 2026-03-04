# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Werner Mayer <wmayer@users.sourceforge.net>
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

from Base.Metadata import export, class_declarations
from Base.PyObjectBase import PyObjectBase
from typing import Any, overload


@export(
    Constructor=True,
    Delete=True,
)
@class_declarations("""public:
    static Base::Color toColor(PyObject* value);
        """)
class Material(PyObjectBase):
    """
    App.Material class.

    Licence: LGPL
    UserDocu: This is the Material class
    """

    def set(self, string: str, /) -> None:
        """
        Set(string) -- Set the material.

        The material must be one of the following values:
        Brass, Bronze, Copper, Gold, Pewter, Plaster, Plastic, Silver, Steel, Stone, Shiny plastic,
        Satin, Metalized, Neon GNC, Chrome, Aluminium, Obsidian, Neon PHC, Jade, Ruby or Emerald.
        """
        ...

    AmbientColor: Any = ...
    """Ambient color"""

    DiffuseColor: Any = ...
    """Diffuse color"""

    EmissiveColor: Any = ...
    """Emissive color"""

    SpecularColor: Any = ...
    """Specular color"""

    Shininess: float = 0.0
    """Shininess"""

    Transparency: float = 0.0
    """Transparency"""
