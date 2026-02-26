// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2021 Wanderer Fan <wandererfan@gmail.com>

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

#include <Mod/TechDraw/TechDrawGlobal.h>

#include <QDialog>

namespace TechDrawGui {

class Ui_DlgPageChooser;

//NOLINTBEGIN
class TechDrawGuiExport DlgPageChooser : public QDialog
{
    Q_OBJECT
//NOLINTEND

public:
    DlgPageChooser(const std::vector<std::string>& labels,
                   const std::vector<std::string>& names,
                   QWidget* parent = nullptr, Qt::WindowFlags fl = Qt::WindowFlags());
    ~DlgPageChooser() override;

    std::string getSelection() const;
    void accept() override;
    void reject() override;

public Q_SLOTS:
    void slotChangedSelection();

private:
    void fillList(std::vector<std::string> labels, std::vector<std::string> names);

    Ui_DlgPageChooser* ui;
};

} // namespace Gui