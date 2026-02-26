# SPDX-FileCopyrightText: 2018 Przemo Firszt <przemo@firszt.eu>
# SPDX-FileCopyrightText: 2018 Bernd Hahnebach <bernd@bimstatik.org>
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

# Unit test for the FEM module
# to get the right order import as is used
from femtest.app.test_femimport import TestFemImport as FemTest01
from femtest.app.test_common import TestFemCommon as FemTest02
from femtest.app.test_object import TestObjectCreate as FemTest03
from femtest.app.test_object import TestObjectType as FemTest04
from femtest.app.test_open import TestObjectOpen as FemTest05
from femtest.app.test_material import TestMaterialUnits as FemTest06
from femtest.app.test_mesh import TestMeshCommon as FemTest07
from femtest.app.test_mesh import TestMeshEleTetra10 as FemTest08
from femtest.app.test_mesh import TestMeshGroups as FemTest09
from femtest.app.test_result import TestResult as FemTest10
from femtest.app.test_ccxtools import TestCcxTools as FemTest11
from femtest.app.test_solver_elmer import TestSolverElmer as FemTest13
from femtest.app.test_solver_z88 import TestSolverZ88 as FemTest14

# dummy usage to get flake8 and lgtm quiet
False if FemTest01.__name__ else True
False if FemTest02.__name__ else True
False if FemTest03.__name__ else True
False if FemTest04.__name__ else True
False if FemTest05.__name__ else True
False if FemTest06.__name__ else True
False if FemTest07.__name__ else True
False if FemTest08.__name__ else True
False if FemTest09.__name__ else True
False if FemTest10.__name__ else True
False if FemTest11.__name__ else True
False if FemTest13.__name__ else True
False if FemTest14.__name__ else True
