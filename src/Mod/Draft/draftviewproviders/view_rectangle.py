# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileCopyrightText: 2020 FreeCAD Developers
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
"""Provides the viewprovider code for the Rectangle object."""
## @package view_rectangle
# \ingroup draftviewproviders
# \brief Provides the viewprovider code for the Rectangle object.

## \addtogroup draftviewproviders
# @{
from PySide.QtCore import QT_TRANSLATE_NOOP

from draftviewproviders.view_base import ViewProviderDraft


class ViewProviderRectangle(ViewProviderDraft):

    def __init__(self, vobj):
        super(ViewProviderRectangle, self).__init__(vobj)

        _tip = QT_TRANSLATE_NOOP(
            "App::Property", "Defines a texture image (overrides hatch patterns)"
        )
        vobj.addProperty("App::PropertyFile", "TextureImage", "Draft", _tip, locked=True)


# Alias for compatibility with v0.18 and earlier
_ViewProviderRectangle = ViewProviderRectangle

## @}
