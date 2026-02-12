# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: Werner Mayer <wmayer@users.sourceforge.net>
# SPDX-FileNotice: Part of the FreeCAD project.

from __future__ import annotations

from Base.Metadata import no_args
from ViewProviderDocumentObject import ViewProviderDocumentObject

class ViewProviderGeometryObject(ViewProviderDocumentObject):
    """
    This is the ViewProvider geometry class

    Licence: LGPL
    """

    @staticmethod
    @no_args
    def getUserDefinedMaterial() -> object:
        """
        Get a material object with the user-defined colors.
        """
        ...
