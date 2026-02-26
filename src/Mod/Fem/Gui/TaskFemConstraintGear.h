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

#include "TaskFemConstraintBearing.h"
#include "ViewProviderFemConstraintGear.h"

namespace FemGui
{

class TaskFemConstraintGear: public TaskFemConstraintBearing
{
    Q_OBJECT

public:
    explicit TaskFemConstraintGear(
        ViewProviderFemConstraint* ConstraintView,
        QWidget* parent = nullptr,
        const char* pixmapname = "FEM_ConstraintGear"
    );

    double getDiameter() const;
    double getForce() const;
    double getForceAngle() const;
    const std::string getDirectionName() const;
    const std::string getDirectionObject() const;
    bool getReverse() const;

private Q_SLOTS:
    void onDiameterChanged(double dia);
    void onForceChanged(double force);
    void onForceAngleChanged(double angle);
    void onButtonDirection(const bool pressed = true);
    void onCheckReversed(bool);

protected:
    void changeEvent(QEvent* e) override;
    void onSelectionChanged(const Gui::SelectionChanges& msg) override;
};

/// simulation dialog for the TaskView
class TaskDlgFemConstraintGear: public TaskDlgFemConstraintBearing
{
    Q_OBJECT

public:
    TaskDlgFemConstraintGear() = default;
    explicit TaskDlgFemConstraintGear(ViewProviderFemConstraintGear* ConstraintView);

    /// is called by the framework if the dialog is accepted (Ok)
    bool accept() override;
};

}  // namespace FemGui
