// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2013 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Gui/MouseSelection.h>
#include <QColor>
#include <QPoint>
#include <QList>

namespace SandboxGui {
class DrawingPlane : public Gui::BaseMouseSelection
{
public:
    DrawingPlane();
    virtual ~DrawingPlane();

protected:
    void initialize();
    void terminate();
    virtual int mouseButtonEvent( const SoMouseButtonEvent * const e, const QPoint& pos );
    virtual int locationEvent   ( const SoLocation2Event   * const e, const QPoint& pos );
    virtual int keyboardEvent   ( const SoKeyboardEvent    * const e );
    void draw ();

private:
    void drawLineTo(const QPoint &endPoint);

    bool scribbling;
    int myPenWidth;
    float myRadius;
    QColor myPenColor;
    QPoint lastPoint;
    QList<QPoint> selection;

    QOpenGLFramebufferObject* fbo;
};

} // SandboxGui