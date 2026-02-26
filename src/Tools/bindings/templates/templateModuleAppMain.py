#! python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

# (c) 2006 Jürgen Riegel

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

from . import template
import model.generateModel_Module
import model.generateTools


class TemplateModuleAppMain(template.ModelTemplate):
    def Generate(self):
        file = open(self.outputDir + "/App" + self.module.Name + ".cpp", "w")
        model.generateTools.replace(self.Template, locals(), file)
        # file.write( model.generateTools.replace(self.Template,locals()))

    Template = """
/******************************************************************************
 *                                                                            *
 *   FreeCAD is free software: you can redistribute it and/or modify          *
 *   it under the terms of the GNU Lesser General Public License as           *
 *   published by the Free Software Foundation, either version 2.1            *
 *   of the License, or (at your option) any later version.                   *
 *                                                                            *
 *   FreeCAD is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty              *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 *   See the GNU Lesser General Public License for more details.              *
 *                                                                            *
 *   You should have received a copy of the GNU Lesser General Public         *
 *   License along with FreeCAD. If not, see https://www.gnu.org/licenses     *
 *                                                                            *
 ******************************************************************************/

# include <Python.h>


#include <Base/Console.h>

+ for i in self.module.Content.Feature:
#include "Feature/@i.Name@.h"
-

extern struct PyMethodDef @self.module.Name@_methods[];


extern "C" {
void App@self.module.Name@Export init@self.module.Name@() {

  Base::Console().log("Mod: Loading @self.module.Name@ module... done\\n");
  PyObject* partModule = Py_InitModule3("@self.module.Name@", @self.module.Name@_methods, module_@self.module.Name@_doc);   /* mod name, table ptr */

+ for i in self.module.Content.Feature:
  @self.module.Name@::Feature@i.Name@::init();
-

    return;
}

} // extern "C"
"""
