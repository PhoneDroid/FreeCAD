// SPDX-FileCopyrightText: 2015 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Gui/SyntaxHighlighter.h>

namespace FemGui
{

/**
 * Syntax highlighter for Abaqus.
 * @author Werner Mayer
 */
class AbaqusHighlighter: public Gui::SyntaxHighlighter
{
public:
    explicit AbaqusHighlighter(QObject* parent);
    ~AbaqusHighlighter() override;

protected:
    void highlightBlock(const QString& text) override;
};

}  // namespace FemGui
