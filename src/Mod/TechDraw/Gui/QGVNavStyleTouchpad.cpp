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

# include <QApplication>
# include <QGuiApplication>
# include <QMouseEvent>


#include "QGVNavStyleTouchpad.h"
#include "QGVPage.h"


using namespace TechDrawGui;

namespace TechDrawGui {

QGVNavStyleTouchpad::QGVNavStyleTouchpad(QGVPage *qgvp) :
    QGVNavStyle(qgvp)
{
}

QGVNavStyleTouchpad::~QGVNavStyleTouchpad()
{
}

void QGVNavStyleTouchpad::handleKeyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_PageUp) {
        zoomIn();
        event->accept();
        return;
    }

    if (event->key() == Qt::Key_PageDown) {
        zoomOut();
        event->accept();
        return;
    }

    QGVNavStyle::handleKeyPressEvent(event);
}

void QGVNavStyleTouchpad::handleKeyReleaseEvent(QKeyEvent *event)
{
//    Q_UNUSED(event)
    if (event->key() == Qt::Key_Shift) {
        if (panningActive) {
            stopPan();
        }
        if (zoomingActive) {
            stopZoom();
        }
        event->accept();
    }

    if (event->key() == Qt::Key_Control) {
        stopZoom();
        event->accept();
    }

}

void QGVNavStyleTouchpad::handleMouseMoveEvent(QMouseEvent *event)
{
    if (getViewer()->isBalloonPlacing()) {
        balloonCursorMovement(event);
        return;
    }

    if (QApplication::keyboardModifiers() == Qt::ShiftModifier) {
        //if shift is down then we are panning
        if (panningActive) {
            pan(event->pos());
        } else {
            startPan(event->pos());
        }
        event->accept();
        return;
    }

    if (QGuiApplication::keyboardModifiers().testFlag(Qt::ControlModifier) &&
        QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier) ) {
        //if control and shift are down, then we are zooming
        if (zoomingActive) {
            zoom(mouseZoomFactor(event->pos()));
        } else {
            startZoom(event->pos());
        }
        event->accept();
        return;
    }

    // if the mouse moves, but we are not zooming or panning, then we should make
    // sure that zoom and pan are turned off.
    if (panningActive) {
        stopPan();
    }
    if (zoomingActive) {
        stopZoom();
    }
}

void QGVNavStyleTouchpad::setAnchor()
{
    if (QGuiApplication::keyboardModifiers().testFlag(Qt::ControlModifier)
        && QGuiApplication::keyboardModifiers().testFlag(Qt::ShiftModifier)) {
        // this navigation style can not anchor under mouse when zooming with Ctrl + Shift since
        // mouse is moving as part of zoom action

        if (m_viewer) {
            m_viewer->setResizeAnchor(QGraphicsView::AnchorViewCenter);
            m_viewer->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        }
    }
    else {
        QGVNavStyle::setAnchor();
    }
}

}  //namespace TechDrawGui
