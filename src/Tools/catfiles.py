#! python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2018 Werner Mayer
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

import sys, getopt

# import os # The code that needs this is commented out
import shutil


def main():
    outputfile = ""
    try:
        opts, args = getopt.getopt(sys.argv[1:], "o:", ["outputfile="])
    except getopt.GetoptError:
        pass

    for o, a in opts:
        if o in ("-o", "--outputfile"):
            outputfile = a

    # if os.path.exists(outputfile):
    #    do_not_create = True
    #    ts = os.path.getmtime(outputfile)
    #    for f in args:
    #        if os.path.getmtime(f) > ts:
    #            do_not_create = False
    #            break
    #
    #    if do_not_create:
    #        print ("Up-to-date file {0}".format(outputfile))
    #        return

    with open(outputfile, "wb") as wfd:
        for f in args:
            with open(f, "rb") as fd:
                shutil.copyfileobj(fd, wfd, 1024 * 1024 * 10)
        print("Created file {0}".format(outputfile))


if __name__ == "__main__":
    main()
