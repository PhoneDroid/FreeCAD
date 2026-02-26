# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileCopyrightText: 2019 Zheng Lei<realthunder.dev@gmail.com>
# SPDX-FileCopyrightText: 2020 Eliud Cabrera Castillo <e.cabrera-castillo@tum.de>
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
"""Provides the base viewprovider code for the Link objects."""
## @package view_draftlink
# \ingroup draftviewproviders
# \brief Provides the base viewprovider code for the Link objects.

## \addtogroup draftviewproviders
# @{
from draftviewproviders.view_base import ViewProviderDraft


class ViewProviderDraftLink(ViewProviderDraft):
    """A view provider for link type object."""

    def __init__(self, vobj):
        super(ViewProviderDraftLink, self).__init__(vobj)

    def getIcon(self):
        tp = self.Object.Proxy.Type
        if tp == "Array":
            if self.Object.ArrayType == "ortho":
                return ":/icons/Draft_LinkArray.svg"
            elif self.Object.ArrayType == "polar":
                return ":/icons/Draft_PolarLinkArray.svg"
            elif self.Object.ArrayType == "circular":
                return ":/icons/Draft_CircularLinkArray.svg"
        elif tp == "PathArray":
            return ":/icons/Draft_PathLinkArray.svg"
        elif tp == "PathTwistedArray":
            return ":/icons/Draft_PathTwistedLinkArray.svg"
        elif tp == "PointArray":
            return ":/icons/Draft_PointLinkArray.svg"

    def claimChildren(self):
        obj = self.Object
        if hasattr(obj, "ExpandArray"):
            expand = obj.ExpandArray
        else:
            expand = obj.ShowElement
        if not expand:
            return super(ViewProviderDraftLink, self).claimChildren()
        else:
            return obj.ElementList


# Alias for compatibility with old versions of v0.19
_ViewProviderDraftLink = ViewProviderDraftLink

## @}
