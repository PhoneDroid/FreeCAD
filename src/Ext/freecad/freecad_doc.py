# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2024 Werner Mayer
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

__title__="FreeCAD Python documentation"
__author__ = "Werner Mayer"
__url__ = "https://www.freecad.org"
__doc__ = "Helper module to use pydoc"


import os, sys, pydoc, pkgutil

class FreeCADDoc(pydoc.HTMLDoc):
    def index(self, dir, shadowed=None):
        """ Generate an HTML index for a directory of modules."""
        modpkgs = []
        if shadowed is None: shadowed = {}
        for importer, name, ispkg in pkgutil.iter_modules([dir]):
            if name == 'Init':
                continue
            if name == 'InitGui':
                continue
            if name[-2:] == '_d':
                continue
            modpkgs.append((name, '', ispkg, name in shadowed))
            shadowed[name] = 1

        if len(modpkgs) == 0:
            return None

        modpkgs.sort()
        contents = self.multicolumn(modpkgs, self.modpkglink)
        try:
            return self.bigsection(dir, '#ffffff', '#ee77aa', contents)
        except Exception as e:
            return self.bigsection(dir, 'pkg-content', contents)

def bltinlink(name):
    return '<a href=\"%s.html\">%s</a>' % (name, name)

def getIndexOld():
    pydoc.html = FreeCADDoc()
    title = 'FreeCAD Python Modules Index'

    heading = pydoc.html.heading('<big><big><strong>Python: Index of Modules</strong></big></big>','#ffffff', '#7799ee')

    names = list(filter(lambda x: x != '__main__', sys.builtin_module_names))
    contents = pydoc.html.multicolumn(names, bltinlink)
    indices = ['<p>' + pydoc.html.bigsection('Built-in Modules', '#ffffff', '#ee77aa', contents)]

    names = ['FreeCAD', 'FreeCADGui']
    contents = pydoc.html.multicolumn(names, bltinlink)
    indices.append('<p>' + pydoc.html.bigsection('Built-in FreeCAD Modules', '#ffffff', '#ee77aa', contents))

    seen = {}
    for dir in sys.path:
        dir = os.path.realpath(dir)
        ret = pydoc.html.index(dir, seen)
        if ret != None:
            indices.append(ret)

    contents = heading + ' '.join(indices) + '''<p align=right>
<font color=\"#909090\" face=\"helvetica, arial\"><strong>
pydoc</strong> by Ka-Ping Yee &lt;ping@lfw.org&gt;</font>'''

    htmldocument = pydoc.html.page(title, contents)
    return htmldocument

def getIndexNew():
    pydoc.html = FreeCADDoc()
    title = 'FreeCAD Python Modules Index'

    heading = pydoc.html.heading(
        '<strong class="title">Index of Modules</strong>'
    )

    names = list(filter(lambda x: x != '__main__', sys.builtin_module_names))
    contents = pydoc.html.multicolumn(names, bltinlink)
    indices = ['<p>' + pydoc.html.bigsection('Built-in Modules', 'index', contents)]

    names = ['FreeCAD', 'FreeCADGui']
    contents = pydoc.html.multicolumn(names, bltinlink)
    indices.append('<p>' + pydoc.html.bigsection('Built-in FreeCAD Modules', 'index', contents))

    seen = {}
    for dir in sys.path:
        dir = os.path.realpath(dir)
        ret = pydoc.html.index(dir, seen)
        if ret != None:
            indices.append(ret)

    contents = heading + ' '.join(indices) + '''<p align=right>
<font color=\"#909090\" face=\"helvetica, arial\"><strong>
pydoc</strong> by Ka-Ping Yee &lt;ping@lfw.org&gt;</font>'''

    htmldocument = pydoc.html.page(title, contents)
    return htmldocument

def getIndex():
    try:
        return getIndexOld()
    except Exception as e:
        return getIndexNew()

def getPage(page):
    object, name = pydoc.resolve(page)
    page = pydoc.html.page(pydoc.describe(object), pydoc.html.document(object, name))
    return page
