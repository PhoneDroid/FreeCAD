// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2012 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QCoreApplication>
#include <QEvent>

#include "Debugger.h"
#include "Console.h"


using namespace Base;

Debugger::Debugger(QObject* parent)
    : QObject(parent)
{}

Debugger::~Debugger() = default;

void Debugger::attach()
{
    QCoreApplication::instance()->installEventFilter(this);
    isAttached = true;
}

void Debugger::detach()
{
    QCoreApplication::instance()->removeEventFilter(this);
    isAttached = false;
}

bool Debugger::eventFilter(QObject* /*watched*/, QEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        if (loop.isRunning()) {
            loop.quit();
            return true;
        }
    }

    return false;
}

int Debugger::exec()
{
    if (isAttached) {
        Base::Console().message("TO CONTINUE PRESS ANY KEY...\n");
    }
    return loop.exec();
}

void Debugger::quit()
{
    loop.quit();
}

#include "moc_Debugger.cpp"
