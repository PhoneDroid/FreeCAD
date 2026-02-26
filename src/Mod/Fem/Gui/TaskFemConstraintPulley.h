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

#include "TaskFemConstraintGear.h"
#include "ViewProviderFemConstraintPulley.h"

namespace FemGui
{

class TaskFemConstraintPulley: public TaskFemConstraintGear
{
    Q_OBJECT

public:
    explicit TaskFemConstraintPulley(
        ViewProviderFemConstraintPulley* ConstraintView,
        QWidget* parent = nullptr
    );

    double getOtherDiameter() const;
    double getCenterDistance() const;
    double getTensionForce() const;
    double getTorque() const;
    bool getIsDriven() const;

private Q_SLOTS:
    void onOtherDiameterChanged(double dia);
    void onCenterDistanceChanged(double dia);
    void onTensionForceChanged(double force);
    void onCheckIsDriven(bool);

protected:
    void changeEvent(QEvent* e) override;
};

/// simulation dialog for the TaskView
class TaskDlgFemConstraintPulley: public TaskDlgFemConstraintGear
{
    Q_OBJECT

public:
    explicit TaskDlgFemConstraintPulley(ViewProviderFemConstraintPulley* ConstraintView);

    /// is called by the framework if the dialog is accepted (Ok)
    bool accept() override;
};

}  // namespace FemGui
