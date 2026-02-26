# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2016 sliptonic <shopinthewoods@gmail.com>
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
from PySide import QtCore, QtGui

translate = FreeCAD.Qt.translate


_dressups = []


def RegisterDressup(dressup):
    _dressups.append(dressup)


class DressupPreferencesPage:
    def __init__(self, parent=None):
        self.form = QtGui.QWidget()
        self.form.setWindowTitle(translate("CAM_PreferencesPathDressup", "Dressups"))

        layout = QtGui.QVBoxLayout(self.form)
        pages = []
        for dressup in _dressups:
            page = dressup.preferencesPage()
            layout.addWidget(page.form)
            pages.append(page)
        self.pages = pages

    def saveSettings(self):
        for page in self.pages:
            page.saveSettings()

    def loadSettings(self):
        for page in self.pages:
            page.loadSettings()
