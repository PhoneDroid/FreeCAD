# SPDX-FileCopyrightText: 2025 Stefan Tröger <stefantroeger@gmx.net>
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

__title__ = "FreeCAD FEM histogram plot task panel"
__author__ = "Stefan Tröger"
__url__ = "https://www.freecad.org"

## @package task_post_histogram
#  \ingroup FEM
#  \brief task panel for post histogram plot

from PySide import QtCore, QtGui

import FreeCAD
import FreeCADGui

from . import base_fempostpanel
from femguiutils import extract_link_view as elv

translate = FreeCAD.Qt.translate


class _TaskPanel(base_fempostpanel._BasePostTaskPanel):
    """
    The TaskPanel for editing properties of glyph filter
    """

    def __init__(self, vobj):
        super().__init__(vobj.Object)

        # data widget
        self.data_widget = QtGui.QWidget()
        self.data_widget.show_table = QtGui.QPushButton()
        self.data_widget.show_table.setText(translate("FEM", "Show Table"))

        vbox = QtGui.QVBoxLayout()
        vbox.addWidget(self.data_widget.show_table)
        vbox.addSpacing(10)

        extracts = elv.ExtractLinkView(self.obj, False, self)
        vbox.addWidget(extracts)

        self.data_widget.setLayout(vbox)
        self.data_widget.setWindowTitle(translate("FEM", "Table Data"))
        self.data_widget.setWindowIcon(FreeCADGui.getIcon(":/icons/FEM_PostSpreadsheet.svg"))

        self.__init_widgets()

        # form made from param and selection widget
        self.form = [self.data_widget]

    # Setup functions
    # ###############

    def __init_widgets(self):

        # connect data widget
        self.data_widget.show_table.clicked.connect(self.showTable)

    @QtCore.Slot()
    def showTable(self):
        self.obj.ViewObject.Proxy.show_visualization()
