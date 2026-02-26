# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2017 sliptonic <shopinthewoods@gmail.com>
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

import FreeCAD
import Path
import Path.Op.Gui.Base as PathOpGui
import Path.Op.Gui.PocketBase as PathPocketBaseGui
import Path.Op.Pocket as PathPocket

from PySide.QtCore import QT_TRANSLATE_NOOP

if False:
    Path.Log.setLevel(Path.Log.Level.DEBUG, Path.Log.thisModule())
    Path.Log.trackModule(Path.Log.thisModule())
else:
    Path.Log.setLevel(Path.Log.Level.INFO, Path.Log.thisModule())


__title__ = "CAM Pocket Operation UI"
__author__ = "sliptonic (Brad Collette)"
__url__ = "https://www.freecad.org"
__doc__ = "Pocket operation page controller and command implementation."


class TaskPanelOpPage(PathPocketBaseGui.TaskPanelOpPage):
    """Page controller class for Pocket operation"""

    def pocketFeatures(self):
        """pocketFeatures() ... return FeaturePocket (see PathPocketBaseGui)"""
        return PathPocketBaseGui.FeaturePocket | PathPocketBaseGui.FeatureRestMachining


Command = PathOpGui.SetupOperation(
    "Pocket3D",
    PathPocket.Create,
    TaskPanelOpPage,
    "CAM_3DPocket",
    QT_TRANSLATE_NOOP("CAM_Pocket3D", "3D Pocket"),
    QT_TRANSLATE_NOOP("CAM_Pocket3D", "Creates a 3D Pocket toolpath from a face or faces"),
    PathPocket.SetupProperties,
)

FreeCAD.Console.PrintLog("Loading PathPocketGui... done\n")
