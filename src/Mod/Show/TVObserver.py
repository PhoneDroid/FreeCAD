# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2019 Victor Titov (DeepSOIC) <vv.titov@gmail.com
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

import FreeCAD


class TVObserver(object):
    def __init__(self):
        FreeCAD.addDocumentObserver(self)

    def stop(self):
        FreeCAD.removeDocumentObserver(self)

    def slotStartSaveDocument(self, doc, filepath):
        from . import TVStack

        TVStack._slotStartSaveDocument(doc)

    def slotFinishSaveDocument(self, doc, filepath):
        from . import TVStack

        TVStack._slotFinishSaveDocument(doc)

    def slotDeletedDocument(self, doc):
        from . import TVStack

        TVStack._slotDeletedDocument(doc)


# handle module reload
if "observer_singleton" in vars():
    observer_singleton.stop()

observer_singleton = TVObserver()
