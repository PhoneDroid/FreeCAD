// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2009 Jürgen Riegel <juergen.riegel@web.de>
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

#include "TaskView.h"


class Ui_TaskEditControl;
class QHBoxLayout;
class QDialogButtonBox;

namespace App
{
class Property;
}

namespace Gui
{
class ViewProvider;
namespace TaskView
{


class TaskEditControl: public TaskWidget
{
    Q_OBJECT

public:
    explicit TaskEditControl(QWidget* parent = nullptr);
    ~TaskEditControl() override;
    QDialogButtonBox* standardButtons() const;
    friend class TaskView;

protected:
    QHBoxLayout* hboxLayout;
    QDialogButtonBox* buttonBox;
};

}  // namespace TaskView
}  // namespace Gui
