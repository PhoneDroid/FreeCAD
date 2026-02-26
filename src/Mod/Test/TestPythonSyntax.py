# SPDX-FileCopyrightText: 2018 looooo <sppedflyer@gmail.com>
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
################################################################################/

import os
import ast
import unittest
import FreeCAD as App


def test_python_syntax(rootdir, whitelist=None):
    whitelist = whitelist or []
    log = []
    for sub_dir, dirs, files in os.walk(rootdir):
        for fn in files:
            kargs = {}
            kargs["encoding"] = "utf-8"
            if (not fn in whitelist) and os.path.splitext(fn)[1] == ".py":
                with open(os.path.join(sub_dir, fn), **kargs) as py_file:
                    try:
                        ast.parse(py_file.read())
                    except SyntaxError as err:
                        log.append(str(err).replace("<unknown>", os.path.join(sub_dir, fn)))
    message = "\n\n" + "#" * 30 + "\n"
    message += "{} python files are not parseable:\n\n".format(len(log))
    for i, m in enumerate(log):
        message += str(i + 1) + " " + m + "\n"
    if log:
        raise RuntimeError(
            "there are some files not parse-able with the used python-interpreter" + message
        )
    else:
        return


class PythonSyntaxTestCase(unittest.TestCase):
    """
    Test Case to test python syntax of all python files in FreeCAD
    """

    def setUp(self):
        self.whitelist = []
        self.whitelist += [
            "ap203_configuration_controlled_3d_design_of_mechanical_parts_and_assemblies_mim_lf.py"
        ]
        self.whitelist += ["automotive_design.py"]
        self.whitelist += ["ifc2x3.py"]
        self.whitelist += ["ifc4.py"]

    def testAll(self):
        mod_dir = os.path.join(App.getHomePath(), "Mod")
        test_python_syntax(mod_dir, self.whitelist)
