// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2013 Luke Parry <l.parry@warwick.ac.uk>
// SPDX-FileCopyrightText: 2024 Benjamin Bræstrup Sayoc <benj5378@outlook.com>

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

# include <QPainter>
# include <QPainterPath>
# include <QStyleOptionGraphicsItem>

#include <Base/Tools2D.h>

#include "QGIVertex.h"
#include "PreferencesGui.h"
#include "QGIPrimPath.h"


using namespace TechDrawGui;

QGIVertex::QGIVertex(int index) :
    projIndex(index),
    m_radius(2)
{
    QColor vertexColor = PreferencesGui::vertexQColor();
    setFill(vertexColor, Qt::SolidPattern);

    setRadius(m_radius);
}

void QGIVertex::setRadius(double r)
{
    m_radius = r;
    QPainterPath p;
    p.addEllipse(-r/2.0, -r/2.0, r, r);
    setPath(p);
}

void QGIVertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QStyleOptionGraphicsItem myOption(*option);
    myOption.state &= ~QStyle::State_Selected;

//    painter->setPen(Qt::blue);
//    painter->drawRect(boundingRect());          //good for debugging

//    m_brush.setColor(m_colCurrent);
//    m_brush.setStyle(m_fill);
//    setBrush(m_brush);
    QGIPrimPath::paint (painter, &myOption, widget);
}

Base::Vector2d QGIVertex::toVector2d() const
{
    QPointF center = boundingRect().center();
    center = mapToScene(center);
    return Base::Vector2d(center.x(), center.y());
}

//! Returns a vector drawn from own position to p2
Base::Vector2d QGIVertex::vector2dBetweenPoints(const QGIVertex* p2) const
{
    return p2->toVector2d() - toVector2d();
}
