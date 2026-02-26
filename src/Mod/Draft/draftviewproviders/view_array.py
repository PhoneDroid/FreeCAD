# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

# ***************************************************************************
# *   (c) 2019 Eliud Cabrera Castillo <e.cabrera-castillo@tum.de>           *
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
"""Provides the viewprovider code for the Array object."""
## @package view_array
# \ingroup draftviewproviders
# \brief Provides the viewprovider code for the Array object.

## \addtogroup draftviewproviders
# @{
from draftviewproviders.view_base import ViewProviderDraft
from draftutils import gui_utils


class ViewProviderDraftArray(ViewProviderDraft):
    """a view provider that displays a Array icon instead of a Draft icon"""

    def __init__(self, vobj):
        super(ViewProviderDraftArray, self).__init__(vobj)

    def getIcon(self):
        if hasattr(self.Object, "ArrayType"):
            if self.Object.ArrayType == "ortho":
                return ":/icons/Draft_Array.svg"
            elif self.Object.ArrayType == "polar":
                return ":/icons/Draft_PolarArray.svg"
            elif self.Object.ArrayType == "circular":
                return ":/icons/Draft_CircularArray.svg"
        elif hasattr(self.Object, "PointObject"):
            return ":/icons/Draft_PointArray.svg"
        elif hasattr(self.Object, "RotationFactor"):
            return ":/icons/Draft_PathTwistedArray.svg"
        else:
            return ":/icons/Draft_PathArray.svg"

    def resetColors(self, vobj):
        obj = vobj.Object
        if obj.Base is not None:
            colors = gui_utils.get_diffuse_color(obj.Base)
            if not colors:
                return
            if len(colors) > 1:
                n = 1
                if hasattr(obj, "ArrayType"):
                    if obj.ArrayType == "ortho":
                        n = obj.NumberX * obj.NumberY * obj.NumberZ
                    elif obj.ArrayType == "polar":
                        n = obj.NumberPolar
                    else:  # "circular"
                        n = obj.Count
                elif hasattr(obj, "Count"):
                    n = obj.Count
                colors = colors * n
            vobj.DiffuseColor = colors


# Alias for compatibility with v0.18 and earlier
_ViewProviderDraftArray = ViewProviderDraftArray

## @}
