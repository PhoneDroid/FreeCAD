# SPDX-License-Identifier: LGPL-2.1-or-later
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

import sys
from os import path

# Actual code generation is done in Base/param_utils.py.

# The following code is to import param_util.py without needing __init__.py in Base directory
sys.path.append(path.join(path.dirname(path.dirname(path.abspath(__file__))), "Base"))
import params_utils

from params_utils import ParamBool, ParamInt, ParamString, ParamUInt, ParamFloat

NameSpace = "App"
ClassName = "LinkParams"
ParamPath = "User parameter:BaseApp/Preferences/Link"
ClassDoc = "Convenient class to obtain App::Link related parameters"
HeaderFile = "Link.h"
SourceFile = "Link.cpp"

Params = [
    ParamBool(
        "CopyOnChangeApplyToAll",
        True,
        """\
Stores the last user choice of whether to apply CopyOnChange setup to all link
that links to the same configurable object""",
    ),
]


def declare():
    params_utils.declare_begin(sys.modules[__name__], header=False)
    params_utils.declare_end(sys.modules[__name__])


def define():
    params_utils.define(sys.modules[__name__], header=False)
