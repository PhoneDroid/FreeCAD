# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

macro(SetupLark)
    # ------------------------------ Lark ------------------------------

    find_package(LARK MODULE REQUIRED)
    message(STATUS "Found Lark: version ${LARK_VERSION}")

endmacro()
