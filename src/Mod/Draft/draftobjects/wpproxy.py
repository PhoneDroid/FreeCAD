# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2009,2010 Yorik van Havre <yorik@uncreated.net>
# SPDX-FileCopyrightText: 2009,2010 Ken Cline <cline@frii.com>
# SPDX-FileCopyrightText: 2020 FreeCAD Developers
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
"""Provides the object code for the WorkingPlaneProxy object."""
## @package wpproxy
# \ingroup draftobjects
# \brief Provides the object code for the WorkingPlaneProxy object.

## \addtogroup draftobjects
# @{
from PySide.QtCore import QT_TRANSLATE_NOOP

import FreeCAD as App
from draftutils import gui_utils


class WorkingPlaneProxy:
    """The Draft working plane proxy object"""

    def __init__(self, obj):
        obj.Proxy = self

        _tip = QT_TRANSLATE_NOOP("App::Property", "The placement of this object")
        obj.addProperty("App::PropertyPlacement", "Placement", "Base", _tip, locked=True)

        obj.addProperty("Part::PropertyPartShape", "Shape", "Base", "", locked=True)

        obj.addExtension("Part::AttachExtensionPython")
        obj.changeAttacherType("Attacher::AttachEnginePlane")

        self.Type = "WorkingPlaneProxy"

    def onDocumentRestored(self, obj):
        gui_utils.restore_view_object(
            obj, vp_module="view_wpproxy", vp_class="ViewProviderWorkingPlaneProxy", format=False
        )

    def execute(self, obj):
        import Part

        l = 1
        if obj.ViewObject:
            if hasattr(obj.ViewObject, "DisplaySize"):
                l = obj.ViewObject.DisplaySize.Value
        p = Part.makePlane(l, l, App.Vector(l / 2, -l / 2, 0), App.Vector(0, 0, -1))
        # make sure the normal direction is pointing outwards, you never know what OCC will decide...
        if p.normalAt(0, 0).getAngle(obj.Placement.Rotation.multVec(App.Vector(0, 0, 1))) > 1:
            p.reverse()
        p.Placement = obj.Placement
        obj.Shape = p

    def onChanged(self, obj, prop):
        pass

    def getNormal(self, obj):
        return obj.Shape.Faces[0].normalAt(0, 0)

    def dumps(self):
        return self.Type

    def loads(self, state):
        if state:
            self.Type = state


## @}
