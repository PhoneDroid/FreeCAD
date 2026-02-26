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

class QGraphicsScene;
class QGraphicsSvgItem;
class QSvgRenderer;
class QFile;
class QString;

#include "QGITemplate.h"
#include "QGIUserTypes.h"

namespace TechDraw
{
class DrawSVGTemplate;
}

namespace TechDrawGui
{
class QGSPage;

class TechDrawGuiExport QGISVGTemplate : public TechDrawGui::QGITemplate
{
    Q_OBJECT

public:
    explicit QGISVGTemplate(QGSPage* scene);
    ~QGISVGTemplate() override;

    enum {Type = UserType::QGISVGTemplate};
    int type() const override { return Type; }

    void draw() override;
    void drawPageRectangle();

    void updateView(bool update = false) override;

    TechDraw::DrawSVGTemplate* getSVGTemplate() const;
    std::vector<TemplateTextField*> getTextFields() override;

protected:
    void openFile(const QFile& file);
    void load(QByteArray svgCode);

    void createClickHandles();
    void clearClickHandles();

private:
    QGraphicsSvgItem* m_svgItem;
    QSvgRenderer* m_svgRender;
    QGraphicsRectItem* m_pageRectangle;

};// class QGISVGTemplate

}// namespace TechDrawGui