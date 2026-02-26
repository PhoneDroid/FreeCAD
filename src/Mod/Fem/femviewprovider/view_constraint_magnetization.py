# SPDX-FileCopyrightText: 2023 Uwe Stöhr <uwestoehr@lyx.org>
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

__title__ = "FreeCAD FEM constraint magnetization ViewProvider for the document object"
__author__ = "Uwe Stöhr"
__url__ = "https://www.freecad.org"

## @package view_constraint_magnetization
#  \ingroup FEM
#  \brief view provider for constraint magnetization object

from femtaskpanels import task_constraint_magnetization
from . import view_base_femconstraint


class VPConstraintMagnetization(view_base_femconstraint.VPBaseFemConstraint):

    def setEdit(self, vobj, mode=0):
        return view_base_femconstraint.VPBaseFemConstraint.setEdit(
            self, vobj, mode, task_constraint_magnetization._TaskPanel
        )
