// SPDX-FileCopyrightText: 2018 Zheng Lei <realthunder.dev@gmail.com>
// SPDX-FileNotice: Part of the FreeCAD project.

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


#include <App/Application.h>
#include "ViewParams.h"

using namespace Gui;

ViewParams::ViewParams()
{
    handle = App::GetApplication().GetParameterGroupByPath("User parameter:BaseApp/Preferences/View");
    handle->Attach(this);
#undef FC_VIEW_PARAM
#define FC_VIEW_PARAM(_name, _ctype, _type, _def) _name = handle->Get##_type(#_name, _def);

    FC_VIEW_PARAMS
}

ViewParams::~ViewParams() = default;

void ViewParams::OnChange(Base::Subject<const char*>&, const char* sReason)
{
    if (!sReason) {
        return;
    }
#undef FC_VIEW_PARAM
#define FC_VIEW_PARAM(_name, _ctype, _type, _def) \
    if (strcmp(sReason, #_name) == 0) { \
        _name = handle->Get##_type(#_name, _def); \
        return; \
    }
    FC_VIEW_PARAMS
}

ViewParams* ViewParams::instance()
{
    static ViewParams* inst;
    if (!inst) {
        inst = new ViewParams;
    }
    return inst;
}
