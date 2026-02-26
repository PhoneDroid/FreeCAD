// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#include <Gui/Inventor/Draggers/Gizmo.h>

#include "TaskDressUpParameters.h"
#include "ViewProviderFillet.h"

class Ui_TaskFilletParameters;

namespace Gui
{
class LinearGizmo;
class GizmoContainer;
}  // namespace Gui

namespace PartDesignGui
{

class TaskFilletParameters: public TaskDressUpParameters
{
    Q_OBJECT

public:
    explicit TaskFilletParameters(ViewProviderDressUp* DressUpView, QWidget* parent = nullptr);
    ~TaskFilletParameters() override;

    void apply() override;

private Q_SLOTS:
    void onLengthChanged(double);
    void onRefDeleted() override;
    void onAddAllEdges();
    void onCheckBoxUseAllEdgesToggled(bool checked);

protected:
    double getLength() const;
    void setButtons(const selectionModes mode) override;
    void changeEvent(QEvent* e) override;
    void onSelectionChanged(const Gui::SelectionChanges& msg) override;

private:
    std::unique_ptr<Ui_TaskFilletParameters> ui;

    std::unique_ptr<Gui::GizmoContainer> gizmoContainer;
    Gui::LinearGizmo* radiusGizmo = nullptr;
    Gui::LinearGizmo* radiusGizmo2 = nullptr;
    void setupGizmos(ViewProviderDressUp* vp);
    void setGizmoPositions();
};

/// simulation dialog for the TaskView
class TaskDlgFilletParameters: public TaskDlgDressUpParameters
{
    Q_OBJECT

public:
    explicit TaskDlgFilletParameters(ViewProviderFillet* DressUpView);
    ~TaskDlgFilletParameters() override;

public:
    /// is called by the framework if the dialog is accepted (Ok)
    bool accept() override;
};

}  // namespace PartDesignGui
