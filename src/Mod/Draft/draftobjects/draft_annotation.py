# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2020 Carlo Pavan <carlopav@gmail.com>
# SPDX-FileCopyrightText: 2020 Eliud Cabrera Castillo <e.cabrera-castillo@tum.de>
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
"""Provides the object code for all annotation type objects.

This is used by many objects that show dimensions and text created on screen
through Coin (pivy).
- DimensionBase
- LinearDimension
- AngularDimension
- Label
- Text
"""
## @package draft_annotation
# \ingroup draftobjects
# \brief Provides the object code for all annotation type objects.

## \addtogroup draftobjects
# @{
from draftutils.messages import _log


class DraftAnnotation(object):
    """The Draft Annotation Base object.

    This class is not used directly, but inherited by all Draft annotation
    objects.

    LinearDimension through DimensionBase
    AngularDimension through DimensionBase
    Label
    Text
    """

    def onDocumentRestored(self, obj):
        """Execute code when the document is restored.

        Check if new properties are present after the object is restored
        in order to migrate older objects.
        """
        vobj = getattr(obj, "ViewObject", None)
        if vobj is None:
            return
        if not getattr(vobj, "Proxy", None):
            # Object was saved without GUI.
            # onDocumentRestored in the object class should restore the ViewObject.
            return

        if not hasattr(vobj, "ScaleMultiplier") or not hasattr(vobj, "AnnotationStyle"):
            self.add_missing_properties_0v19(obj, vobj)

        if hasattr(vobj, "ArrowType") or hasattr(vobj, "ArrowSize"):
            self.update_properties_1v1(obj, vobj)

    def add_missing_properties_0v19(self, obj, vobj):
        """Provide missing annotation properties."""
        multiplier = None
        if not hasattr(vobj, "ScaleMultiplier"):
            multiplier = 1.00
            _log("v0.19, " + obj.Name + ", added view property 'ScaleMultiplier'")
        if not hasattr(vobj, "AnnotationStyle"):
            _log("v0.19, " + obj.Name + ", added view property 'AnnotationStyle'")
        vobj.Proxy.set_annotation_properties(vobj, vobj.PropertiesList)
        if multiplier is not None:
            vobj.ScaleMultiplier = multiplier

    def update_properties_1v1(self, obj, vobj):
        """Update view properties."""
        vobj.Proxy.set_graphics_properties(vobj, vobj.PropertiesList)

        if hasattr(vobj, "ArrowType"):
            typ = obj.Proxy.Type
            if typ == "Label":
                vobj.ArrowTypeStart = vobj.ArrowType
            elif typ == "AngularDimension" or obj.Diameter or not vobj.Proxy.is_linked_to_circle():
                vobj.ArrowTypeStart = vobj.ArrowType
                vobj.ArrowTypeEnd = vobj.ArrowType
            else:  # Radial dimension
                vobj.ArrowTypeStart = "None"
                vobj.ArrowTypeEnd = vobj.ArrowType
            vobj.setPropertyStatus("ArrowType", "-LockDynamic")
            vobj.removeProperty("ArrowType")
        if hasattr(vobj, "ArrowSize"):
            vobj.ArrowSizeStart = vobj.ArrowSize
            if hasattr(vobj, "ArrowSizeEnd"):
                # Label objects do not have this property
                vobj.ArrowSizeEnd = vobj.ArrowSize
            vobj.setPropertyStatus("ArrowSize", "-LockDynamic")
            vobj.removeProperty("ArrowSize")
        _log("v1.1, " + obj.Name + ", migrated view properties")

    def dumps(self):

        return

    def loads(self, state):

        return


## @}
