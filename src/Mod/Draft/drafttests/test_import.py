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

"""Unit tests for the Draft Workbench, import tests."""

## @package test_import
# \ingroup drafttests
# \brief Unit tests for the Draft Workbench, import tests.

## \addtogroup drafttests
# @{

from drafttests import auxiliary as aux
from drafttests import test_base


class DraftImport(test_base.DraftTestCaseNoDoc):
    """Import the Draft modules."""

    def test_import_draft(self):
        """Import the Draft module."""
        module = "Draft"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))

    def test_import_draft_geomutils(self):
        """Import Draft geometrical utilities."""
        module = "DraftGeomUtils"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))

    def test_import_draft_vecutils(self):
        """Import Draft vector utilities."""
        module = "DraftVecUtils"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))

    def test_import_draft_svg(self):
        """Import Draft SVG utilities."""
        module = "draftfunctions.svg"
        imported = aux.import_test(module)
        self.assertTrue(imported, "Problem importing '{}'".format(module))


## @}
