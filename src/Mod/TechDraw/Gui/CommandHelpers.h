// SPDX-License-Identifier: LGPL-2.0-or-later
// SPDX-FileCopyrightText: 2024 WandererFan <wandererfan@gmail.com>
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

#include <string>
#include <vector>

#include <Mod/TechDraw/TechDrawGlobal.h>
#include <Base/Vector3D.h>

namespace App {
class DocumentObject;
}

namespace Gui {
class Command;
}

namespace TechDraw {
class DrawView;
class DrawViewPart;

/**
 * CommandHelpers is a collection of methods for common actions in commands.
 */
namespace CommandHelpers {
TechDraw::DrawView* firstViewInSelection(Gui::Command* cmd);
TechDraw::DrawView* firstNonSpreadsheetInSelection(Gui::Command* cmd);

std::vector<std::string> getSelectedSubElements(Gui::Command* cmd,
                                                TechDraw::DrawViewPart* &dvp,
                                                std::string subType = "Edge");


std::pair<App::DocumentObject*, std::string> faceFromSelection();


}   // end namespace CommandHelpers
}   // end namespace TechDraw