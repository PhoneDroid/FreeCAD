// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2024 Shai Seger <shaise@gmail.com>

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

#include "ViewCAMSimulator.h"
#include "DlgCAMSimulator.h"

namespace CAMSimulator
{

ViewCAMSimulator::ViewCAMSimulator(Gui::Document* pcDocument, QWidget* parent, Qt::WindowFlags wflags)
    : Gui::MDIView(pcDocument, parent, wflags)
{
    mDlg = new DlgCAMSimulator(*this);
    setCentralWidget(mDlg);
}

ViewCAMSimulator* ViewCAMSimulator::clone()
{
    auto viewCam = new ViewCAMSimulator(_pcDocument, nullptr);

    viewCam->cloneFrom(*this);
    viewCam->mDlg->cloneFrom(*mDlg);

    return viewCam;
}

DlgCAMSimulator& ViewCAMSimulator::dlg()
{
    return *mDlg;
}

}  // namespace CAMSimulator
