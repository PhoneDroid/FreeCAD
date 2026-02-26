// SPDX-FileCopyrightText: 2013 Jan Rheinländer <jrheinlaender@users.sourceforge.net>
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

#include <QObject>
#include <memory>

#include "TaskFemConstraintOnBoundary.h"
#include "ViewProviderFemConstraintForce.h"


class Ui_TaskFemConstraintForce;

namespace App
{
class Property;
}

namespace Gui
{
class SelectionObject;
class ViewProvider;
}  // namespace Gui

namespace FemGui
{

class TaskFemConstraintForce: public TaskFemConstraintOnBoundary
{
    Q_OBJECT

public:
    explicit TaskFemConstraintForce(
        ViewProviderFemConstraintForce* ConstraintView,
        QWidget* parent = nullptr
    );
    ~TaskFemConstraintForce() override;
    const std::string getForce() const;
    const std::string getReferences() const override;
    const std::string getDirectionName() const;
    const std::string getDirectionObject() const;
    bool getReverse() const;

private Q_SLOTS:
    void onReferenceDeleted();
    void onButtonDirection(const bool pressed = false);
    void onCheckReverse(bool);
    void addToSelection() override;
    void removeFromSelection() override;

protected:
    void changeEvent(QEvent* e) override;
    void clearButtons(const SelectionChangeModes notThis) override;

private:
    std::pair<App::DocumentObject*, std::string> getDirection(
        const std::vector<Gui::SelectionObject>&
    ) const;
    void updateUI();

private:
    std::unique_ptr<Ui_TaskFemConstraintForce> ui;
};

/// simulation dialog for the TaskView
class TaskDlgFemConstraintForce: public TaskDlgFemConstraint
{
    Q_OBJECT

public:
    explicit TaskDlgFemConstraintForce(ViewProviderFemConstraintForce* ConstraintView);

    /// is called by the framework if the dialog is accepted (Ok)
    bool accept() override;
};

}  // namespace FemGui
