// SPDX-FileCopyrightText: 2025 Stefan Tröger <stefantroeger@gmx.net>
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

#include <Gui/DocumentObserver.h>
#include <Gui/TaskView/TaskDialog.h>
#include <Gui/TaskView/TaskView.h>
#include <Gui/ViewProviderDocumentObject.h>

#include <QAbstractTableModel>

#include "TaskPostBoxes.h"

#include <vtkSmartPointer.h>
#include <vtkTableAlgorithm.h>

class Ui_TaskPostExtraction;


namespace FemGui
{

// ***************************************************************************
// box to handle data extractions: It is implemented in python, the c++
// code is used to access it and manage it for the c++ task panels
class TaskPostExtraction: public TaskPostWidget
{
    Q_OBJECT

public:
    explicit TaskPostExtraction(ViewProviderFemPostObject* view, QWidget* parent = nullptr);
    ~TaskPostExtraction();

protected:
    bool isGuiTaskOnly() override;
    void apply() override;
    void onPostDataChanged(Fem::FemPostObject* obj) override;
    bool initiallyCollapsed() override;

private:
    Py::Object m_panel;
};


}  // namespace FemGui
