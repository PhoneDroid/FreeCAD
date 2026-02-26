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

#include "QGIView.h"
#include "QGIUserTypes.h"

namespace TechDraw
{
class DrawView;
}

namespace TechDrawGui
{
class QGCustomRect;
class QGCustomClip;

class TechDrawGuiExport QGIViewClip : public QGIView
{
public:

    QGIViewClip();
    ~QGIViewClip() override = default;

    enum {Type = UserType::QGIViewClip};
    int type() const override { return Type;}
    bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;
    TechDraw::DrawView* selectionIsInGroup() const;
    bool forwardEventToSelection(QGIView* qview, QEvent *event) const;

    void updateView(bool update = false) override;

    void draw() override;
    QGCustomRect* getFrame() {return m_frame;}
    QGCustomClip* getClipArea() {return m_cliparea;}

protected:
    void drawClip();

private:
    QGCustomRect* m_frame;
    QGCustomClip* m_cliparea;

};

} // namespace MDIViewPageGui