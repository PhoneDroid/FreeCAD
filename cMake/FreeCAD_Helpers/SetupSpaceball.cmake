# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

macro(SetupSpaceball)
# ------------------------------ Spaceball -------------------------------

    if (WIN32)
        #future
    else(WIN32)
        find_package(Spnav)
    endif(WIN32)

endmacro(SetupSpaceball)
