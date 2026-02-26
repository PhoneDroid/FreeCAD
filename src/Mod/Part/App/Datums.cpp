// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2024 Ondsel (PL Boyer) <development@ondsel.com>
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


#include "Datums.h"


using namespace Part;
using namespace Attacher;

PROPERTY_SOURCE_WITH_EXTENSIONS(Part::DatumPlane, App::Plane)

Part::DatumPlane::DatumPlane()
{
    AttachExtension::initExtension(this);
    this->setAttacher(new AttachEnginePlane);
}


PROPERTY_SOURCE_WITH_EXTENSIONS(Part::DatumLine, App::Line)

Part::DatumLine::DatumLine()
{
    setBaseDirection(Base::Vector3d(0, 0, 1));
    AttachExtension::initExtension(this);
    this->setAttacher(new AttachEngineLine);
}


PROPERTY_SOURCE_WITH_EXTENSIONS(Part::DatumPoint, App::Point)

Part::DatumPoint::DatumPoint()
{
    AttachExtension::initExtension(this);
    this->setAttacher(new AttachEnginePoint);
}


PROPERTY_SOURCE_WITH_EXTENSIONS(Part::LocalCoordinateSystem, App::LocalCoordinateSystem)

Part::LocalCoordinateSystem::LocalCoordinateSystem()
{
    AttachExtension::initExtension(this);
}
