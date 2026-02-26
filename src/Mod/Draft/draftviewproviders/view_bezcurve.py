# SPDX-License-Identifier: LGPL-2.1-or-later
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
"""Provides the viewprovider code for the BezCurve object.

At the moment this view provider subclasses the Wire view provider,
and behaves the same as it. In the future this could change
if another behavior is desired.
"""
## @package view_bezcurve
# \ingroup draftviewproviders
# \brief Provides the viewprovider code for the BezCurve object.

## \addtogroup draftviewproviders
# @{
from draftviewproviders.view_wire import ViewProviderWire


class ViewProviderBezCurve(ViewProviderWire):
    """The view provider for the Bezier curve object."""

    def __init__(self, vobj):
        super(ViewProviderBezCurve, self).__init__(vobj)


# Alias for compatibility with v0.18 and earlier
_ViewProviderBezCurve = ViewProviderBezCurve

## @}
