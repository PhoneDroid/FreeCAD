// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2012-2014 Luke Parry <l.parry@warwick.ac.uk

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


#include <Mod/TechDraw/App/DrawTemplate.h>

#include "QGITemplate.h"
#include "QGSPage.h"
#include "ZVALUE.h"


using namespace TechDrawGui;

QGITemplate::QGITemplate(QGSPage *scene) : QGraphicsItemGroup(),
    pageTemplate(nullptr)
{
    setHandlesChildEvents(false);
    setCacheMode(QGraphicsItem::NoCache);
    setZValue(ZVALUE::TEMPLATE); //Template is situated in background

    scene->addItem(this);
}

QGITemplate::~QGITemplate()
{
    pageTemplate = nullptr;
}

void QGITemplate::setTemplate(TechDraw::DrawTemplate *obj)
{
    if (!obj)
        return;

    pageTemplate = obj;
}

void QGITemplate::clearContents()
{

}

void QGITemplate::updateView(bool update)
{
    Q_UNUSED(update);
    draw();
}

#include <Mod/TechDraw/Gui/moc_QGITemplate.cpp>
