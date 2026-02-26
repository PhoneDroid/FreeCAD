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
#include "ViewProviderFemConstraintHeatflux.h"


class Ui_TaskFemConstraintHeatflux;

namespace FemGui
{
class TaskFemConstraintHeatflux: public TaskFemConstraintOnBoundary
{
    Q_OBJECT

public:
    explicit TaskFemConstraintHeatflux(
        ViewProviderFemConstraintHeatflux* ConstraintView,
        QWidget* parent = nullptr
    );
    ~TaskFemConstraintHeatflux() override;
    std::string getAmbientTemp() const;
    /*double getFaceTemp(void) const;*/
    std::string getFilmCoef() const;
    std::string getDFlux() const;
    double getEmissivity() const;
    std::string getConstraintType() const;
    const std::string getReferences() const override;

private Q_SLOTS:
    void onReferenceDeleted();
    void onAmbientTempChanged(double val);
    /*void onFaceTempChanged(double val);*/
    void onFilmCoefChanged(double val);
    void onEmissivityChanged(double val);
    void onHeatFluxChanged(double val);
    void onConstrTypeChanged(int val);
    void Conv();
    void Rad();
    void Flux();
    void addToSelection() override;
    void removeFromSelection() override;

protected:
    void changeEvent(QEvent* e) override;
    void clearButtons(const SelectionChangeModes notThis) override;

private:
    void updateUI();
    std::unique_ptr<Ui_TaskFemConstraintHeatflux> ui;
};

class TaskDlgFemConstraintHeatflux: public TaskDlgFemConstraint
{
    Q_OBJECT

public:
    explicit TaskDlgFemConstraintHeatflux(ViewProviderFemConstraintHeatflux* ConstraintView);
    bool accept() override;
};

}  // namespace FemGui
