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

__title__ = "FreeCAD FEM solver calculix ccx tools document object"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package solver_ccxtools
#  \ingroup FEM
#  \brief solver calculix ccx tools object

from .base_fempythonobject import _PropHelper
from .solver_calculix import SolverCalculiX


class SolverCcxTools(SolverCalculiX):
    """The Fem::FemSolver's Proxy python type, add solver specific properties"""

    Type = "Fem::SolverCcxTools"

    def __init__(self, obj):
        super().__init__(obj)

    def _get_properties(self):
        prop = super()._get_properties()

        # set analysis types supported by CcxTools solver
        for p in prop:
            if p.name == "AnalysisType":
                p.value = ["static", "frequency", "thermomech", "check", "buckling"]

        # remove unused properties
        prop = list(filter(lambda p: p.name != "ElectromagneticMode", prop))

        prop.append(
            _PropHelper(
                type="App::PropertyPath",
                name="WorkingDir",
                group="Solver",
                doc="Working directory for calculations.\n"
                + "Will only be used it is left blank in preferences",
                value="",
            )
        )

        return prop
