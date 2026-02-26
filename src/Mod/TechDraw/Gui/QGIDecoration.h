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

#pragma once

#include <Mod/TechDraw/TechDrawGlobal.h>

#include <QBrush>
#include <QGraphicsItemGroup>
#include <QPen>


QT_BEGIN_NAMESPACE
class QPainter;
class QStyleOptionGraphicsItem;
QT_END_NAMESPACE

#include <Base/Parameter.h>
#include <Base/Console.h>
#include <Base/Vector3D.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "Enums.h"
#include "QGIUserTypes.h"

namespace TechDrawGui
{

class TechDrawGuiExport QGIDecoration : public QGraphicsItemGroup
{
public:
    explicit QGIDecoration();
    ~QGIDecoration() override = default;
    enum {Type = UserType::QGIDecoration};
    int type() const override { return Type;}

    QRectF boundingRect() const override;
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget = nullptr ) override;
    virtual void draw();

    // Mouse handling
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void onDragFinished();

    void setWidth(double w);
    double getWidth() { return m_pen.widthF(); }
    void setStyle(Qt::PenStyle s);
    void setColor(QColor c);
    QColor getColor() { return m_colNormal; }
    void makeMark(double x, double y);
    void makeMark(Base::Vector3d v);

protected:
    void setPrettyNormal();
    void setPrettyPre();
    void setPrettySel();
    virtual QColor prefNormalColor();
    virtual QColor prefPreColor();
    virtual QColor prefSelectColor();
    QPen m_pen;
    QBrush m_brush;
    QColor m_colNormal;

    DragState m_dragState;

private:
};

}