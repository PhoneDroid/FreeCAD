// SPDX-FileCopyrightText: 2022 Zheng Lei <realthunder.dev@gmail.com>
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

#include <map>
#include <string>
#include <Gui/Selection/Selection.h>

class SoGroup;
class SoNode;
class SoSeparator;

namespace Gui
{

class Document;
class SoFCUnifiedSelection;

class GuiExport View3DInventorSelection
{
public:
    View3DInventorSelection(SoFCUnifiedSelection* root);
    ~View3DInventorSelection();

    void setDocument(Gui::Document* pcDocument)
    {
        guiDocument = pcDocument;
    }
    Gui::Document* getDocument() const
    {
        return guiDocument;
    }

    void checkGroupOnTop(const SelectionChanges& Reason);
    void clearGroupOnTop();

private:
    SoGroup* pcGroupOnTop;
    SoGroup* pcGroupOnTopSel;
    SoGroup* pcGroupOnTopPreSel;
    SoFCUnifiedSelection* selectionRoot;
    std::map<std::string, SoNode*> objectsOnTop;
    std::map<std::string, SoNode*> objectsOnTopPreSel;
    Gui::Document* guiDocument = nullptr;
};

}  // namespace Gui
