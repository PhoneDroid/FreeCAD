// SPDX-FileCopyrightText: 2022 Zheng Lei <realthunder.dev@gmail.com>
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
#include <QCompleter>

class QLineEdit;

namespace Gui
{

/**
 * Command name auto completer.
 *
 * This class provides an auto completer for a QLineEdit widget. The auto
 * completer supports keyword search in command title, internal name, and
 * shortcut.
 */
class GuiExport CommandCompleter: public QCompleter
{
    Q_OBJECT
public:
    explicit CommandCompleter(QLineEdit* edit, QObject* parent = nullptr);

Q_SIGNALS:
    /// Triggered when a command is selected in the completer
    void commandActivated(const QByteArray& name);

protected Q_SLOTS:
    void onTextChanged(const QString&);
    void onCommandActivated(const QModelIndex&);

protected:
    bool eventFilter(QObject*, QEvent* ev) override;
};

}  // namespace Gui
