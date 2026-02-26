# SPDX-FileCopyrightText: 2017 Markus Hovorka <m.hovorka@live.de>
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

__title__ = "FreeCAD FEM base constraint ViewProvider"
__author__ = "Markus Hovorka, Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## @package view_base_femconstraint
#  \ingroup FEM
#  \brief view provider for Python base constraint object

from FreeCAD import getResourceDir
from femviewprovider import view_base_femobject


class VPBaseFemConstraint(view_base_femobject.VPBaseFemObject):
    """Proxy View Provider for Pythons base constraint."""

    resource_symbol_dir = getResourceDir() + "Mod/Fem/Resources/symbols/"
