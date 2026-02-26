// SPDX-FileCopyrightText: 2015 FreeCAD Developers
// SPDX-FileCopyrightText: Michael Hindley <hindlemp@eskom.co.za>
// SPDX-FileCopyrightText: Ruan Olwagen <olwager@eskom.co.za>
// SPDX-FileCopyrightText: Oswald van Ginkel <vginkeo@eskom.co.za>
// SPDX-FileNotice: Part of the FreeCAD project.

// Based on Force constraint by Jan Rheinländer

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
#include "ViewProviderFemConstraintPressure.h"


class Ui_TaskFemConstraintPressure;

namespace FemGui
{
class TaskFemConstraintPressure: public TaskFemConstraintOnBoundary
{
    Q_OBJECT

public:
    explicit TaskFemConstraintPressure(
        ViewProviderFemConstraintPressure* ConstraintView,
        QWidget* parent = nullptr
    );
    ~TaskFemConstraintPressure() override;
    const std::string getReferences() const override;
    std::string getPressure() const;
    bool getReverse() const;

private Q_SLOTS:
    void onReferenceDeleted();
    void onCheckReverse(bool);
    void addToSelection() override;
    void removeFromSelection() override;

protected:
    void changeEvent(QEvent* e) override;
    void clearButtons(const SelectionChangeModes notThis) override;

private:
    void updateUI();
    std::unique_ptr<Ui_TaskFemConstraintPressure> ui;
};

class TaskDlgFemConstraintPressure: public TaskDlgFemConstraint
{
    Q_OBJECT

public:
    explicit TaskDlgFemConstraintPressure(ViewProviderFemConstraintPressure* ConstraintView);
    bool accept() override;
};

}  // namespace FemGui
