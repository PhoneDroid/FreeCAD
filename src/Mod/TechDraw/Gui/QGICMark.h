// SPDX-FileCopyrightText: 2013 Luke Parry <l.parry@warwick.ac.uk>
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

#include "QGIUserTypes.h"
#include "QGIVertex.h"

namespace TechDrawGui
{

class TechDrawGuiExport QGICMark : public QGIVertex
{
public:
    explicit QGICMark(int index);
    ~QGICMark() override {}

    enum {Type = UserType::QGICMark};
    int type() const override { return Type;}
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr ) override;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void draw(void);
    float getSize() { return m_size; }
    void setSize(float s);
    float getThick() { return m_pen.widthF(); }
    void setThick(float t);
    void setPrettyNormal() override;

    double getMarkFuzz(void) const;

protected:
    QColor getCMarkColor();

private:
    float m_size;
};

}