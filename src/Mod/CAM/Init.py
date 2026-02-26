# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2014 Yorik van Havre <yorik@uncreated.net>
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

# This code handles parameter groups following the CAM workbench renaming
# (PATH -> CAM).  This code can be removed after the 1.0 release.


ParGrp = App.ParamGet("System parameter:Modules").GetGroup("Path")
if ParGrp.HasGroup("CAM"):
    pass
elif ParGrp.HasGroup("Path"):
    ParGrp.RenameGroup("Path", "CAM")

ParGrp = App.ParamGet("User parameter:BaseApp/Preferences/Mod/Path")
parent = ParGrp.Parent()
if parent.HasGroup("CAM"):
    pass
elif parent.HasGroup("Path"):
    result = parent.RenameGroup("Path", "CAM")

# Get the Parameter Group of this module
ParGrp = App.ParamGet("System parameter:Modules").GetGroup("Path")

# Set the needed information
ParGrp.SetString("HelpIndex", "Path/Help/index.html")
ParGrp.SetString("WorkBenchName", "CAM")
ParGrp.SetString("WorkBenchModule", "PathWorkbench.py")

FreeCAD.__unit_test__ += ["TestCAMApp"]
