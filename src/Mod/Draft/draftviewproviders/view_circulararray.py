# SPDX-License-Identifier: LGPL-2.1-or-later
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

"""Provides the viewprovider code for the circular Array object.

Currently unused.
"""
## @package view_circulararray
# \ingroup draftviewproviders
# \brief Provides the viewprovider code for the circular Array object.

## \addtogroup draftviewproviders
# @{
import Draft_rc

from draftviewproviders.view_array import ViewProviderDraftArray

# The module is used to prevent complaints from code checkers (flake8)
True if Draft_rc.__name__ else False


class ViewProviderCircularArray(ViewProviderDraftArray):
    """View provider for the circular array object, currently unused."""

    def __init__(self, vobj):
        super().__init__(vobj)

    def getIcon(self):
        """Set the icon in the tree view."""
        return ":/icons/Draft_CircularArray"


## @}
