// SPDX-FileCopyrightText: 2016 WandererFan <wandererfan@gmail.com>
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

namespace TechDraw {
class DrawViewImage;
}

namespace TechDrawGui
{
class QGCustomImage;
class QGCustomClip;

class TechDrawGuiExport QGIViewImage : public QGIView
{
public:
    QGIViewImage();
    ~QGIViewImage() override;

    enum {Type = UserType::QGIViewImage};
    int type() const override { return Type;}

    void updateView(bool update = false) override;
    void setViewImageFeature(TechDraw::DrawViewImage *obj);

    void draw() override;
    void rotateView() override;

protected:
    virtual void drawImage();

    QGCustomImage* m_imageItem;
    QGCustomClip*  m_cliparea;
};

} // namespace