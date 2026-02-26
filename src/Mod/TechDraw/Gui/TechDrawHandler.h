// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileCopyrightText: 2024 Pierre-Louis Boyer <development@ondsel.com>

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

#include <Gui/ToolHandler.h>

#include <Mod/TechDraw/TechDrawGlobal.h>

namespace TechDrawGui
{
class QGVPage;

class TechDrawGuiExport TechDrawHandler : public Gui::ToolHandler
{
public:

    TechDrawHandler();
    virtual ~TechDrawHandler();

    void activate(QGVPage* vPage);
    void deactivate() override;

    void quit() override;

    virtual void mouseMoveEvent(QMouseEvent* event) = 0;
    virtual void mousePressEvent(QMouseEvent* event) { Q_UNUSED(event) };
    virtual void mouseReleaseEvent(QMouseEvent* event);

    virtual void keyPressEvent(QKeyEvent* event) = 0;
    virtual void keyReleaseEvent(QKeyEvent* event);

    TechDraw::DrawPage* getPage();


protected:
    QWidget* getCursorWidget() override;
    void setWidgetCursor(QCursor cursor) override;

    QGVPage* viewPage;
};


}  // namespace TechDrawGui