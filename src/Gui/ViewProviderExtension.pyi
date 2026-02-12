# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Werner Mayer <wmayer@users.sourceforge.net>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import constmethod
from App.Extension import Extension

class ViewProviderExtension(Extension):
    """
    Base class for all view provider extensions

    Licence: LGPL
    """

    def setIgnoreOverlayIcon(self) -> None:
        """
        Ignore the overlay icon of an extension
        """
        ...

    @constmethod
    def ignoreOverlayIcon(self) -> None:
        """
        Ignore the overlay icon of an extension
        """
        ...
