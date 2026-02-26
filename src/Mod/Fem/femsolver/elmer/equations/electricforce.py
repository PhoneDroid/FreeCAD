# SPDX-FileCopyrightText: 2020 Wilfried Hortschitz  <w.hortschitz@gmail.com>
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

__title__ = "FreeCAD FEM solver Elmer equation object Electricforce"
__author__ = "Wilfried Hortschitz"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{

from femtools import femutils
from ... import equationbase
from . import linear

SOLVER_EXEC_METHODS = ["After Timestep", "Always"]


def create(doc, name="Electricforce"):
    return femutils.createObject(doc, name, Proxy, ViewProxy)


class Proxy(linear.Proxy, equationbase.ElectricforceProxy):

    Type = "Fem::EquationElmerElectricforce"

    def __init__(self, obj):
        super().__init__(obj)

        obj.addProperty(
            "App::PropertyEnumeration",
            "ExecSolver",
            "Electric Force",
            (
                "That solver is only executed after solution converged\n"
                "To execute always, change to 'Always'"
            ),
            locked=True,
        )

        obj.ExecSolver = SOLVER_EXEC_METHODS
        obj.ExecSolver = "After Timestep"
        # Electrostatic has priority 10 and Electricforce needs
        # the potential field calculated by Electrostatic
        # therefore set priority to 5
        obj.Priority = 5


class ViewProxy(linear.ViewProxy, equationbase.ElectricforceViewProxy):
    pass


##  @}
