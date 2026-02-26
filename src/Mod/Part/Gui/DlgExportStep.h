// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2022 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Mod/Part/PartGlobal.h>
#include <Gui/PropertyPage.h>
#include <QDialog>

class QButtonGroup;
class QCheckBox;

namespace PartGui
{

struct StepSettings
{
    bool exportLegacy = false;
    bool exportHidden = false;
    bool keepPlacement = false;
};

// ----------------------------------------------------------------------------

class Ui_DlgExportStep;
class DlgExportStep: public Gui::Dialog::PreferencePage
{
    Q_OBJECT

public:
    explicit DlgExportStep(QWidget* parent = nullptr);
    ~DlgExportStep() override;

    void saveSettings() override;
    void loadSettings() override;

    StepSettings getSettings() const;

protected:
    void changeEvent(QEvent* e) override;

private:
    std::unique_ptr<Ui_DlgExportStep> ui;
};

// ----------------------------------------------------------------------------

class Ui_DlgExportHeaderStep;
class DlgExportHeaderStep: public Gui::Dialog::PreferencePage
{
    Q_OBJECT

public:
    explicit DlgExportHeaderStep(QWidget* parent = nullptr);
    ~DlgExportHeaderStep() override;

    void saveSettings() override;
    void loadSettings() override;

protected:
    void changeEvent(QEvent* e) override;

private:
    std::unique_ptr<Ui_DlgExportHeaderStep> ui;
};

// ----------------------------------------------------------------------------

class PartGuiExport TaskExportStep: public QDialog
{
    Q_OBJECT

public:
    explicit TaskExportStep(QWidget* parent = nullptr);
    ~TaskExportStep() override;

    bool showDialog() const;
    void accept() override;
    StepSettings getSettings() const;

private:
    QCheckBox* showThis;
    std::unique_ptr<DlgExportStep> ui;
};

}  // namespace PartGui
