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

#include <Mod/TechDraw/App/Geometry.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "QGIPrimPath.h"
#include "QGIUserTypes.h"

namespace TechDrawGui
{

class TechDrawGuiExport QGIEdge : public QGIPrimPath
{
public:
    explicit QGIEdge(int index);
    ~QGIEdge() override = default;

    enum {Type = UserType::QGIEdge};

    int type() const override { return Type;}
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    int getProjIndex() const { return projIndex; }

    void setCosmetic(bool state);
    void setHiddenEdge(bool b);
    bool getHiddenEdge() const { return(isHiddenEdge); }
    void setSmoothEdge(bool b) { isSmoothEdge = b; }
    bool getSmoothEdge() const { return(isSmoothEdge); }
    void setPrettyNormal() override;

    double getEdgeFuzz() const;

    void setLinePen(const QPen& isoPen);

    void setSource(TechDraw::SourceType source) { m_source = source; }
    TechDraw::SourceType getSource() const { return m_source;}

protected:

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    bool multiselectEligible() override { return true; }

    QColor getHiddenColor();

private:
    int projIndex;                                                     //index of edge in Projection. must exist.

    bool isCosmetic;
    bool isHiddenEdge;
    bool isSmoothEdge;

    TechDraw::SourceType m_source{TechDraw::SourceType::GEOMETRY};
};

}