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


#pragma once

#include <QMenu>

namespace Gui
{
namespace Dialog
{

/** This class implements the undo dialog.
 * \author Werner Mayer
 */
class UndoDialog: public QMenu
{
    Q_OBJECT

public:
    explicit UndoDialog(QWidget* parent = nullptr);
    ~UndoDialog() override;

protected Q_SLOTS:
    void onSelected();
    void onFetchInfo();
};

/** This class implements the redo dialog.
 * \author Werner Mayer
 */
class RedoDialog: public QMenu
{
    Q_OBJECT

public:
    explicit RedoDialog(QWidget* parent = nullptr);
    ~RedoDialog() override;

protected Q_SLOTS:
    void onSelected();
    void onFetchInfo();
};

}  // namespace Dialog
}  // namespace Gui
