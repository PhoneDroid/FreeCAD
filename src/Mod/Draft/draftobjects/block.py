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
"""Provides the object code for the Block object."""
## @package block
# \ingroup draftobjects
# \brief Provides the object code for the Block object.

## \addtogroup draftobjects
# @{
from PySide.QtCore import QT_TRANSLATE_NOOP

from draftobjects.base import DraftObject
from draftutils import gui_utils


class Block(DraftObject):
    """The Block object"""

    def __init__(self, obj):
        super().__init__(obj, "Block")

        _tip = QT_TRANSLATE_NOOP("App::Property", "The components of this block")
        obj.addProperty("App::PropertyLinkList", "Components", "Draft", _tip, locked=True)

    def onDocumentRestored(self, obj):
        super().onDocumentRestored(obj)
        gui_utils.restore_view_object(
            obj, vp_module="view_base", vp_class="ViewProviderDraftPart", format=False
        )

    def execute(self, obj):
        if self.props_changed_placement_only(obj):
            obj.positionBySupport()
            self.props_changed_clear()
            return

        import Part

        plm = obj.Placement
        shps = []
        for c in obj.Components:
            shps.append(c.Shape)
        if shps:
            shape = Part.makeCompound(shps)
            obj.Shape = shape
        obj.Placement = plm
        obj.positionBySupport()
        self.props_changed_clear()

    def onChanged(self, obj, prop):
        self.props_changed_store(prop)


# Alias for compatibility with v0.18 and earlier
_Block = Block

## @}
