# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Stefan Troeger <stefantroeger@gmx.net>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from typing import Final, Any
from Base.PyObjectBase import PyObjectBase


class Extension(PyObjectBase):
    """
    Base class for all extensions
    Licence: LGPL
    """

    ExtendedObject: Final[Any] = None
    """Get extended container object"""
