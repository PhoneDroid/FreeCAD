// SPDX-FileCopyrightText: 2013 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#include <Gui/TaskView/TaskView.h>


class Ui_TaskObjectName;

namespace App
{
class Property;
class DocumentObject;
}  // namespace App

namespace Gui
{
class ViewProvider;
}

namespace FemGui
{


class TaskObjectName: public Gui::TaskView::TaskBox
{
    Q_OBJECT

public:
    explicit TaskObjectName(App::DocumentObject* pcObject, QWidget* parent = nullptr);
    ~TaskObjectName() override;


    std::string name;

private Q_SLOTS:
    void TextChanged(const QString&);

protected:
    App::DocumentObject* pcObject;

private:
private:
    QWidget* proxy;
    std::unique_ptr<Ui_TaskObjectName> ui;
};

}  // namespace FemGui
