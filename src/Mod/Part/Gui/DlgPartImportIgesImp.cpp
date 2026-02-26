// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2002 Jürgen Riegel <juergen.riegel@web.de>
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


#include <Gui/FileDialog.h>
#include <Gui/MainWindow.h>

#include "DlgPartImportIgesImp.h"
#include "ui_DlgPartImportIges.h"


using namespace PartGui;

/* TRANSLATOR PartGui::DlgPartImportIgesImp */

/*
 *  Constructs a DlgPartImportIges which is a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
DlgPartImportIgesImp::DlgPartImportIgesImp(QWidget* parent, Qt::WindowFlags fl)
    : QDialog(parent, fl)
    , ui(new Ui_DlgPartImportIges)
{
    ui->setupUi(this);
}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgPartImportIgesImp::~DlgPartImportIgesImp() = default;

/*
 * public slot
 */
void DlgPartImportIgesImp::OnApply()
{
    qWarning("DlgPartImportIgesImp::OnApply() not yet implemented!");
}

void DlgPartImportIgesImp::onChooseFileName()
{
    QString fn = Gui::FileDialog::getOpenFileName(
                     Gui::getMainWindow(),
                     QString(),
                     QString(),
                     QStringLiteral("%1 (*.igs *.iges);;%2 (*.*)")
    )
                     .arg(tr("IGES"), tr("All Files"));
    if (!fn.isEmpty()) {
        ui->FileName->setText(fn);
    }
}


#include "moc_DlgPartImportIgesImp.cpp"
