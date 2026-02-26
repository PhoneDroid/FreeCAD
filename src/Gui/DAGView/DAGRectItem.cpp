// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2015 Thomas Anderson <blobfish@gmx.com>
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

#include <QApplication>
#include <QPainter>


#include <QStyleOptionViewItem>

#include "DAGRectItem.h"


using namespace Gui;
using namespace DAG;

RectItem::RectItem(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    selected = false;
    preSelected = false;
    editing = false;
}

void RectItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->save();

    QStyleOptionViewItem styleOption;

    styleOption.backgroundBrush = backgroundBrush;
    if (editing) {
        styleOption.backgroundBrush = editBrush;
    }
    else {
        styleOption.state |= QStyle::State_Enabled;
        if (selected) {
            styleOption.state |= QStyle::State_Selected;
        }
        if (preSelected) {
            if (!selected) {
                styleOption.state |= QStyle::State_Selected;
                QPalette palette = styleOption.palette;
                QColor tempColor = palette.color(QPalette::Active, QPalette::Highlight);
                tempColor.setAlphaF(0.15F);
                palette.setColor(QPalette::Inactive, QPalette::Highlight, tempColor);
                styleOption.palette = palette;
            }
            styleOption.state |= QStyle::State_MouseOver;
        }
    }
    styleOption.rect = this->rect().toRect();

    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &styleOption, painter);

    painter->restore();
}
