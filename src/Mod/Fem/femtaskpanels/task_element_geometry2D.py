# SPDX-FileCopyrightText: 2015 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "FreeCAD FEM element geometry 2D task panel for the document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package task_element_geometry2D
#  \ingroup FEM
#  \brief task panel for element geometry 2D object

from PySide import QtCore

import FreeCAD
import FreeCADGui

from femguiutils import selection_widgets
from . import base_femtaskpanel


class _TaskPanel(base_femtaskpanel._BaseTaskPanel):
    """
    The TaskPanel for editing References property of ElementGeometry2D objects
    """

    def __init__(self, obj):
        super().__init__(obj)

        # parameter widget
        self.parameter_widget = FreeCADGui.PySideUic.loadUi(
            FreeCAD.getHomePath() + "Mod/Fem/Resources/ui/ElementGeometry2D.ui"
        )
        QtCore.QObject.connect(
            self.parameter_widget.qsb_thickness,
            QtCore.SIGNAL("valueChanged(Base::Quantity)"),
            self.thickness_changed,
        )
        self.init_parameter_widget()

        # geometry selection widget
        self.selection_widget = selection_widgets.GeometryElementsSelection(
            obj.References, ["Face"], False, True
        )

        # form made from param and selection widget
        self.form = [self.parameter_widget, self.selection_widget]

    def accept(self):
        self.obj.Thickness = self.thickness
        self.obj.References = self.selection_widget.references
        self.selection_widget.finish_selection()
        return super().accept()

    def reject(self):
        self.selection_widget.finish_selection()
        return super().reject()

    def init_parameter_widget(self):
        self.thickness = self.obj.Thickness
        FreeCADGui.ExpressionBinding(self.parameter_widget.qsb_thickness).bind(
            self.obj, "Thickness"
        )
        self.parameter_widget.qsb_thickness.setProperty("value", self.thickness)

    def thickness_changed(self, base_quantity_value):
        self.thickness = base_quantity_value
