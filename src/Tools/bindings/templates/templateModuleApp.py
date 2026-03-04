#! python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2007 Jürgen Riegel
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

from . import template, templateModuleAppMain, templateModuleAppFeature
import model.generateModel_Module
import model.generateTools


class TemplateModuleApp(template.ModelTemplate):
    def Generate(self):
        AppPath = self.outputDir + "/App/"
        model.generateTools.ensureDir(AppPath)

        # the main module files
        AppMain = templateModuleAppMain.TemplateModuleAppMain()
        AppMain.outputDir = AppPath
        AppMain.module = self.module
        AppMain.Generate()

        # Features
        model.generateTools.ensureDir(AppPath + "Features/")
        for i in self.module.Content.Feature:
            AppFeature = templateModuleAppFeature.TemplateFeature()
            AppFeature.outputDir = AppPath + "Features/"
            AppFeature.module = self.module
            AppFeature.feature = i
            AppFeature.Generate()
