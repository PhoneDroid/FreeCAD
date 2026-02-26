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

from PySide.QtCore import QT_TRANSLATE_NOOP
import FreeCAD
import Path
import Path.Op.Gui.Base as PathOpGui
import Path.Op.Gui.PocketBase as PathPocketBaseGui
import Path.Op.MillFace as PathMillFace
import Path.Op.PocketShape as PathPocketShape
import FreeCADGui

__title__ = "CAM Face Mill Operation UI"
__author__ = "sliptonic (Brad Collette)"
__url__ = "https://www.freecad.org"
__doc__ = "Face Mill operation page controller and command implementation."

if False:
    Path.Log.setLevel(Path.Log.Level.DEBUG, Path.Log.thisModule())
    Path.Log.trackModule(Path.Log.thisModule())
else:
    Path.Log.setLevel(Path.Log.Level.INFO, Path.Log.thisModule())


class TaskPanelOpPage(PathPocketBaseGui.TaskPanelOpPage):
    """Page controller class for the face milling operation."""

    def getForm(self):
        Path.Log.track()
        """getForm() ... return UI"""

        form = FreeCADGui.PySideUic.loadUi(":/panels/PageOpPocketFullEdit.ui")
        comboToPropertyMap = [
            ("cutMode", "CutMode"),
            ("clearingPattern", "ClearingPattern"),
            ("boundaryShape", "BoundaryShape"),
        ]

        enumTups = PathMillFace.ObjectFace.propertyEnumerations(dataType="raw")
        enumTups.update(PathPocketShape.ObjectPocket.pocketPropertyEnumerations(dataType="raw"))

        self.populateCombobox(form, enumTups, comboToPropertyMap)
        return form

    def pocketFeatures(self):
        """pocketFeatures() ... return FeatureFacing (see PathPocketBaseGui)"""
        return PathPocketBaseGui.FeatureFacing


Command = PathOpGui.SetupOperation(
    "MillFace",
    PathMillFace.Create,
    TaskPanelOpPage,
    "CAM_Face",
    QT_TRANSLATE_NOOP("CAM_MillFace", "Face"),
    QT_TRANSLATE_NOOP("CAM_MillFace", "Create a Facing Operation from a model or face"),
    PathMillFace.SetupProperties,
)

FreeCAD.Console.PrintLog("Loading PathMillFaceGui... done\n")
