// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2009 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Mod/Mesh/MeshGlobal.h>
#include <memory>

#include <Gui/PropertyPage.h>


namespace MeshGui
{
class Ui_DlgSettingsMeshView;
/**
 * The DlgSettingsMeshView class implements a preference page to change settings
 * for display of meshes.
 * @author Werner Mayer
 */
class DlgSettingsMeshView: public Gui::Dialog::PreferencePage
{
    Q_OBJECT

public:
    explicit DlgSettingsMeshView(QWidget* parent = nullptr);
    ~DlgSettingsMeshView() override;

protected:
    void saveSettings() override;
    void loadSettings() override;
    void changeEvent(QEvent* e) override;

private:
    std::unique_ptr<Ui_DlgSettingsMeshView> ui;

    Q_DISABLE_COPY_MOVE(DlgSettingsMeshView)
};

}  // namespace MeshGui
