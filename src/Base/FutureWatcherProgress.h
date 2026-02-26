// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2011 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QObject>
#include <Base/Sequencer.h>


namespace Base
{

class BaseExport FutureWatcherProgress: public QObject
{
    Q_OBJECT

public:
    FutureWatcherProgress(const char* text, unsigned int steps);
    ~FutureWatcherProgress() override;

    FutureWatcherProgress(const FutureWatcherProgress&) = delete;
    FutureWatcherProgress(FutureWatcherProgress&&) = delete;
    FutureWatcherProgress& operator=(const FutureWatcherProgress&) = delete;
    FutureWatcherProgress& operator=(FutureWatcherProgress&&) = delete;

public Q_SLOTS:
    void progressValueChanged(int value);

private:
    Base::SequencerLauncher seq;
    unsigned int steps, current {0};
};
}  // namespace Base
