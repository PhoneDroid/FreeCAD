# SPDX-License-Identifier: LGPL-2.1-or-later
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

from __future__ import annotations

"""
This file keeps auxiliary metadata to be used by the Python API stubs.
"""

def export(**kwargs):
    """
    A decorator to attach metadata to a class.
    """
    ...

def constmethod(method): ...
def no_args(method): ...
def forward_declarations(source_code):
    """
    A decorator to attach forward declarations to a class.
    """
    ...

def class_declarations(source_code):
    """
    A decorator to attach forward declarations to a class.
    """
    ...

def sequence_protocol(**kwargs):
    """
    A decorator to attach sequence protocol metadata to a class.
    """
    ...
