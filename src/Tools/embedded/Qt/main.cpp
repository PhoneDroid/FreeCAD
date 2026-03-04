// SPDX-License-Identifier: LGPL-2.1-or-later
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

#include <Python.h>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[])
{
    const char* name = "Qt example";
    Py_SetProgramName(Py_DecodeLocale(name, NULL));
    Py_Initialize();

    size_t size = argc;
    wchar_t** _argv = new wchar_t*[size];
    for (int i = 0; i < argc; i++) {
        _argv[i] = Py_DecodeLocale(argv[i], NULL);
    }
    PySys_SetArgv(argc, _argv);

    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.resize(600, 400);
    mainWin.show();
    return app.exec();
}
