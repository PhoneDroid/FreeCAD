// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2022 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <tuple>
#include <Mod/PartDesign/PartDesignGlobal.h>
#include <Gui/Selection/SelectionFilter.h>

namespace App
{
class Document;
class DocumentObject;
class GeoFeatureGroupExtension;
}  // namespace App
namespace Gui
{
class Document;
}
namespace PartDesign
{
class Body;
}
namespace PartDesignGui
{

class SketchWorkflow
{
public:
    explicit SketchWorkflow(Gui::Document*);
    void createSketch();

private:
    void tryCreateSketch();
    std::tuple<bool, PartDesign::Body*> shouldCreateBody();
    bool shouldAbort(bool) const;
    std::tuple<Gui::SelectionFilter, Gui::SelectionFilter, Gui::SelectionFilter> getFilters() const;

private:
    Gui::Document* guidocument;
    App::Document* appdocument;
    PartDesign::Body* activeBody {nullptr};
};

}  // namespace PartDesignGui
