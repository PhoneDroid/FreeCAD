// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2016 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <FCGlobal.h>

#include <QDialog>

namespace MeshGui
{

class Ui_DlgEvaluateSettings;

/**
 * \author Werner Mayer
 */
class DlgEvaluateSettings: public QDialog
{
    Q_OBJECT

public:
    explicit DlgEvaluateSettings(QWidget* parent = nullptr, Qt::WindowFlags fl = Qt::WindowFlags());
    ~DlgEvaluateSettings() override;

    void setNonmanifoldPointsChecked(bool);
    bool isNonmanifoldPointsChecked() const;

    void setFoldsChecked(bool);
    bool isFoldsChecked() const;

    void setDegeneratedFacetsChecked(bool);
    bool isDegeneratedFacetsChecked() const;

private:
    Ui_DlgEvaluateSettings* ui;

    Q_DISABLE_COPY_MOVE(DlgEvaluateSettings)
};

}  // namespace MeshGui
