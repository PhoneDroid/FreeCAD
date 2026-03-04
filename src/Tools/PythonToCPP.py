#!/usr/bin/python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2004 Werner Mayer
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

import os, sys

# os.chdir("E:\\Develop\\FreeCADWin\\scripts")


try:
    file = open(sys.argv[1], encoding="utf-8")
except TypeError:
    file = open(sys.argv[1])

if len(sys.argv) > 4:
    sys.stderr.write("Wrong Parameter\n  Usage:\n  PythonToCPP Infile.py [Outfile][Variable]\n")

if len(sys.argv) > 2:
    try:
        out = open(sys.argv[2], "w", encoding="utf-8")
    except TypeError:
        out = open(sys.argv[2], "w")
else:
    out = sys.stdout

if len(sys.argv) > 3:
    identifier = sys.argv[3]
else:
    identifier = os.path.basename(sys.argv[1])
    identifier = identifier[:-3]

lines = file.readlines()

# We want to use this script for files in another directory, so we extract the actual file name
out.write("const char " + identifier + "[] =")

for line in lines:
    # remove new line
    line2 = line.rstrip()
    # replace special chars
    line2 = line2.replace("\\", "\\\\")
    line2 = line2.replace('"', '\\"')
    line2 = line2.replace("'", "\\'")

    # output
    # out.write(line)
    out.write('"' + line2 + '\\n"\n')

out.write(";\n\n\n")
