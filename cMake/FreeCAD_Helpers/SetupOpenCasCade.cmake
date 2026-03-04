# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

macro(SetupOpenCasCade)
    find_package(OCC)
    if(NOT OCC_FOUND)
        message(FATAL_ERROR "================================================================\n"
                            "OpenCASCADE not found!\n"
                            "================================================================\n")
    endif()
endmacro()
