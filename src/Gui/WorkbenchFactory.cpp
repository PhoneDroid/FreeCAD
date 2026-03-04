// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2004 Werner Mayer <wmayer@users.sourceforge.net>
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


#include "WorkbenchFactory.h"
#include "Workbench.h"

using namespace Gui;

Gui::WorkbenchFactoryInst* Gui::WorkbenchFactoryInst::_pcSingleton = nullptr;

WorkbenchFactoryInst& WorkbenchFactoryInst::instance()
{
    if (!_pcSingleton) {
        _pcSingleton = new WorkbenchFactoryInst;
    }
    return *_pcSingleton;
}

void WorkbenchFactoryInst::destruct()
{
    delete _pcSingleton;
    _pcSingleton = nullptr;
}

Workbench* WorkbenchFactoryInst::createWorkbench(const char* sName) const
{
    auto obj = (Workbench*)Produce(sName);
    auto wb = freecad_cast<Workbench*>(obj);
    if (!wb) {
        delete obj;  // delete the unknown object as no workbench object
        return nullptr;
    }

    wb->setName(sName);
    return wb;
}

std::list<std::string> WorkbenchFactoryInst::workbenches() const
{
    std::list<std::string> wb;
    for (const auto& it : _mpcProducers) {
        wb.push_back(it.first);
    }
    return wb;
}
