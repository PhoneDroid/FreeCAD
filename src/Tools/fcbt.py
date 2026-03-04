#!python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2004 Jürgen Riegel
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

#  FreeCAD Build Tool

import sys

help1 = """
FreeCAD Build Tool
Usage:
   fcbt <command name> [command parameter]
possible commands are:
 - DistSrc         (DS)   Build a source Distr. of the current source tree
 - DistBin         (DB)   Build a binary Distr. of the current source tree
 - DistSetup       (DI)   Build a Setup Distr. of the current source tree
 - DistSetup       (DUI)  Build a User Setup Distr. of the current source tree
 - DistAll         (DA)   Run all three above modules
 - NextBuildNumber (NBN)  Increase the Build Number of this Version
 - CreateModule    (CM)   Insert a new FreeCAD Module in the module directory
 - CreatePyModule  (CP)   Insert a new FreeCAD Python Module in the module directory

For help on the modules type:
  fcbt <command name> ?

"""

if len(sys.argv) < 2:
    sys.stdout.write(help1)
    sys.stdout.write("Insert command: ")
    sys.stdout.flush()
    CmdRaw = sys.stdin.readline()[:-1]
else:
    CmdRaw = sys.argv[1]

Cmd = CmdRaw.lower()


if Cmd == "distsrc" or Cmd == "ds":
    import fcbt.DistSrc
elif Cmd == "distbin" or Cmd == "db":
    import fcbt.DistBin
elif Cmd == "distsetup" or Cmd == "di":
    import fcbt.DistSetup
elif Cmd == "distsetup" or Cmd == "dui":
    import fcbt.DistUserSetup
elif Cmd == "distall" or Cmd == "da":
    import fcbt.DistSrc
    import fcbt.DistBin
    import fcbt.DistSetup
elif Cmd == "nextbuildnumber" or Cmd == "nbn":
    import fcbt.NextBuildNumber
elif Cmd == "createmodule" or Cmd == "cm":
    import fcbt.CreateModule
elif Cmd == "createpymodule" or Cmd == "cp":
    import fcbt.CreatePyModule
elif Cmd == "?" or Cmd == "help" or Cmd == "/h" or Cmd == "/?" or Cmd == "-h" or Cmd == "-help":
    sys.stdout.write(help1)
else:
    print(CmdRaw + " is an unknown command!\n")
    sys.exit(1)
