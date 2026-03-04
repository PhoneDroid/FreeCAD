#! python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009 Jürgen Riegel <Jürgen.riegel@web.de>
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

Usage = """examplePy2wiki - generating a wiki text out of a python example

Usage:
   examplePy2wiki [Optionen]

Options:
 -o  --out-file=FILENAME  use this file name for output, default resources.qrc
 -i, --in-file=FILENAME   directory to search, default PWD
 -h, --help               print this help message

This program reads python files and generate a output suited for a Mediawiki page.
The python comments get translated to text and the code blocks get intended to
show up us code in the wiki.


  Licence: GPL V2

Version:
  0.1
"""

import os, sys, string, getopt


def Process(line):
    if line[0:2] == "# ":
        return line[2:]
    else:
        return " " + line


def main():

    try:
        opts, args = getopt.getopt(
            sys.argv[1:], "hi:o:", ["help", "verbose", "in-file=", "out-file="]
        )
    except getopt.GetoptError:
        # print help information and exit:
        sys.stderr.write(Usage)
        sys.exit(2)

    # checking on the options
    for o, a in opts:
        if o in ("-h", "--help"):
            sys.stderr.write(Usage)
            sys.exit()
        if o in ("-o", "--out-file"):
            outfile = open(a, "w")
        if o in ("-i", "--in-file"):
            infile = open(a, "r")

    lines = infile.readlines()
    for l in lines:
        outfile.write(Process(l))
        # print l


if __name__ == "__main__":
    main()
