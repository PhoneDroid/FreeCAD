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


#include "QGVNavStyleOpenSCAD.h"
#include "QGVPage.h"


using namespace TechDrawGui;

namespace TechDrawGui {

QGVNavStyleOpenSCAD::QGVNavStyleOpenSCAD(QGVPage *qgvp) :
    QGVNavStyle(qgvp)
{
}

QGVNavStyleOpenSCAD::~QGVNavStyleOpenSCAD()
{
}

void QGVNavStyleOpenSCAD::handleKeyReleaseEvent(QKeyEvent *event)
{
    //zoom mode 2
    if ( (event->key() == Qt::Key_Shift) && zoomingActive) {
        stopZoom();
        event->accept();
    }
}

void QGVNavStyleOpenSCAD::handleMousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        startClick(Qt::RightButton);
    }
}

void QGVNavStyleOpenSCAD::handleMouseMoveEvent(QMouseEvent *event)
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

    if (QGuiApplication::mouseButtons() & Qt::RightButton &&
        !QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        //pan mode - RMB + move
        if (panningActive) {
            pan(event->pos());
        } else {
            startPan(event->pos());
        }
        event->accept();
    }

    if (QGuiApplication::mouseButtons() & Qt::MiddleButton) {
        //zoom mode 1 - MMB + move
        if (zoomingActive) {
            zoom(mouseZoomFactor(event->pos()));
        } else {
            startZoom(event->pos());
        }
        event->accept();
    }

    if ((QGuiApplication::mouseButtons() & Qt::RightButton) &&
         QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        //zoom mode 2 - SHIFT + RMB + move
        if (zoomingActive) {
            zoom(mouseZoomFactor(event->pos()));
        } else {
            startZoom(event->pos());
        }
        event->accept();
    }
}

void QGVNavStyleOpenSCAD::handleMouseReleaseEvent(QMouseEvent *event)
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

    if ((event->button() == Qt::RightButton) && panningActive) {
        stopPan();
        event->accept();
    }

    if ((event->button() == Qt::RightButton) && zoomingActive) {
        stopZoom();
        event->accept();
    }

    if ((event->button() == Qt::MiddleButton) && zoomingActive) {
        stopZoom();
        event->accept();
    }
}

bool QGVNavStyleOpenSCAD::allowContextMenu(QContextMenuEvent *event)
{
//    Base::Console().message("QGVNSCAD::allowContextMenu()\n");
    if (event->reason() == QContextMenuEvent::Mouse) {
        //must check for a button combination involving context menu button
        if (QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
            //Shift down - don't allow context menu
            return false;
        } else if (m_clickPending) {
            //context menu request to be handled by button release
            return false;
        }
    }
    return true;
}


}  // namespace TechDrawGui
