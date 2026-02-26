// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2012-2013 Luke Parry <l.parry@warwick.ac.uk>

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

#include "QGIView.h"
#include "QGIUserTypes.h"

QT_BEGIN_NAMESPACE
class QGraphicsScene;
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

namespace TechDrawGui
{

class TechDrawGuiExport  QGIViewCollection : public QGIView
{
public:
    QGIViewCollection();
    ~QGIViewCollection() override = default;

    enum {Type = UserType::QGIViewCollection};
    int type() const override { return Type;}
};

} // namespace MDIViewPageGui