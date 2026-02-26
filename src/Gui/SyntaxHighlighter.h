// SPDX-FileCopyrightText: 2008 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QSyntaxHighlighter>
#include <FCGlobal.h>

namespace Gui
{
class SyntaxHighlighterP;
class TextEditor;

/**
 * Abstract Syntax highlighter.
 * @author Werner Mayer
 */
class GuiExport SyntaxHighlighter: public QSyntaxHighlighter
{
public:
    SyntaxHighlighter(QObject* parent);
    ~SyntaxHighlighter() override;

    int maximumUserState() const;

    void setColor(const QString& type, const QColor& col);
    QColor color(const QString& type);

protected:
    virtual void colorChanged(const QString& type, const QColor& col);

protected:
    enum TColor
    {
        Text = 0,
        Comment = 1,
        BlockComment = 2,
        Number = 3,
        String = 4,
        Keyword = 5,
        Classname = 6,
        Defname = 7,
        Operator = 8,
        Output = 9,
        Error = 10
    };

    QColor colorByType(TColor type);


private:
    SyntaxHighlighterP* d;
};

}  // namespace Gui
