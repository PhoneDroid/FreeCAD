// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2005 Werner Mayer <wmayer@users.sourceforge.net>
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


#include "FeatureMeshImport.h"


using namespace Mesh;
using namespace MeshCore;

PROPERTY_SOURCE(Mesh::Import, Mesh::Feature)


Mesh::Import::Import()
{
    ADD_PROPERTY(FileName, (""));
}

short Mesh::Import::mustExecute() const
{
    if (FileName.isTouched()) {
        return 1;
    }
    return 0;
}

App::DocumentObjectExecReturn* Mesh::Import::execute()
{
    std::unique_ptr<MeshObject> apcKernel(new MeshObject());
    apcKernel->load(FileName.getValue());
    Mesh.setValuePtr(apcKernel.release());

    return App::DocumentObject::StdReturn;
}
