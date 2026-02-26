# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2015 Yorik van Havre <yorik@uncreated.net>
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

"""
This is an preprocessor to read gcode files produced from slic3r.
"""

import os
import Path
import FreeCAD
from builtins import open as pyopen


def open(filename):
    "called when freecad opens a file."
    docname = os.path.splitext(os.path.basename(filename))[0]
    doc = FreeCAD.newDocument(docname)
    insert(filename, doc.Name)


def insert(filename, docname):
    "called when freecad imports a file"
    gfile = pyopen(filename)
    gcode = gfile.read()
    gfile.close()
    gcode = parse(gcode)
    doc = FreeCAD.getDocument(docname)
    obj = doc.addObject("Path::Feature", "Path")
    path = Path.Path(gcode)
    obj.Path = path


def parse(inputstring):
    "parse(inputstring): returns a parsed output string"
    print("preprocessing...")

    # split the input by line
    lines = inputstring.split("\n")
    output = ""
    lastcommand = None

    for l in lines:
        # remove any leftover trailing and preceding spaces
        l = l.strip()
        if not l:
            # discard empty lines
            continue
        if l[0].upper() in ["N"]:
            # remove line numbers
            l = l.split(" ", 1)[1]
        if ";" in l:
            # replace ; comments with ()
            l = l.replace(";", "(")
            l = l + ")"
        if l[0].upper() in ["G", "M", "("]:
            # found a G or M command: we store it
            output += l + "\n"
            last = l[0].upper()
            for c in l[1:]:
                if not c.isdigit():
                    break
                else:
                    last += c
            lastcommand = last
        elif lastcommand:
            # no G or M command: we repeat the last one
            output += lastcommand + " " + l + "\n"

    print("done preprocessing.")
    return output


print(__name__ + " gcode preprocessor loaded.")
