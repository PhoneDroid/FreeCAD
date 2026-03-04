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

"""Modules that define the workbench GuiCommands to perform graphical actions.

These GUI Commands or tools are called by buttons, menus, contextual menus,
toolbars, and other graphical widgets.
They are normally loaded by the workbench's `InitGui` module.
In this workbench these GUI tools are loaded by the `DraftTools`
module, which itself is loaded by `InitGui.DraftWorkbench.Initialize`.

This means that any script or workbench that wishes to use
this workbench's tools can import the individual modules,
or just `DraftTools`, to have access to them.

::

    import draftguitools.gui_rectangles
    import draftguitools.gui_circles
    import draftguitools.gui_arcs
    import DraftTools

These modules should not be imported in a console-only session,
as they are not intended to be used without the graphical interface (GUI).
They are also not generally suitable for scripting
as they normally require graphical input in the task panel or a selection
in the 3D view (`Gui.Selection`).

Most of these GUI tools require certain components of Draft to exist
like the `gui_snapper.Snapper`and the `DraftGui.DraftToolBar` classes.
These classes are normally installed in the global `Gui` namespace,
so they are accessible at all times.

::

    import DraftGui
    import draftguitools.gui_snapper
    Gui.draftToolBar = DraftGui.DraftToolBar()
    Gui.Snapper = draftguitools.gui_snapper.Snapper()

These classes can be imported and initialized individually
but it is easier to set them up just by importing `DraftTools`.
"""
## \defgroup draftguitools draftguitools
# \ingroup DRAFT
# \brief Modules that define the workbench GuiCommands to perform actions.
