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

__title__ = "Mystran add femelement materials"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{


from FreeCAD import Units


def add_femelement_material(f, model, mystran_writer):

    # generate pyNastran code
    # only use the first material object
    mat_obj = mystran_writer.member.mats_linear[0]["Object"]
    YM = Units.Quantity(mat_obj.Material["YoungsModulus"])
    YM_in_MPa = YM.getValueAs("MPa").Value
    PR = float(mat_obj.Material["PoissonRatio"])
    pynas_code = "# mat1 card, material properties for linear isotropic material\n"
    pynas_code += f"mat = model.add_mat1(mid=1, E={YM_in_MPa:.1f}, G=None, nu={PR})\n\n\n"

    # write the pyNastran code
    f.write(pynas_code)

    # execute pyNastran code to add data to the model
    # print(model.get_bdf_stats())
    exec(pynas_code)
    # print(model.get_bdf_stats())

    return model


##  @}
