# SPDX-FileCopyrightText: 2007 Jürgen Riegel <juergen.riegel@web.de>
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

# Open and edit only in UTF-8 !!!!!!

import FreeCAD, os, unittest, tempfile


# ---------------------------------------------------------------------------
# define the functions to test the FreeCAD Document code
# ---------------------------------------------------------------------------


class UnicodeBasicCases(unittest.TestCase):
    def setUp(self):
        self.Doc = FreeCAD.newDocument("CreateTest")

    def testUnicodeLabel(self):
        L1 = self.Doc.addObject("App::FeatureTest", "Label_1")
        L1.Label = "हिन्दी"
        self.assertTrue(L1.Label == "हिन्दी")

    def tearDown(self):
        # closing doc
        FreeCAD.closeDocument("CreateTest")


class DocumentSaveRestoreCases(unittest.TestCase):
    def setUp(self):
        self.Doc = FreeCAD.newDocument("SaveRestoreTests")
        L1 = self.Doc.addObject("App::FeatureTest", "Label_1")
        L1.Label = "हिन्दी"
        self.TempPath = tempfile.gettempdir()
        FreeCAD.Console.PrintLog("  Using temp path: " + self.TempPath + "\n")

    def testSaveAndRestore(self):
        # saving and restoring
        SaveName = self.TempPath + os.sep + "UnicodeTest.FCStd"
        self.Doc.saveAs(SaveName)
        FreeCAD.closeDocument("SaveRestoreTests")
        self.Doc = FreeCAD.open(SaveName)
        self.assertTrue(self.Doc.Label_1.Label == "हिन्दी")
        FreeCAD.closeDocument("UnicodeTest")
        FreeCAD.newDocument("SaveRestoreTests")

    def tearDown(self):
        # closing doc
        FreeCAD.closeDocument("SaveRestoreTests")
