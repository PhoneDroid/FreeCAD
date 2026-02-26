// SPDX-FileCopyrightText: 2022 Wanderer Fan <wandererfan@gmail.com>
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

# include <QGuiApplication>
# include <QMouseEvent>


#include "QGVNavStyleGesture.h"
#include "QGVPage.h"


using namespace TechDrawGui;

namespace TechDrawGui {

QGVNavStyleGesture::QGVNavStyleGesture(QGVPage* qgvp) :
    QGVNavStyle(qgvp)
{
}

QGVNavStyleGesture::~QGVNavStyleGesture()
{
}

void QGVNavStyleGesture::handleMousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        startClick(Qt::RightButton);
    }
}

void QGVNavStyleGesture::handleMouseMoveEvent(QMouseEvent *event)
{
    if (getViewer()->isBalloonPlacing()) {
        balloonCursorMovement(event);
        return;
    }

    //if the mouse moves between press and release, then it isn't a click
    if (m_clickPending) {
        stopClick();
        return;
    }

    if (QGuiApplication::mouseButtons() & Qt::RightButton) {
        //pan mode 1 - RMB + move
        if (panningActive) {
            pan(event->pos());
        } else {
            startPan(event->pos());
        }
        event->accept();
    }
}

void QGVNavStyleGesture::handleMouseReleaseEvent(QMouseEvent *event)
{
    if (getViewer()->isBalloonPlacing()) {
        placeBalloon(event->pos());
    }

    if ((event->button() == Qt::RightButton) &&
         m_clickPending &&
        (m_clickButton == Qt::RightButton)) {
        stopClick();
        pseudoContextEvent();
        event->accept();
        return;
    }

    if (event->button() == Qt::RightButton) {
        stopPan();
        event->accept();
    }
}

//RMB for pan conflicts with RMB for context menu
bool QGVNavStyleGesture::allowContextMenu(QContextMenuEvent *event)
{
    if (event->reason() == QContextMenuEvent::Mouse) {
        return false;
    }
    return true;
}

}  // namespace TechDrawGui
