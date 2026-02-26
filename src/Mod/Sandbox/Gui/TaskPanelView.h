// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2009 Jürgen Riegel <juergen.riegel@web.de>
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

#include <QWidget>

namespace SandboxGui {

/** A test class. A more elaborate class description.
 */
class TaskPanelView : public QWidget
{
    //Q_OBJECT

public:
    /**
     * A constructor.
     * A more elaborate description of the constructor.
     */
    TaskPanelView(QWidget *parent=0);

    /**
     * A destructor.
     * A more elaborate description of the destructor.
    */
    virtual ~TaskPanelView();

    void executeAction();
    void on_rbDefaultScheme_toggled(bool b);
    void on_rbXPBlueScheme_toggled(bool b);
    void on_rbXPBlue2Scheme_toggled(bool b);
    void on_rbVistaScheme_toggled(bool b);
    void on_rbMacScheme_toggled(bool b);
    void on_rbAndroidScheme_toggled(bool b);

private:
    QWidget* actionGroup;
};

} // namespace SandboxGui