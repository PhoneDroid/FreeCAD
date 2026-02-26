// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2006 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QDialog>
#include <memory>

namespace MeshGui
{
class Ui_DlgRegularSolid;
class DlgRegularSolidImp: public QDialog
{
    Q_OBJECT

public:
    explicit DlgRegularSolidImp(QWidget* parent = nullptr, Qt::WindowFlags fl = Qt::WindowFlags());
    ~DlgRegularSolidImp() override;

private:
    void onCreateSolidButtonClicked();

protected:
    void changeEvent(QEvent* e) override;

private:
    std::unique_ptr<Ui_DlgRegularSolid> ui;

    Q_DISABLE_COPY_MOVE(DlgRegularSolidImp)
};

}  // namespace MeshGui
