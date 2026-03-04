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

#include <QApplication>
#include <QDialog>
#include <QFileDialog>
#include <QLibrary>
#include <QPushButton>

QLibrary* freecadPlugin = nullptr;

void loadFreeCAD()
{
    if (!freecadPlugin) {
        freecadPlugin = new QLibrary("FreeCADPlugin", qApp);
    }

    if (!freecadPlugin->isLoaded()) {
        if (freecadPlugin->load()) {
            QFunctionPointer ptr = freecadPlugin->resolve("FreeCAD_init");
            if (ptr) {
                ptr();
            }
        }
    }

    // Load a test file
    if (freecadPlugin->isLoaded()) {
        typedef void (*TestFunction)(const char*);
        TestFunction test = (TestFunction)freecadPlugin->resolve("FreeCAD_test");
        if (test) {
            QString file = QFileDialog::getOpenFileName();
            if (!file.isEmpty()) {
                test(file.toUtf8());
            }
        }
    }
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QDialog dlg;
    QPushButton* button = new QPushButton(&dlg);
    button->setGeometry(QRect(140, 110, 90, 23));
    button->setText("Load FreeCAD");
    QObject::connect(button, &QPushButton::clicked, &loadFreeCAD);
    dlg.show();
    return app.exec();
}
