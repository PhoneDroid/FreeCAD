// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2007 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QLayout>
#include <QOpenGLWidget>
#include <QRect>
#include <QWidgetItem>
#include <Inventor/SbVec3f.h>
#include <Gui/GLPainter.h>

namespace Gui
{
class View3DInventorViewer;

/**
 * @author Werner Mayer
 */
class GuiExport Flag: public QOpenGLWidget
{
    Q_OBJECT

public:
    Flag(QWidget* parent = nullptr);
    ~Flag() override;

    QSize sizeHint() const override;
    void setOrigin(const SbVec3f&);
    const SbVec3f& getOrigin() const;
    void drawLine(Gui::View3DInventorViewer*, int tox, int toy);
    void setText(const QString&);

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void contextMenuEvent(QContextMenuEvent*) override;

private:
    QString text;
    SbVec3f coord;
    QPoint dragPosition;
};


class FlagLayout: public QLayout
{
    Q_OBJECT

public:
    enum Position
    {
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    FlagLayout(QWidget* parent, int margin = 0, int spacing = -1);
    FlagLayout(int spacing = -1);
    ~FlagLayout() override;

    void addItem(QLayoutItem* item) override;
    void addWidget(QWidget* widget, Position position);
    Qt::Orientations expandingDirections() const override;
    bool hasHeightForWidth() const override;
    int count() const override;
    QLayoutItem* itemAt(int index) const override;
    QSize minimumSize() const override;
    void setGeometry(const QRect& rect) override;
    QSize sizeHint() const override;
    QLayoutItem* takeAt(int index) override;

    void add(QLayoutItem* item, Position position);

private:
    struct ItemWrapper
    {
        ItemWrapper(QLayoutItem* i, Position p)
        {
            item = i;
            position = p;
        }

        QLayoutItem* item;
        Position position;
    };

    enum SizeType
    {
        MinimumSize,
        SizeHint
    };
    QSize calculateSize(SizeType sizeType) const;

    QList<ItemWrapper*> list;
};

class GuiExport GLFlagWindow: public Gui::GLGraphicsItem
{
    TYPESYSTEM_HEADER_WITH_OVERRIDE();

public:
    GLFlagWindow(View3DInventorViewer*);
    ~GLFlagWindow() override;
    void addFlag(Flag* item, FlagLayout::Position pos);
    void removeFlag(Flag* item);
    void deleteFlags();
    Flag* getFlag(int) const;
    int countFlags() const;

    void paintGL() override;

private:
    View3DInventorViewer* _viewer;
    FlagLayout* _flagLayout;
};

}  // namespace Gui
