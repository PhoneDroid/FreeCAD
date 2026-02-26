# SPDX-FileCopyrightText: 2017-2023 Johannes Hartung <j.hartung@gmx.net>
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

__title__ = "FreeCAD Fenics XDMF mesh reader"
__author__ = "Johannes Hartung"
__url__ = "https://www.freecad.org"

## @package importFenicsXDMF
#  \ingroup FEM
#  \brief FreeCAD Fenics Mesh XDMF reader for FEM workbench

from FreeCAD import Console


def read_fenics_mesh_xdmf(xdmffilename):

    Console.PrintMessage("Not operational, yet\n")

    return {
        "Nodes": {},
        "Hexa8Elem": {},
        "Penta6Elem": {},
        "Tetra4Elem": {},
        "Tetra10Elem": {},
        "Penta15Elem": {},
        "Hexa20Elem": {},
        "Tria3Elem": {},
        "Tria6Elem": {},
        "Quad4Elem": {},
        "Quad8Elem": {},
        "Seg2Elem": {},
    }
