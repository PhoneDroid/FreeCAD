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


#include "FeatureMeshTransformDemolding.h"


using namespace Mesh;
using namespace MeshCore;

PROPERTY_SOURCE(Mesh::TransformDemolding, Mesh::Transform)


TransformDemolding::TransformDemolding()
{
    ADD_PROPERTY(Source, (nullptr));
    ADD_PROPERTY(Rotation, (0.0));
    ADD_PROPERTY(Axis, (0.0, 0.0, 1.0));
}

App::DocumentObjectExecReturn* TransformDemolding::execute()
{ /*
  Feature *pcFirst  = freecad_cast<Feature*>(Source.getValue());
  if (!pcFirst || pcFirst->isError())
      return new App::DocumentObjectExecReturn("Unknown Error");

  MeshCore::MeshKernel* pcKernel = new MeshCore::MeshKernel(pcFirst->Mesh.getValue()); // Result
  Meshkernel Base::Matrix4D trans(Base::Vector3f(0, 0, 0), Axis.getValue(), Rotation.getValue());
  //Matrix4D trans;
  //trans.rotLine(Axis.getValue(), Rotation.getValue());
  pcKernel->Transform(trans);
  Mesh.setValue(pcKernel);
 */
    return App::DocumentObject::StdReturn;
}
