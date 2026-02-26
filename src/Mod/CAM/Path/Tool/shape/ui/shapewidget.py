# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2025 Samuel Abels <knipknap@gmail.com>
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
from typing import Optional
from PySide import QtGui, QtCore
from ..models.base import ToolBitShape


def _png2qpixmap(data, icon_size):
    pixmap = QtGui.QPixmap()
    pixmap.loadFromData(data, "PNG")
    # Scale the pixmap if the requested size is different
    if pixmap.size() != icon_size:
        pixmap = pixmap.scaled(
            icon_size,
            QtCore.Qt.KeepAspectRatio,
            QtCore.Qt.SmoothTransformation,
        )
    return pixmap


class ShapeWidget(QtGui.QWidget):
    def __init__(self, shape: ToolBitShape, icon_size: Optional[QtCore.QSize] = None, parent=None):
        super(ShapeWidget, self).__init__(parent)
        self.layout = QtGui.QVBoxLayout(self)
        self.layout.setAlignment(QtCore.Qt.AlignHCenter)

        self.shape = shape
        self.icon_size = icon_size or QtCore.QSize(263, 372)  # A4 aspect ratio
        self.icon_widget = QtGui.QLabel()
        self.layout.addWidget(self.icon_widget)

        self._update_icon()

    def _update_icon(self):
        ratio = self.devicePixelRatioF()
        size = self.icon_size * ratio
        icon = self.shape.get_icon()
        if icon:
            pixmap = icon.get_qpixmap(size)
            self.icon_widget.setPixmap(pixmap)
            return

        thumbnail = self.shape.get_thumbnail()
        if thumbnail:
            pixmap = _png2qpixmap(thumbnail, size)
            self.icon_widget.setPixmap(pixmap)
            return

        self.icon_widget.clear()  # Clear pixmap if no icon
