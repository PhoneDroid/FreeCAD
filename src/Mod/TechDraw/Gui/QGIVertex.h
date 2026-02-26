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

#include "QGIPrimPath.h"
#include "QGIUserTypes.h"

namespace Base {
class Vector2d;
}

namespace TechDrawGui
{

class TechDrawGuiExport QGIVertex : public QGIPrimPath
{
public:
    explicit QGIVertex(int index);
    ~QGIVertex() override = default;

    enum {Type = UserType::QGIVertex};
    int type() const override { return Type;}
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr ) override;

    int getProjIndex() const { return projIndex; }

    double getRadius() const { return m_radius; }
    virtual void setRadius(double r);

    Base::Vector2d toVector2d() const;
    Base::Vector2d vector2dBetweenPoints(const QGIVertex* p2) const;

protected:
    bool multiselectEligible() override { return true; }

    int projIndex;
    double m_radius;
};

}