// SPDX-FileCopyrightText: 2009 Jürgen Riegel <juergen.riegel@web.de>
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

#include "DockWindow.h"


class QTabWidget;
class QTreeView;

namespace App
{
class PropertyContainer;
}

namespace Gui
{
class TreeWidget;
class PropertyView;
class TreePanel;
namespace PropertyEditor
{
class EditableListView;
class EditableItem;
class PropertyEditor;
}  // namespace PropertyEditor

namespace TaskView
{
class TaskView;
class TaskDialog;
}  // namespace TaskView
}  // namespace Gui


namespace Gui
{
class ControlSingleton;
namespace DockWnd
{

/** Combo View
 * is a combination of a tree and property view for
 * integrated user action.
 */
class GuiExport ComboView: public Gui::DockWindow
{
    Q_OBJECT

public:
    /**
     * A constructor.
     * A more elaborate description of the constructor.
     */
    ComboView(Gui::Document* pcDocument, QWidget* parent = nullptr);

    void setShowModel(bool);

    /**
     * A destructor.
     * A more elaborate description of the destructor.
     */
    ~ComboView() override;

    friend class Gui::ControlSingleton;

private:
    Gui::PropertyView* prop;
    Gui::TreePanel* tree;
};

}  // namespace DockWnd
}  // namespace Gui
