// SPDX-FileCopyrightText: 2020 WandererFan <wandererfan@gmail.com>
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

#include <QGraphicsScene>
#include <QObject>
#include <QPointF>

#include "QGIHighlight.h"
#include "QGIUserTypes.h"


//a movable, selectable surrogate for detail highlights in QGIVPart

namespace TechDrawGui
{

class TechDrawGuiExport QGIGhostHighlight : public QObject, public QGIHighlight
{
    Q_OBJECT
public:
    explicit QGIGhostHighlight();
    ~QGIGhostHighlight() override;

    enum {Type = UserType::QGIGhostHighlight};
    int type() const override { return Type;}

    void setInteractive(bool state);
    void setRadius(double r);

Q_SIGNALS:
    void positionChange(QPointF p);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    bool m_dragging;

private:
};

}