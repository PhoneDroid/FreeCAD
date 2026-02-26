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

__title__ = "FreeCAD FEM post extractor object task panel"
__author__ = "Stefan Tröger"
__url__ = "https://www.freecad.org"

## @package task_post_extractor
#  \ingroup FEM
#  \brief universal task dialog for extractor objects.

from PySide import QtCore, QtGui

from . import base_fempostpanel


class _ExtractorTaskPanel(base_fempostpanel._BasePostTaskPanel):
    """
    The TaskPanel for editing properties extractor objects. The actual UI is
    provided by the viewproviders. This allows using a universal task panel
    """

    def __init__(self, obj):
        super().__init__(obj)

        # form is used to display individual task panels
        app = obj.ViewObject.Proxy.get_app_edit_widget(self)
        app.setWindowTitle("Data Extraction")
        app.setWindowIcon(obj.ViewObject.Icon)
        view = obj.ViewObject.Proxy.get_view_edit_widget(self)
        view.setWindowTitle("Visualization Settings")
        view.setWindowIcon(obj.ViewObject.Icon)

        self.form = [app, view]
