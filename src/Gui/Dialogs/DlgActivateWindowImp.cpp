// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2004 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QApplication>
#include <QPushButton>

#include "Dialogs/DlgActivateWindowImp.h"
#include "ui_DlgActivateWindow.h"
#include "MainWindow.h"
#include "MDIView.h"


using namespace Gui::Dialog;

/* TRANSLATOR Gui::Dialog::DlgActivateWindowImp */

/**
 *  Constructs a DlgActivateWindowImp which is a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
DlgActivateWindowImp::DlgActivateWindowImp(QWidget* parent, Qt::WindowFlags fl)
    : QDialog(parent, fl)
    , ui(new Ui_DlgActivateWindow)
{
    // create widgets
    ui->setupUi(this);
    QPushButton* buttonOk = ui->buttonBox->button(QDialogButtonBox::Ok);
    buttonOk->setText(QApplication::translate("Gui::Dialog::DlgActivateWindow", "&Activate"));
    QTreeWidgetItem* active = nullptr;
    QStringList labels;
    labels << tr("Windows");
    ui->treeWidget->setHeaderLabels(labels);
    ui->treeWidget->header()->hide();

    QList<QWidget*> windows = getMainWindow()->windows();
    if (windows.isEmpty()) {
        buttonOk->setDisabled(true);
        return;
    }

    QWidget* activeWnd = getMainWindow()->activeWindow();

    for (QWidget* it : windows) {
        auto item = new QTreeWidgetItem(ui->treeWidget);
        QString title = it->windowTitle();
        title.replace(QLatin1String("[*]"), QLatin1String(""));
        if (it->isWindowModified()) {
            title += QLatin1String("*");
        }
        item->setText(0, title);
        if (it == activeWnd) {
            active = item;
        }
    }

    if (active) {
        ui->treeWidget->setCurrentItem(active);
    }
    ui->treeWidget->setFocus();
}

/** Destroys the object and frees any allocated resources */
DlgActivateWindowImp::~DlgActivateWindowImp()
{
    delete ui;
}

/**
 * Activates the MDI window you wish and closes the dialog.
 */
void DlgActivateWindowImp::accept()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    QList<QWidget*> windows = getMainWindow()->windows();

    if (item) {
        int index = ui->treeWidget->indexOfTopLevelItem(item);
        getMainWindow()->setActiveWindow(static_cast<MDIView*>(windows.at(index)));
    }

    QDialog::accept();
}

#include "moc_DlgActivateWindowImp.cpp"
