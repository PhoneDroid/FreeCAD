# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

macro(SetupXercesC)
# -------------------------------- XercesC --------------------------------

    find_package(XercesC REQUIRED)
    if(NOT XercesC_FOUND)
        message(FATAL_ERROR "==================\n"
                            "XercesC not found.\n"
                            "==================\n")
    endif(NOT XercesC_FOUND)

endmacro(SetupXercesC)
