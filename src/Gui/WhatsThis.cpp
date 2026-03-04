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
#include <QWhatsThisClickedEvent>


#include "WhatsThis.h"
#include "Action.h"
#include "MainWindow.h"


using namespace Gui;


bool StdCmdDescription::_descrMode = false;

/* TRANSLATOR Gui::StdCmdDescription */

StdCmdDescription::StdCmdDescription()
    : Command("Std_DescriptionMode")
{
    sGroup = "Help";
    sMenuText = QT_TR_NOOP("Des&cription");
    sToolTipText = QT_TR_NOOP("Long description of commands");
    sWhatsThis = "Std_DescriptionMode";
    sStatusTip = sToolTipText;
    sAccel = "F1";
}

StdCmdDescription::~StdCmdDescription() = default;

Action* StdCmdDescription::createAction()
{
    Action* pcAction = Command::createAction();
    pcAction->setCheckable(true);
    return pcAction;
}

void StdCmdDescription::activated(int iMsg)
{
    Q_UNUSED(iMsg);
    if (!inDescriptionMode()) {
        enterDescriptionMode();
    }
    else {
        leaveDescriptionMode();
    }
}

bool StdCmdDescription::inDescriptionMode()
{
    return _descrMode;
}

void StdCmdDescription::setSource(const QString& src)
{
    if (!src.isEmpty()) {
        QWhatsThisClickedEvent e(src);
        QApplication::sendEvent(getMainWindow(), &e);
    }
}

void StdCmdDescription::enterDescriptionMode()
{
    _descrMode = true;
    QApplication::setOverrideCursor(Qt::WhatsThisCursor);
}

void StdCmdDescription::leaveDescriptionMode()
{
    _descrMode = false;
    QApplication::restoreOverrideCursor();
}
