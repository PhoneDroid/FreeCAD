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

#include <FCGlobal.h>

namespace Gui
{

class ToolBarItem;


namespace DockWnd
{
class ToolBox;
}

/**
 * The ToolBoxManager class is responsible for the creation of command bars and appending them
 * to the toolbox window.
 * @see ToolBarManager
 * @see MenuManager
 * @author Werner Mayer
 */
class GuiExport ToolBoxManager
{
public:
    /// The one and only instance.
    static ToolBoxManager* getInstance();
    static void destruct();
    /** Sets up the command bars of a given workbench. */
    void setup(ToolBarItem*) const;
    void setToolBox(DockWnd::ToolBox*);
    void retranslate() const;

protected:
    ToolBoxManager();
    ~ToolBoxManager();

private:
    DockWnd::ToolBox* _toolBox {nullptr};
    static ToolBoxManager* _instance;
};

}  // namespace Gui
