// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2005 Werner Mayer <wmayer@users.sourceforge.net>
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


#pragma once

#include <list>
#include <map>
#include <string>
#include <FCGlobal.h>

namespace Gui
{

class Workbench;

/**
 * The WorkbenchManager class manages all workbench objects.
 * @author Werner Mayer
 */
class GuiExport WorkbenchManager
{
public:
    /** Creates the only instance of the WorkbenchManager. */
    static WorkbenchManager* instance();
    static void destruct();

    /** Searches for and returns an existing workbench object with name \a name. If no
     * such workbench exists then a workbench of class \a className gets created, if possible.
     * If the workbench cannot be created 0 is returned.
     */
    Workbench* createWorkbench(const std::string& name, const std::string& className);
    /** Removes the workbench with name \a name. If there is no such
     * workbench exists nothing happens.
     */
    void removeWorkbench(const std::string& name);
    /** Returns an instance of the workbench with name \a name. If there is
     * no such workbench 0 is returned.
     */
    Workbench* getWorkbench(const std::string& name) const;
    /** Activates the workbench with name \a name. */
    bool activate(const std::string& name, const std::string& className);
    /** Returns the active workbench. */
    Workbench* active() const;
    /** Returns the name of the active workbench. */
    std::string activeName() const;
    /** Returns a list of all created workbench objects. */
    std::list<std::string> workbenches() const;

protected:
    WorkbenchManager();
    ~WorkbenchManager();

private:
    static WorkbenchManager* _instance;
    Workbench* _activeWorkbench {nullptr};
    std::map<std::string, Workbench*> _workbenches;
};

}  // namespace Gui
