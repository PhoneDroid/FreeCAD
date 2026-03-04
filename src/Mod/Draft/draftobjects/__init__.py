# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2020 Carlo Pavan <carlopav@gmail.com
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

"""Modules that contain classes that define custom scripted objects.

These proxy classes are used to extend one of the core classes
defined in C++, for example, `Part::FeaturePython`
or `Part::Part2DObjectPython`, thus creating a custom object type
tied to a Python class.
A new object that uses one of these classes inherits some basic properties
from the parent C++ class, and new properties and behavior
are added by the Python class.

These classes are not normally used by themselves, but are used at creation
time by the make functions defined in the `draftmake` package.

Once an object is assigned one of these proxy classes, and it is saved
in a document, the object will be rebuilt with the same class every time
the document is opened. In order to do this, the object module must exist
with the same name as when the object was saved.

For example, when creating a `Rectangle`, the object uses
the `draftobjects.rectangle.Rectangle` class. This class must exist
when the document is opened again.

This means that, in general, these modules cannot be renamed or moved
without risking breaking previously saved files. They can be renamed
only if the old class can be migrated to point to a new class,
for example, by creating a reference to the new class named the same
as the older class.

::

    old_module.Rectangle = new_module.Rectangle
"""
## \defgroup draftobjects draftobjects
# \ingroup DRAFT
# \brief Modules that contain classes that define custom scripted objects.
