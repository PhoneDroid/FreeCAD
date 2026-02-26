// SPDX-FileCopyrightText: 2015 WandererFan <wandererfan@gmail.com>
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

#include <QByteArray>
#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QPointF>
#include <QSvgRenderer>

#include "QGIUserTypes.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QStyleOptionGraphicsItem;
QT_END_NAMESPACE

namespace TechDrawGui
{

class TechDrawGuiExport QGCustomSvg : public QGraphicsSvgItem
{
public:
    explicit QGCustomSvg();
    ~QGCustomSvg() override;

    enum {Type = UserType::QGCustomSvg};
    int type() const override { return Type;}

    void paint( QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                QWidget *widget = nullptr ) override;
    virtual void centerAt(QPointF centerPos);
    virtual void centerAt(double cX, double cY);
    virtual bool load(QByteArray *svgString);
    virtual bool load(QString filename);

protected:
    QSvgRenderer *m_svgRender;
};

} // namespace TechDrawGui