// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2017 Peter Lama <peterldev94@gmail.com>
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

#include <Gui/propertyeditor/PropertyItem.h>

#include <Mod/Part/PartGlobal.h>

#include "TaskAttacher.h"

namespace PartGui
{

using FrameOption = Gui::PropertyEditor::FrameOption;

/**
 * Custom editor item for PropertyEnumeration to open Attacher task
 */
class PartGuiExport PropertyEnumAttacherItem: public Gui::PropertyEditor::PropertyEnumItem
{
    Q_OBJECT

public:
    PROPERTYITEM_HEADER

    QWidget* createEditor(
        QWidget* parent,
        const std::function<void()>& method,
        FrameOption frameOption
    ) const override;
    void setEditorData(QWidget* editor, const QVariant& data) const override;
    QVariant editorData(QWidget* editor) const override;

protected Q_SLOTS:
    void openTask();

protected:
    PropertyEnumAttacherItem();
};

}  // namespace PartGui
