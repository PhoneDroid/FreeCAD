# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

import unittest

import FreeCAD
import TestSketcherApp


class TestPolarPattern(unittest.TestCase):
    def setUp(self):
        self.Doc = FreeCAD.newDocument("PartDesignTestPolarPattern")

    def testXAxisPolarPattern(self):
        self.Body = self.Doc.addObject("PartDesign::Body", "Body")
        self.Box = self.Doc.addObject("PartDesign::AdditiveBox", "Box")
        self.Body.addObject(self.Box)
        self.Box.Length = 10.00
        self.Box.Width = 10.00
        self.Box.Height = 10.00
        self.Doc.recompute()
        self.PolarPattern = self.Doc.addObject("PartDesign::PolarPattern", "PolarPattern")
        self.PolarPattern.Originals = [self.Box]
        self.PolarPattern.Axis = (self.Doc.X_Axis, [""])
        self.PolarPattern.Angle = 360
        self.PolarPattern.Occurrences = 4
        self.PolarPattern.Refine = True
        self.Body.addObject(self.PolarPattern)
        self.Doc.recompute()
        self.assertAlmostEqual(self.PolarPattern.Shape.Volume, 4000)
        # self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 66)  # TODO
        self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 26)

    def testYAxisPolarPattern(self):
        self.Body = self.Doc.addObject("PartDesign::Body", "Body")
        self.Box = self.Doc.addObject("PartDesign::AdditiveBox", "Box")
        self.Body.addObject(self.Box)
        self.Box.Length = 10.00
        self.Box.Width = 10.00
        self.Box.Height = 10.00
        self.Doc.recompute()
        self.PolarPattern = self.Doc.addObject("PartDesign::PolarPattern", "PolarPattern")
        self.PolarPattern.Originals = [self.Box]
        self.PolarPattern.Axis = (self.Doc.Y_Axis, [""])
        self.PolarPattern.Angle = 360
        self.PolarPattern.Occurrences = 4
        self.PolarPattern.Refine = True
        self.Body.addObject(self.PolarPattern)
        self.Doc.recompute()
        self.assertAlmostEqual(self.PolarPattern.Shape.Volume, 4000)
        # self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 66)  # TODO
        self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 26)

    def testZAxisPolarPattern(self):
        self.Body = self.Doc.addObject("PartDesign::Body", "Body")
        self.Box = self.Doc.addObject("PartDesign::AdditiveBox", "Box")
        self.Body.addObject(self.Box)
        self.Box.Length = 10.00
        self.Box.Width = 10.00
        self.Box.Height = 10.00
        self.Doc.recompute()
        self.PolarPattern = self.Doc.addObject("PartDesign::PolarPattern", "PolarPattern")
        self.PolarPattern.Originals = [self.Box]
        self.PolarPattern.Axis = (self.Doc.Z_Axis, [""])
        self.PolarPattern.Angle = 360
        self.PolarPattern.Occurrences = 4
        self.PolarPattern.Refine = True
        self.Body.addObject(self.PolarPattern)
        self.Doc.recompute()
        self.assertAlmostEqual(self.PolarPattern.Shape.Volume, 4000)
        # self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 66)  # TODO
        self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 26)

    def testNormalSketchAxisPolarPattern(self):
        self.Body = self.Doc.addObject("PartDesign::Body", "Body")
        self.PadSketch = self.Doc.addObject("Sketcher::SketchObject", "SketchPad")
        self.Body.addObject(self.PadSketch)
        TestSketcherApp.CreateRectangleSketch(self.PadSketch, (0, 0), (10, 10))
        self.Doc.recompute()
        self.Pad = self.Doc.addObject("PartDesign::Pad", "Pad")
        self.Body.addObject(self.Pad)
        self.Pad.Profile = self.PadSketch
        self.Pad.Length = 10
        self.Doc.recompute()
        self.PolarPattern = self.Doc.addObject("PartDesign::PolarPattern", "PolarPattern")
        self.PolarPattern.Originals = [self.Pad]
        self.PolarPattern.Axis = (self.PadSketch, ["N_Axis"])
        self.PolarPattern.Angle = 360
        self.PolarPattern.Occurrences = 4
        self.PolarPattern.Refine = True
        self.Body.addObject(self.PolarPattern)
        self.Doc.recompute()
        self.assertAlmostEqual(self.PolarPattern.Shape.Volume, 4000)
        # self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 66)  # TODO
        self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 26)

    def testVerticalSketchAxisPolarPattern(self):
        self.Body = self.Doc.addObject("PartDesign::Body", "Body")
        self.PadSketch = self.Doc.addObject("Sketcher::SketchObject", "SketchPad")
        self.Body.addObject(self.PadSketch)
        TestSketcherApp.CreateRectangleSketch(self.PadSketch, (0, 0), (10, 10))
        self.Doc.recompute()
        self.Pad = self.Doc.addObject("PartDesign::Pad", "Pad")
        self.Body.addObject(self.Pad)
        self.Pad.Profile = self.PadSketch
        self.Pad.Length = 10
        self.Doc.recompute()
        self.PolarPattern = self.Doc.addObject("PartDesign::PolarPattern", "PolarPattern")
        self.PolarPattern.Originals = [self.Pad]
        self.PolarPattern.Axis = (self.PadSketch, ["V_Axis"])
        self.PolarPattern.Angle = 360
        self.PolarPattern.Occurrences = 4
        self.PolarPattern.Refine = True
        self.Body.addObject(self.PolarPattern)
        self.Doc.recompute()
        self.assertAlmostEqual(self.PolarPattern.Shape.Volume, 4000)
        # self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 66)  # TODO
        self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 26)

    def testHorizontalSketchAxisPolarPattern(self):
        self.Body = self.Doc.addObject("PartDesign::Body", "Body")
        self.PadSketch = self.Doc.addObject("Sketcher::SketchObject", "SketchPad")
        self.Body.addObject(self.PadSketch)
        TestSketcherApp.CreateRectangleSketch(self.PadSketch, (0, 0), (10, 10))
        self.Doc.recompute()
        self.Pad = self.Doc.addObject("PartDesign::Pad", "Pad")
        self.Body.addObject(self.Pad)
        self.Pad.Profile = self.PadSketch
        self.Pad.Length = 10
        self.Doc.recompute()
        self.PolarPattern = self.Doc.addObject("PartDesign::PolarPattern", "PolarPattern")
        self.PolarPattern.Originals = [self.Pad]
        self.PolarPattern.Axis = (self.PadSketch, ["H_Axis"])
        self.PolarPattern.Angle = 360
        self.PolarPattern.Occurrences = 4
        self.PolarPattern.Refine = True
        self.Body.addObject(self.PolarPattern)
        self.Doc.recompute()
        self.assertAlmostEqual(self.PolarPattern.Shape.Volume, 4000)
        # 26 original plus 3 new instances:
        # First and second have 4 new vertexes, 8 new edges and 5 new faces
        # Final one has  2 new vertexes, 5 new edges and original loses one face.
        # That makes 40.
        # self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 66)  # TODO
        self.assertEqual(self.PolarPattern.Shape.ElementMapSize, 26)

    def tearDown(self):
        # closing doc
        FreeCAD.closeDocument("PartDesignTestPolarPattern")
        # print ("omit closing document for debugging")
