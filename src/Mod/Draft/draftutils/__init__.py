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
"""Utility modules that are used throughout the workbench.

These modules include functions intended to be quite general,
so they should be useful in all other modules in the workbench
and even other workbenches.
Since they are not meant to be very complex, they shouldn't require
a lot of prerequisites, and shouldn't cause problems of circular imports.

They include modules that don't require the graphical interface (GUI),
as well as functions that do require it because they interact
with the view providers or with the 3D view.

Non GUI modules
---------------
- `utils`, generic functions
- `messages`, shorthands to print to the console
- `translate`, translate text using QtCore

GUI modules
-----------
- `gui_utils`, generic functions that deal with the graphical interface
- `todo`, delay execution of Python code through Qt

Initialization modules for the GUI
----------------------------------
- `init_tools`, initialize toolbars and menus of the workbench
- `init_draft_statusbar`, initialize the status bar of the workbench
"""
## \defgroup draftutils draftutils
# \ingroup DRAFT
# \brief Utility modules that are used throughout the workbench.
