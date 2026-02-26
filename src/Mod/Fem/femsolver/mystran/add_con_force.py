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

__title__ = "Mystran add force constraint"
__author__ = "Bernd Hahnebach"
__url__ = "https://www.freecad.org"

## \addtogroup FEM
#  @{


def add_con_force(f, model, mystran_writer):

    # generate pyNastran code
    # force card
    scale_factors = []
    load_ids = []
    force_code = "# force cards, mesh node loads\n"
    for i, femobj in enumerate(mystran_writer.member.cons_force):

        sid = i + 2  # 1 will be the id of the load card
        scale_factors.append(1.0)
        load_ids.append(sid)
        force_obj = femobj["Object"]
        # print(force_obj.Name)

        force_code += f"# {force_obj.Name}\n"
        dirvec = femobj["Object"].DirectionVector
        print(femobj["NodeLoadTable"])
        for ref_shape in femobj["NodeLoadTable"]:
            force_code += f"# {ref_shape[0]}\n"
            for n in sorted(ref_shape[1]):
                # the loads in ref_shape[1][n] are without unit
                node_load = ref_shape[1][n]
                force_code += "model.add_force(sid={}, node={}, mag={}, xyz=({}, {}, {}))\n".format(
                    sid, n, node_load, dirvec.x, dirvec.y, dirvec.z
                )
        force_code += "\n"

    # generate calce factors lists
    # load card, static load combinations
    load_code = "model.add_load(sid=1, scale=1.0, scale_factors={}, load_ids={})\n\n\n".format(
        scale_factors, load_ids
    )

    pynas_code = f"{force_code}\n{load_code}"
    # print(pynas_code)

    # write the pyNastran code
    f.write(pynas_code)

    # execute pyNastran code to add data to the model
    # print(model.get_bdf_stats())
    exec(pynas_code)
    # print(model.get_bdf_stats())

    return model


##  @}
