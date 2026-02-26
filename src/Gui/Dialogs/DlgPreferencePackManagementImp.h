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
#include <filesystem>
#include <FCGlobal.h>


class QTreeWidgetItem;

namespace Gui
{

namespace Dialog
{

class Ui_DlgPreferencePackManagement;

/**
 * \class DlgCreateNewPreferencePackImp
 *
 * A dialog to request a preferencePack name and a set of preferencePack templates.
 *
 * \author Chris Hennes
 */
class GuiExport DlgPreferencePackManagementImp: public QDialog
{
    Q_OBJECT

public:
    DlgPreferencePackManagementImp(QWidget* parent = nullptr);
    ~DlgPreferencePackManagementImp() override;

Q_SIGNALS:
    void packVisibilityChanged();

protected Q_SLOTS:

    void deleteUserPack(const std::string& prefPackName);
    void hideBuiltInPack(const std::string& prefPackName);
    void hideInstalledPack(const std::string& addonName, const std::string& prefPackName);
    void showAddonManager();

private:
    enum class TreeWidgetType
    {
        BUILTIN,
        USER,
        ADDON
    };

    std::unique_ptr<Ui_DlgPreferencePackManagement> ui;

    void addTreeNode(
        const std::string& name,
        const std::vector<std::string>& contents,
        TreeWidgetType twt
    );
    void updateTree();
};

}  // namespace Dialog
}  // namespace Gui
