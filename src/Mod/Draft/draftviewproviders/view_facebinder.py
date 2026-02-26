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
"""Provides the viewprovider code for the Facebinder object."""
## @package view_facebinder
# \ingroup draftviewproviders
# \brief Provides the viewprovider code for the Facebinder object.

## \addtogroup draftviewproviders
# @{
import FreeCADGui as Gui

from draftviewproviders.view_base import ViewProviderDraft


class ViewProviderFacebinder(ViewProviderDraft):

    def __init__(self, vobj):
        super(ViewProviderFacebinder, self).__init__(vobj)

    def getIcon(self):
        return ":/icons/Draft_Facebinder_Provider.svg"

    def setEdit(self, vobj, mode):
        if mode != 0:
            return None

        import DraftGui  # Moving this to the top of the file results in a circular import.

        taskd = DraftGui.FacebinderTaskPanel()
        taskd.obj = vobj.Object
        taskd.update()
        Gui.Control.showDialog(taskd)
        return True

    def unsetEdit(self, vobj, mode):
        if mode != 0:
            return None

        return True


# Alias for compatibility with v0.18 and earlier
_ViewProviderFacebinder = ViewProviderFacebinder

## @}
