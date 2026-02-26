// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2013 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <vector>
#include <QWidget>

#include <Gui/Selection/SelectionObject.h>

#include "MeshSelection.h"


namespace MeshGui
{

class Ui_Selection;
class Selection: public QWidget
{
    Q_OBJECT

public:
    explicit Selection(QWidget* parent = nullptr);
    ~Selection() override;
    void setObjects(const std::vector<Gui::SelectionObject>&);
    std::vector<App::DocumentObject*> getObjects() const;
    bool eventFilter(QObject*, QEvent*) override;

private:
    void setupConnections();
    void onAddSelectionClicked();
    void onClearSelectionClicked();
    void onVisibleTrianglesToggled(bool);
    void onScreenTrianglesToggled(bool);

private:
    MeshSelection meshSel;
    Ui_Selection* ui;

    Q_DISABLE_COPY_MOVE(Selection)
};

}  // namespace MeshGui
