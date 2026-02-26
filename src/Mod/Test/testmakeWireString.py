#!/usr/bin/env python3
# SPDX-FileCopyrightText: 2013 WandererFan <wandererfan@gmail.com>
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


# tester for Part.makeWireString

import FreeCAD
import Part
import PartDesign

print("testWire started")

# test strings
# if string contains funky characters, it has to be declared as Unicode or it
# turns into the default encoding (usually utf8).  FT2 doesn't do utf8.
# String = 'Wide WMA_'                                 # wide glyphs for tracking
# String = 'Big'
# String = u'ecAnO'                                    # UCS-2 w/ only ASCII
# String = u'ucs2uéçÄñØ'                               # UCS-2
# String = 'utf8!uéçÄñØ'                               # UTF-8
# String = 'abcdefghijklmnopqrstuvwxyz0123456789'
# String = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
# String = 'Big Daddy'                                 # white space
# String = 'AVWAIXA.V'                                 # kerning
String = "FreeCAD"  # ASCII

# FontPath = '/usr/share/fonts/truetype/msttcorefonts/'
# FontName = 'Times_New_Roman_Italic.ttf'
FontPath = "/usr/share/fonts/truetype/msttcorefonts/"
FontName = "Arial.ttf"
# FontName = 'NOTArial.ttf'                            # font file not found error
# FontPath = '/usr/share/fonts/truetype/msttcorefonts/'
# FontName = 'ariali.ttf'                              # symlink to ttf
# FontPath = '/usr/share/fonts/truetype/'
# FontName = 'Peterbuilt.ttf'                          # overlapping script font
# FontPath = '/usr/share/fonts/truetype/'
# FontName = 'dyspepsia.ttf'                           # overlapping script font  # :)

Height = 2000  # out string height FCunits
Track = 0  # intercharacter spacing

print("testWire.py input String contains ", len(String), " characters.")

s = Part.makeWireString(String, FontPath, FontName, Height, Track)

print("returned from makeWireString")
print("testWire.py output contains ", len(s), " WireChars.")

for char in s:
    for contour in char:
        Part.show(contour)

print("testWire ended.")
