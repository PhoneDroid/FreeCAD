#! python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2006 Jürgen Riegel <Jürgen.riegel@web.de>
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

import os
import sys
import getopt
import model.generateModel_Module
import model.generateModel_Python
import templates.templateModule
import templates.templateClassPyExport


Usage = """generate - generates a FreeCAD Module out of an XML or Python model

Usage:
   generate [Optionen] Model.xml/py Model2.xml/py Model3.xml/py ...

Options:
 -h, --help          print this help
 -o, --outputPath    specify the output path if differs from source path

Generate source code out of an model definition.

    Licence: GPL

Version:
  0.3
"""


# Globals


def generate_model(filename):
    if filename.endswith(".xml"):
        return model.generateModel_Module.parse(filename)
    elif filename.endswith(".pyi"):
        return model.generateModel_Python.parse(filename)
    raise ValueError("invalid file extension")


def generate(filename, outputPath):
    GenerateModelInst = generate_model(filename)

    if len(GenerateModelInst.Module) != 0:
        Module = templates.templateModule.TemplateModule()
        Module.outputDir = outputPath
        Module.module = GenerateModelInst.Module[0]
        Module.Generate()
        print("Done generating: " + GenerateModelInst.Module[0].Name)
    else:
        Export = templates.templateClassPyExport.TemplateClassPyExport()
        Export.outputDir = outputPath + "/"
        Export.inputDir = os.path.dirname(filename) + "/"
        Export.export = GenerateModelInst.PythonExport[0]
        Export.is_python = filename.endswith(".pyi")
        Export.Generate()
        if Export.is_python:
            Export.Compare()
        print("Done generating: " + GenerateModelInst.PythonExport[0].Name)


def main():
    verbose = False
    outputPath = ""

    class generateOutput:
        def write(self, data):
            pass

        def flush(self):  # mandatory for file-like objects
            pass

    try:
        opts, args = getopt.getopt(sys.argv[1:], "hvo:", ["help", "verbose", "outputPath="])
    except getopt.GetoptError:
        # print help information and exit:
        sys.stderr.write(Usage)
        sys.exit(2)

    # checking on the options
    for o, a in opts:
        if o in ("-h", "--help"):
            sys.stderr.write(Usage)
            sys.exit()
        if o in ("-o", "--outputPath"):
            outputPath = a
        if o in ("-v", "--verbose"):
            verbose = True

    if not verbose:
        sys.stdout = generateOutput()

    # running through the files
    if len(args) == 0:
        sys.stderr.write(Usage)
    else:
        for i in args:
            filename = os.path.abspath(i)
            if outputPath == "":
                head, _ = os.path.split(filename)
                generate(filename, head)
            else:
                generate(filename, outputPath)


if __name__ == "__main__":
    main()
