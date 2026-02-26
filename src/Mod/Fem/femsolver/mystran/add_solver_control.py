# SPDX-FileCopyrightText: 2021 Bernd Hahnebach <bernd@bimstatik.org>
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

__title__ = "Mystran add solver control"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{


def add_solver_control(f, model, mystran_writer):

    # write the pyNastran code which will be executed into the file
    f.write(pynas_code)

    # print(model.get_bdf_stats())
    exec(pynas_code)
    # print(model.get_bdf_stats())

    return model


pynas_code = """
# executive control
model.sol = 101


# params cards
model.add_param(key="POST", values=-1)
# model.add_param(key="PRTMAXIM", values="YES")  # not recognized by Mystran


# case control
from pyNastran.bdf.bdf import CaseControlDeck
cc = CaseControlDeck([
    "ECHO = NONE",
    "TITLE = pyNastran for generating solverinput for for Mystran",
    "SUBCASE 1",
    "  SUBTITLE = Default",
    "  LOAD = 1",
    "  SPC = 1",
    "  SPCFORCES(SORT1,REAL) = ALL",
    "  STRESS(SORT1,REAL,VONMISES,BILIN) = ALL",
    "  DISPLACEMENT(SORT1,REAL) = ALL",
])
model.case_control_deck = cc
# model.validate()  # creates an error
"""


##  @}
