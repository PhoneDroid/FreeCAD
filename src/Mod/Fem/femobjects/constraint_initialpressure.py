# SPDX-FileCopyrightText: 2022 Uwe Stöhr <uwestoehr@lyx.org>
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

__title__ = "FreeCAD FEM constraint initial pressure document object"
__author__ = "Uwe Stöhr"
__url__ = "https://www.freecad.org"

## @package constraint_initialpressure
#  \ingroup FEM
#  \brief constraint initial pressure object

from . import base_fempythonobject


class ConstraintInitialPressure(base_fempythonobject.BaseFemPythonObject):

    Type = "Fem::ConstraintInitialPressure"

    def __init__(self, obj):
        super().__init__(obj)
        self.add_properties(obj)

    def onDocumentRestored(self, obj):
        self.add_properties(obj)

    def add_properties(self, obj):
        if not hasattr(obj, "Pressure"):
            obj.addProperty("App::PropertyPressure", "Pressure", "Parameter", "Initial Pressure")
            obj.setPropertyStatus("Pressure", "LockDynamic")
            # we initialize 1 bar
            obj.Pressure = "100 kPa"
