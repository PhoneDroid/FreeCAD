# SPDX-License-Identifier: LGPL-2.1-or-later
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

import sys
from PySide2 import QtWidgets
import FreeCADGui


class MainWindow(QtWidgets.QMainWindow):
    def showEvent(self, event):
        FreeCADGui.showMainWindow()
        self.setCentralWidget(FreeCADGui.getMainWindow())


app = QtWidgets.QApplication(sys.argv)
mw = MainWindow()
mw.resize(1200, 800)
mw.show()

# must be done a few times to update the GUI
app.processEvents()
app.processEvents()
app.processEvents()

import Part

cube = Part.makeBox(2, 2, 2)
# creates a document and a Part feature with the cube
Part.show(cube)
app.processEvents()
app.processEvents()
