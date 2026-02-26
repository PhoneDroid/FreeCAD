# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2001,2002 Jürgen Riegel <juergen.riegel@web.de>
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

# FreeCAD init script of the part module

# FreeCAD.addImportType("CAD formats (*.igs *.iges *.step *.stp *.brep *.brp)","Part")
# FreeCAD.addExportType("CAD formats (*.igs *.iges *.step *.stp *.brep *.brp)","Part")
FreeCAD.addImportType("BREP format (*.brep *.BREP *.brp *.BRP)", "Part")
FreeCAD.addExportType("BREP format (*.brep *.brp)", "Part")
FreeCAD.addImportType("IGES format (*.iges *.IGES *.igs *.IGS)", "Part")
FreeCAD.addExportType("IGES format (*.iges *.igs)", "Part")
FreeCAD.addImportType("STEP with colors (*.step *.STEP *.stp *.STP)", "Import")
FreeCAD.addExportType("STEP with colors (*.step *.stp)", "Import")

FreeCAD.__unit_test__ += ["TestPartApp"]
