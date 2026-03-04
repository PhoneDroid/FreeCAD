# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

macro(BuildAndInstallDesignerPlugin)
    # =================================================================
    # ============= Build and install the designer plugin =============
    # =================================================================

    if(BUILD_DESIGNER_PLUGIN)
        add_subdirectory(src/Tools/plugins/widget)
    endif(BUILD_DESIGNER_PLUGIN)
endmacro(BuildAndInstallDesignerPlugin)
