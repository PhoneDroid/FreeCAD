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

#pragma once

#include <QSplashScreen>

namespace Gui
{

class SplashObserver;

/** This widget provides a splash screen that can be shown during application startup.
 *
 * \author Werner Mayer
 */
class SplashScreen: public QSplashScreen
{
    Q_OBJECT

public:
    explicit SplashScreen(const QPixmap& pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags());
    ~SplashScreen() override;

    void setShowMessages(bool on);

    static QPixmap splashImage();

protected:
    void drawContents(QPainter* painter) override;

private:
    SplashObserver* messages;
};

}  // namespace Gui
