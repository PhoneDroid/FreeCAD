#! python
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileCopyrightText: 2006 Jürgen Riegel
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

from . import template
import model.generateModel_Module
import model.generateTools


class TemplateFeature(template.ModelTemplate):
    def Generate(self):
        file = open(self.outputDir + self.feature.Name + "Imp.cpp", "w")
        model.generateTools.replace(self.TemplateImplement, locals(), file)
        file = open(self.outputDir + self.feature.Name + ".cpp", "w")
        model.generateTools.replace(self.TemplateModule, locals(), file)
        file = open(self.outputDir + self.feature.Name + ".h", "w")
        model.generateTools.replace(self.TemplateHeader, locals(), file)
        # file.write( model.generateTools.replace(self.Template,locals()))

    TemplateHeader = """
#ifndef @self.module.Name.upper()@_FEATURE_@self.feature.Name.upper()@_H
#define @self.module.Name.upper()@_FEATURE_@self.feature.Name.upper()@_H

#include <App/PropertyStandard.h>

#include <App/Feature.h>

namespace @self.module.Name@
{


class @self.feature.Name@ : public App::Feature
{
  PROPERTY_HEADER(@self.module.Name@::@self.feature.Name@);

public:
  @self.feature.Name@();
+ for i in self.feature.Property:
  @i.Type@ @i.Name@;
-

  /** @name Methods override feature */
  //@{
  /// Recalculate the feature
  virtual int execute(void);
  /// Return the type name of the ViewProvider
  virtual const char* getViewProviderName(void) const {
    return "@self.module.Name@Gui::ViewProviderBox";
  }
  //@}
};

} //namespace @self.module.Name@

#endif // @self.module.Name.upper()@_FEATURE_@self.feature.Name.upper()@_H

"""
    TemplateModule = """

#include "@self.feature.Name@.h"

using namespace @self.module.Name@;

PROPERTY_SOURCE(@self.module.Name@::@self.feature.Name@, App::Feature)

@self.feature.Name@::@self.feature.Name@()
{
+ for i in self.feature.Property:
  ADD_PROPERTY(@i.Name@,(0.0));
-
}
"""
    # Here's the template for the user part of the implementation. This does NOT get overwritten if it already exists.
    TemplateImplement = """
//

#include "@self.feature.Name@.h"

using namespace @self.module.Name@;

// TODO This method implements the function of the feature
int @self.feature.Name@::execute(void)
{
   return 0;
}

"""
