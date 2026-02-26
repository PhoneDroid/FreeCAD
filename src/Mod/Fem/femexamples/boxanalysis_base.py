# SPDX-FileCopyrightText: 2019 Bernd Hahnebach <bernd@bimstatik.org>
# SPDX-FileCopyrightText: 2020 Sudhanshu Dubey <sudhanshu.thethunder@gmail.com>
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

import FreeCAD

import Fem
import ObjectsFem

from .manager import get_meshname
from .manager import init_doc
from .meshes import generate_mesh


def setup_boxanalysisbase(doc=None, solvertype="ccxtools", test_mode=False):

    # init FreeCAD document
    if doc is None:
        doc = init_doc()

    # geometric objects
    # object name is important in this base setup method
    # all module which use this base setup, use the object name to find the object
    geom_obj = doc.addObject("Part::Box", "Box")
    geom_obj.Height = geom_obj.Width = geom_obj.Length = 10
    doc.recompute()

    if FreeCAD.GuiUp:
        geom_obj.ViewObject.Document.activeView().viewAxonometric()
        geom_obj.ViewObject.Document.activeView().fitAll()

    # analysis
    analysis = ObjectsFem.makeAnalysis(doc, "Analysis")

    # material
    material_obj = ObjectsFem.makeMaterialSolid(doc, "MechanicalMaterial")
    mat = material_obj.Material
    mat["Name"] = "Steel-Generic"
    mat["YoungsModulus"] = "200000 MPa"
    mat["PoissonRatio"] = "0.30"
    mat["Density"] = "7900 kg/m^3"
    material_obj.Material = mat
    analysis.addObject(material_obj)

    # mesh
    femmesh_obj = analysis.addObject(ObjectsFem.makeMeshGmsh(doc, get_meshname()))[0]
    femmesh_obj.Shape = geom_obj
    femmesh_obj.SecondOrderLinear = False
    femmesh_obj.CharacteristicLengthMin = "8.0 mm"
    femmesh_obj.ElementOrder = "2nd"

    # generate the mesh
    success = False
    if not test_mode:
        success = generate_mesh.mesh_from_mesher(femmesh_obj, "gmsh")
    if not success:
        # try to create from existing rough mesh
        from .meshes.mesh_boxanalysis_tetra10 import create_nodes, create_elements

        fem_mesh = generate_mesh.mesh_from_existing(create_nodes, create_elements)
        femmesh_obj.FemMesh = fem_mesh

    doc.recompute()
    return doc
