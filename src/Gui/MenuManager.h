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

#include <string>
#include <QList>
#include <QString>
#include <FCGlobal.h>


class QAction;
class QMenu;

namespace Gui
{

class MainWindow;

class GuiExport MenuItem
{
public:
    MenuItem();
    explicit MenuItem(MenuItem*);
    ~MenuItem();

    void setCommand(const std::string&);
    std::string command() const;

    bool hasItems() const;
    MenuItem* findItem(const std::string&);
    MenuItem* findParentOf(const std::string&);
    MenuItem* copy() const;
    uint count() const;

    void appendItem(MenuItem*);
    bool insertItem(MenuItem*, MenuItem*);
    MenuItem* afterItem(MenuItem*) const;
    void removeItem(MenuItem*);
    void clear();

    MenuItem& operator<<(MenuItem* item);
    MenuItem& operator<<(const std::string& command);
    QList<MenuItem*> getItems() const;

private:
    std::string _name;
    QList<MenuItem*> _items;
};

/**
 * The MenuManager class is responsible for the creation of menus and context menus and appending
 * them to the main window.
 * @see ToolBoxManager
 * @see ToolBarManager
 * @author Werner Mayer
 */
class GuiExport MenuManager
{
public:
    /** Sets up the menus of a given workbench. */
    void setup(MenuItem*) const;
    /// sets up a context menu out of item
    void setupContextMenu(MenuItem* item, QMenu& menu) const;
    void retranslate() const;

    /// The one and only instance.
    static MenuManager* getInstance();
    static void destruct();

protected:
    MenuManager();
    ~MenuManager();

private:
    void setup(MenuItem*, QMenu*) const;
    void retranslate(QMenu*) const;
    QAction* findAction(const QList<QAction*>&, const QString&) const;
    QList<QAction*> findActions(const QList<QAction*>&, const QString&) const;

private:
    static MenuManager* _instance;

    friend class MainWindow;
};

}  // namespace Gui
