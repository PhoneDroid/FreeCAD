// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2021 Werner Mayer <wmayer@users.sourceforge.net>
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

namespace App
{
class Document;
class Color;
}  // namespace App

namespace MeshCore
{
struct Material;
}
namespace Mesh
{
class MeshObject;
class Feature;

class Importer
{
public:
    explicit Importer(App::Document*);
    void load(const std::string& fileName);

private:
    void addVertexColors(Feature*, const std::vector<Base::Color>&);
    void addFaceColors(Feature*, const std::vector<Base::Color>&);
    void addColors(Feature*, const std::string& property, const std::vector<Base::Color>&);
    Feature* createMesh(const std::string& name, MeshObject&);
    void createMeshFromSegments(const std::string& name, MeshCore::Material& mat, MeshObject& mesh);

private:
    App::Document* document;
};

}  // namespace Mesh
