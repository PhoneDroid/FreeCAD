// SPDX-FileCopyrightText: 2010 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QTreeView>
#include <FCGlobal.h>

namespace Gui
{

class GuiExport TreeView: public QTreeView
{
    Q_OBJECT

public:
    TreeView(QWidget* parent = nullptr);
    ~TreeView() override;

protected:
    void mouseDoubleClickEvent(QMouseEvent*) override;
    void rowsInserted(const QModelIndex& parent, int start, int end) override;
};

}  // namespace Gui
