// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2012-2014 Luke Parry <l.parry@warwick.ac.uk>

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

#include <QGraphicsItemGroup>
#include <QObject>

#include "QGIUserTypes.h"

QT_BEGIN_NAMESPACE
class QGraphicsScene;
QT_END_NAMESPACE

namespace TechDraw {
class DrawTemplate;
}

namespace TechDrawGui
{
class TemplateTextField;
class QGSPage;

class TechDrawGuiExport QGITemplate : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    QGITemplate(QGSPage *);
    ~QGITemplate() override;

    enum {Type = UserType::QGITemplate};
    int type() const override { return Type;}

    void clearContents();

    void setTemplate(TechDraw::DrawTemplate *obj);
    TechDraw::DrawTemplate * getTemplate() { return pageTemplate; }

    inline qreal getY() { return y() * -1; }

    virtual void updateView(bool update = false);
    virtual std::vector<TemplateTextField *> getTextFields() { return textFields; };

    virtual void draw() = 0;

protected:
    TechDraw::DrawTemplate *pageTemplate;

    std::vector<TemplateTextField *> textFields;
};

} // namespace