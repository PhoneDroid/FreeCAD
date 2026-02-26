// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2007 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Gui/PropertyPage.h>

class QButtonGroup;

namespace PartGui
{

class Ui_DlgSettingsGeneral;
class DlgSettingsGeneral: public Gui::Dialog::PreferencePage
{
    Q_OBJECT

public:
    explicit DlgSettingsGeneral(QWidget* parent = nullptr);
    ~DlgSettingsGeneral() override;

protected:
    void saveSettings() override;
    void loadSettings() override;
    void changeEvent(QEvent* e) override;

private:
    std::unique_ptr<Ui_DlgSettingsGeneral> ui;
};

class Ui_DlgImportExportIges;
class DlgImportExportIges: public Gui::Dialog::PreferencePage
{
    Q_OBJECT

public:
    explicit DlgImportExportIges(QWidget* parent = nullptr);
    ~DlgImportExportIges() override;

protected:
    void saveSettings() override;
    void loadSettings() override;
    void changeEvent(QEvent* e) override;

private:
    std::unique_ptr<Ui_DlgImportExportIges> ui;
    QButtonGroup* bg;
};

class DlgExportStep;
class DlgImportStep;
class DlgExportHeaderStep;
class DlgImportExportStep: public Gui::Dialog::PreferencePage
{
    Q_OBJECT

public:
    explicit DlgImportExportStep(QWidget* parent = nullptr);
    ~DlgImportExportStep() override;

protected:
    void saveSettings() override;
    void loadSettings() override;
    void changeEvent(QEvent* e) override;

private:
    DlgExportStep* exportStep;
    DlgImportStep* importStep;
    DlgExportHeaderStep* headerStep;
};

}  // namespace PartGui
