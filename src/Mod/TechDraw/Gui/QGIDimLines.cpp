// SPDX-FileCopyrightText: 2016 WandererFan <wandererfan@gmail.com>
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

# include <cassert>

# include <QPainterPath>
# include <QPainterPathStroker>

#include "QGIDimLines.h"
#include "PreferencesGui.h"


using namespace TechDrawGui;
using namespace TechDraw;

QGIDimLines::QGIDimLines()
{
    setCacheMode(QGraphicsItem::NoCache);
    setAcceptHoverEvents(false);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setWidth(0.5);
}

void QGIDimLines::draw()
{
}

QPainterPath QGIDimLines::shape() const
{
    QPainterPath outline;
    QPainterPathStroker stroker;
    stroker.setWidth(getEdgeFuzz());
    outline = stroker.createStroke(path());
    return outline;
}

double QGIDimLines::getEdgeFuzz() const
{
    return PreferencesGui::edgeFuzz();
}


QRectF QGIDimLines::boundingRect() const
{
    return shape().controlPointRect().adjusted(-3, -3, 3, 3);
}
