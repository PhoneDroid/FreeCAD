# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileCopyrightText: 2019 Eliud Cabrera Castillo <e.cabrera-castillo@tum.de>
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
"""Provides the viewprovider code for the Point object."""
## @package view_point
# \ingroup draftviewproviders
# \brief Provides the viewprovider code for the Point object.

## \addtogroup draftviewproviders
# @{
from draftviewproviders.view_base import ViewProviderDraft


class ViewProviderPoint(ViewProviderDraft):
    """A viewprovider for the Draft Point object"""

    def __init__(self, obj):
        super(ViewProviderPoint, self).__init__(obj)

    def onChanged(self, vobj, prop):
        mode = 2
        vobj.setEditorMode("AngularDeflection", mode)
        vobj.setEditorMode("BoundingBox", mode)
        vobj.setEditorMode("Deviation", mode)
        vobj.setEditorMode("DisplayMode", mode)
        vobj.setEditorMode("DrawStyle", mode)
        vobj.setEditorMode("Lighting", mode)
        vobj.setEditorMode("LineColor", mode)
        vobj.setEditorMode("LineWidth", mode)
        vobj.setEditorMode("Pattern", mode)
        vobj.setEditorMode("PatternSize", mode)
        vobj.setEditorMode("ShapeAppearance", mode)
        vobj.setEditorMode("Transparency", mode)

    def getIcon(self):
        return ":/icons/Draft_Dot.svg"

    def doubleClicked(self, vobj):
        # See setEdit in ViewProviderDraft.
        import FreeCADGui as Gui

        Gui.runCommand("Std_TransformManip")
        return True


# Alias for compatibility with v0.18 and earlier
_ViewProviderPoint = ViewProviderPoint

## @}
