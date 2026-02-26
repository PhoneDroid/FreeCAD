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


#include "DlgPartCylinderImp.h"
#include "ui_DlgPartCylinder.h"


using namespace PartGui;

DlgPartCylinderImp::DlgPartCylinderImp(QWidget* parent, Qt::WindowFlags fl)
    : Gui::LocationDialogUiImp(new Ui_DlgPartCylinder, parent, fl)
{}

/*
 *  Destroys the object and frees any allocated resources
 */
DlgPartCylinderImp::~DlgPartCylinderImp() = default;

Ui_DlgPartCylinderPtr DlgPartCylinderImp::getUi() const
{
    return boost::any_cast<Ui_DlgPartCylinderPtr>(ui->get());
}

double DlgPartCylinderImp::getRadius() const
{
    return getUi()->radius->value().getValue();
}

double DlgPartCylinderImp::getLength() const
{
    return getUi()->length->value().getValue();
}

#include "moc_DlgPartCylinderImp.cpp"
