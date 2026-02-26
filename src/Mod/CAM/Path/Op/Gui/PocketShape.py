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
import Path.Op.Gui.FeatureExtension as PathFeatureExtensionsGui
import Path.Op.Gui.PocketBase as PathPocketBaseGui
import Path.Op.PocketShape as PathPocketShape
from PySide.QtCore import QT_TRANSLATE_NOOP

# lazily loaded modules
from lazy_loader.lazy_loader import LazyLoader

Part = LazyLoader("Part", globals(), "Part")

__title__ = "CAM Pocket Shape Operation UI"
__author__ = "sliptonic (Brad Collette)"
__url__ = "https://www.freecad.org"
__doc__ = "Pocket Shape operation page controller and command implementation."

if False:
    Path.Log.setLevel(Path.Log.Level.DEBUG, Path.Log.thisModule())
    Path.Log.trackModule(Path.Log.thisModule())
else:
    Path.Log.setLevel(Path.Log.Level.INFO, Path.Log.thisModule())

translate = FreeCAD.Qt.translate


class TaskPanelOpPage(PathPocketBaseGui.TaskPanelOpPage):
    """Page controller class for Pocket operation"""

    def pocketFeatures(self):
        """pocketFeatures() ... return FeaturePocket (see PathPocketBaseGui)"""
        return (
            PathPocketBaseGui.FeaturePocket
            | PathPocketBaseGui.FeatureOutline
            | PathPocketBaseGui.FeatureRestMachining
        )

    def taskPanelBaseLocationPage(self, obj, features):
        if not hasattr(self, "extensionsPanel"):
            self.extensionsPanel = PathFeatureExtensionsGui.TaskPanelExtensionPage(obj, features)
        return self.extensionsPanel


Command = PathOpGui.SetupOperation(
    "Pocket Shape",
    PathPocketShape.Create,
    TaskPanelOpPage,
    "CAM_Pocket",
    QT_TRANSLATE_NOOP("CAM_Pocket_Shape", "Pocket Shape"),
    QT_TRANSLATE_NOOP("CAM_Pocket_Shape", "Creates a pocket toolpath from a face or faces"),
    PathPocketShape.SetupProperties,
)

FreeCAD.Console.PrintLog("Loading PathPocketShapeGui... done\n")
