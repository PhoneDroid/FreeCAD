// SPDX-FileCopyrightText: 2022 WandererFan <wandererfan@gmail.com>
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

//based on a python widget from:
//https://github.com/tcalmant/demo-ipopo-qt/blob/master/pc/details/compass.py

#pragma once

#include <QWidget>
#include <QSize>

namespace TechDrawGui {

class CompassDialWidget : public QWidget
{
    Q_OBJECT

public:
    CompassDialWidget(QWidget* parent = nullptr);
    ~CompassDialWidget() override = default;

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    double angle() const { return m_angle; }
    void setAngle(double newAngle);
    void setSize(int newSize);

public Q_SLOTS:
    void slotChangeAngle(double angle) { setAngle(angle); }
    void resetAngle() { setAngle(0.0); }

protected:
    void paintEvent(QPaintEvent* event) override;
    void drawWidget(QPainter& painter);
    void drawNeedle(QPainter& painter);
    void drawMarkings(QPainter& painter);
    void drawBackground(QPainter& painter);

private:
    QRect m_rect;
    double m_angle;
    double m_margin;
    double m_markInterval;
    int m_defaultSize;
    int m_defaultMargin;
    int m_designRadius;
    int m_designDiameter;
};

} //namespace TechDrawGui