# SPDX-FileCopyrightText: 2022 Wanderer Fan <wandererfan@gmail.com>
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
"""Provides view moving functions for TD Tools."""

import FreeCAD as App

#move a simple view and its dependents (dimensions, balloons, etc) from fromPage to toPage
def simpleViewMove(view, fromPage, toPage, copy):
    deps = [x for x in view.InList if x.isDerivedFrom("TechDraw::DrawView")]
    if not copy:
        for d in deps:
            rc = fromPage.removeView(d)
        rc = fromPage.removeView(view)
        #redraw fromPage without view
        fromPage.requestPaint()

    toPage.addView(view)
    for d in deps:
        toPage.addView(d)

    App.ActiveDocument.recompute()  #update views & dependents if necessary
    return

#move a section view, its Base View and all its dependents (items, dimensions, balloons, etc) of both from fromPage to toPage
def sectionViewMove(view, fromPage, toPage, copy):
    #move the base
    base = view.BaseView
    simpleViewMove(base, fromPage, toPage, copy)

#move a projection group and all its dependents (items, dimensions, balloons, etc) from fromPage to toPage
def projGroupMove(view, fromPage, toPage, copy):
    items = [x for x in view.Views if x.isDerivedFrom("TechDraw::DrawProjGroupItem")]
    if not copy:
        for i in items:
            id = [x for x in i.InList if x.isDerivedFrom("TechDraw::DrawView")]
            for dep in id:
                fromPage.removeView(dep)
        fromPage.removeView(view)

    toPage.addView(view)
    for i in items:
        id = [x for x in i.InList if x.isDerivedFrom("TechDraw::DrawView")]
        for dep in id:
            if not dep.isDerivedFrom("TechDraw::DrawProjGroup"):   #probably superfluous
                toPage.addView(dep)

def moveView(view, fromPage, toPage, copy=False):
    if view.isDerivedFrom("TechDraw::DrawProjGroup"):
        projGroupMove(view, fromPage, toPage, copy)
    elif view.isDerivedFrom("TechDraw::DrawViewSection") or view.isDerivedFrom("TechDraw::DrawViewDetail"):
        sectionViewMove(view, fromPage, toPage, copy)
    elif view.isDerivedFrom("TechDraw::DrawView"):
        simpleViewMove(view, fromPage, toPage, copy)

