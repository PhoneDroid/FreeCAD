// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2004 Jürgen Riegel <juergen.riegel@web.de>
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


#include <Base/Console.h>

namespace Gui
{

/** The console window class
 *  This class opens a console window when instantiated
 *  and redirects the stdio streams to it as long it exists.
 *  This is for Windows only!
 *  After instantiation it automatically registers itself at
 *  the FCConsole class and gets all the FCConsoleObserver
 *  messages. The class must not used directly! Only the
 *  FCConsole class is allowed!
 *  @see FCConsole
 *  \author Jürgen Riegel
 */
class GuiExport GUIConsole: public Base::ILogger
{
public:
    /// Constructor
    GUIConsole();
    /// Destructor
    ~GUIConsole() override;
    void sendLog(
        const std::string& notifiername,
        const std::string& msg,
        Base::LogStyle level,
        Base::IntendedRecipient recipient,
        Base::ContentType content
    ) override;
    const char* name() override
    {
        return "GUIConsole";
    }

protected:
    static const unsigned int s_nMaxLines;
    static unsigned int s_nRefCount;
};

}  // namespace Gui
