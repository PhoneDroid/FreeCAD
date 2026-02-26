// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2022 Chris Hennes <chennes@pioneerlibrarysystem.org>
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

#include <memory>
#include <QDialog>

namespace Gui
{
namespace Dialog
{
class Ui_DlgRevertToBackupConfig;

/** The DlgRevertToBackupConfigImp class
 * \author Chris Hennes
 */
class DlgRevertToBackupConfigImp: public QDialog
{
    Q_OBJECT

public:
    explicit DlgRevertToBackupConfigImp(QWidget* parent = nullptr);
    ~DlgRevertToBackupConfigImp() override;

public Q_SLOTS:
    void accept() override;
    void onItemSelectionChanged();

protected:
    void changeEvent(QEvent* e) override;
    void showEvent(QShowEvent* event) override;

private:
    std::unique_ptr<Ui_DlgRevertToBackupConfig> ui;
};

}  // namespace Dialog
}  // namespace Gui
