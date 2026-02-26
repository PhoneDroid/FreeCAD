# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2002 Jürgen Riegel <juergen.riegel@web.de>
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

# FreeCAD MakeNewBuildNbr script
#
# Increase the Build Number in Version.h

import time

# reading the last Version information
[FCVersionMajor, FCVersionMinor, FCVersionBuild, FCVersionDisDa, dummy] = open(
    "../Version.h", "r"
).readlines()

# increasing build number
BuildNumber = int(FCVersionBuild[23:-1]) + 1

# writing new Version.h File
open("../Version.h", "w").writelines(
    [
        FCVersionMajor,
        FCVersionMinor,
        FCVersionBuild[:23] + str(BuildNumber) + "\n",
        FCVersionDisDa[:23] + '"' + time.asctime() + '"',
    ]
)

# writing the ChangeLog.txt
open("../ChangeLog.txt", "a").write(
    "\nVersion: V"
    + FCVersionMajor[23:-1]
    + "."
    + FCVersionMinor[23:-1]
    + "B"
    + str(BuildNumber)
    + " Date: "
    + time.asctime()
    + " +++++++++++++++++++++++++++++++\n"
)
