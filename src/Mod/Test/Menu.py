# SPDX-FileCopyrightText: 2005 Werner Mayer <werner.wm.mayer@gmx.de>
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

# Menu test module

import FreeCAD, os, unittest, FreeCADGui


# ---------------------------------------------------------------------------
# define the functions to test the FreeCAD base code
# ---------------------------------------------------------------------------

# def suite():
#    suite = unittest.TestSuite()
#    suite.addTest(DocTestCase("DocumentProperties"))
#    suite.addTest(DocTestCase("DocumentLabels"))
#    suite.addTest(DocTestCase("DocumentSaveAndRestore"))
#    return suite


class MenuCreateCases(unittest.TestCase):
    def setUp(self):
        FreeCADGui.activateWorkbench("TestWorkbench")
        FreeCAD.Console.PrintLog("Setup Test menu...\n")
        list = ["Test_TestAll", "Test_TestDoc", "Test_TestBase", "Test_TestWork"]
        w = FreeCADGui.getWorkbench("TestWorkbench")
        w.appendMenu("TestMenu", list)

    def testMenu(self):
        # check menu for items
        FreeCAD.Console.PrintLog("Checking Test menu...\n")
        w = FreeCADGui.getWorkbench("TestWorkbench")
        list = w.listMenus()
        self.b = False
        for i in list:
            if i == "TestMenu":
                self.b = True
        self.assertTrue(self.b, "Test menu not found")

    def tearDown(self):
        if self.b:
            FreeCAD.Console.PrintLog("Test menu successfully added\n")
        else:
            FreeCAD.Console.PrintLog("Adding Test menu failed\n")


class MenuDeleteCases(unittest.TestCase):
    def setUp(self):
        FreeCADGui.activateWorkbench("TestWorkbench")
        FreeCAD.Console.PrintLog("Remove Test menu...\n")
        w = FreeCADGui.getWorkbench("TestWorkbench")
        w.removeMenu("TestMenu")

    def testMenu(self):
        # check menu for items
        FreeCAD.Console.PrintLog("Checking Test menu...\n")
        w = FreeCADGui.getWorkbench("TestWorkbench")
        list = w.listMenus()
        self.b = True
        for i in list:
            if i == "TestMenu":
                self.b = False
        self.assertTrue(self.b == True, "Test menu still added")

    def tearDown(self):
        if self.b:
            FreeCAD.Console.PrintLog("Test menu successfully removed\n")
        else:
            FreeCAD.Console.PrintLog("Removing Test menu failed\n")
