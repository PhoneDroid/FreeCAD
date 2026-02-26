// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2004 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QItemDelegate>
#include <QPointer>

namespace Gui
{
namespace PropertyEditor
{

class PropertyEditorWidget;

class PropertyItemDelegate: public QItemDelegate
{
    Q_OBJECT

public:
    explicit PropertyItemDelegate(QObject* parent);
    ~PropertyItemDelegate() override;

    void paint(QPainter* painter, const QStyleOptionViewItem& opt, const QModelIndex& index) const override;
    QWidget* createEditor(QWidget*, const QStyleOptionViewItem&, const QModelIndex&) const override;
    void setEditorData(QWidget* editor, const QModelIndex& index) const override;
    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    bool editorEvent(
        QEvent* event,
        QAbstractItemModel* model,
        const QStyleOptionViewItem& option,
        const QModelIndex& index
    ) override;

protected:
    bool eventFilter(QObject*, QEvent*) override;

    void valueChanged();

private:
    mutable QPointer<QWidget> propertyEditor;
    mutable QWidget* expressionEditor;
    mutable PropertyEditorWidget* userEditor = nullptr;
    mutable bool pressed;
    bool changed;
};

}  // namespace PropertyEditor
}  // namespace Gui
