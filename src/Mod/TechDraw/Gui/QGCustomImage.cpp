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

# include <QPainter>
# include <QPixmap>
# include <QRectF>
# include <QStyleOptionGraphicsItem>


#include "QGCustomImage.h"


using namespace TechDrawGui;

QGCustomImage::QGCustomImage()
{
    setCacheMode(QGraphicsItem::NoCache);
    setAcceptHoverEvents(false);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QGCustomImage::~QGCustomImage()
{
}

void QGCustomImage::centerAt(QPointF centerPos)
{
    centerAt(centerPos.x(), centerPos.y());
}

void QGCustomImage::centerAt(double cX, double cY)
{
    QRectF br = boundingRect();
    double width = br.width() * scale();
    double height = br.height() * scale();
    double newX = cX - width/2.;
    double newY = cY - height/2.;
    setPos(newX, newY);
}

bool QGCustomImage::load(QString fileSpec)
{
    bool success = true;
    QPixmap px(fileSpec);
    m_px = px;
    prepareGeometryChange();
    setPixmap(m_px);
    return(success);
}

bool QGCustomImage::load(QPixmap map)
{
    bool success = true;
    m_px = map;
    prepareGeometryChange();
    setPixmap(m_px);
    return(success);
}

QSize QGCustomImage::imageSize()
{
    return m_px.size() * scale();
}

void QGCustomImage::paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    QStyleOptionGraphicsItem myOption(*option);
    myOption.state &= ~QStyle::State_Selected;

    //painter->drawRect(boundingRect());          //good for debugging

    QGraphicsPixmapItem::paint (painter, &myOption, widget);
}

