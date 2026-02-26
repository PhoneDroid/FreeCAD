# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2013 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2019 Eliud Cabrera Castillo <e.cabrera-castillo@tum.de>
# SPDX-FileCopyrightText: 2025 FreeCAD Project Association
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

"""Unit tests for the Draft Workbench, GUI import tests."""

## @package test_import_gui
# \ingroup drafttests
# \brief Unit tests for the Draft Workbench, GUI import tests.

## \addtogroup drafttests
# @{

from drafttests import auxiliary as aux
from drafttests import test_base


class DraftGuiImport(test_base.DraftTestCaseNoDoc):
    """Import the Draft graphical modules."""

    def test_import_gui_draftgui(self):
        """Import Draft TaskView GUI tools."""
        module = "DraftGui"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))

    def test_import_gui_draft_snap(self):
        """Import Draft snapping."""
        module = "draftguitools.gui_snapper"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))

    def test_import_gui_draft_tools(self):
        """Import Draft graphical commands."""
        module = "DraftTools"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))

    def test_import_gui_draft_trackers(self):
        """Import Draft tracker utilities."""
        module = "draftguitools.gui_trackers"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))


## @}
