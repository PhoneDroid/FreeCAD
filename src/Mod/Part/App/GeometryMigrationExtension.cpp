// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2020 Abdullah Tahiri <abdullah.tahiri.yo@gmail.com>
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


#include <Base/Exception.h>

#include "GeometryMigrationExtension.h"


using namespace Part;

TYPESYSTEM_SOURCE_ABSTRACT(Part::GeometryMigrationPersistenceExtension, Part::GeometryPersistenceExtension)

//---------- Geometry Extension
TYPESYSTEM_SOURCE(Part::GeometryMigrationExtension, Part::GeometryExtension)


void GeometryMigrationExtension::copyAttributes(Part::GeometryExtension* cpy) const
{
    Part::GeometryExtension::copyAttributes(cpy);
    static_cast<GeometryMigrationExtension*>(cpy)->ConstructionState = this->ConstructionState;
    static_cast<GeometryMigrationExtension*>(cpy)->GeometryMigrationFlags = this->GeometryMigrationFlags;

    static_cast<GeometryMigrationExtension*>(cpy)->Id = this->Id;
    static_cast<GeometryMigrationExtension*>(cpy)->Flags = this->Flags;
    static_cast<GeometryMigrationExtension*>(cpy)->Ref = this->Ref;
    static_cast<GeometryMigrationExtension*>(cpy)->RefIndex = this->RefIndex;
}

std::unique_ptr<Part::GeometryExtension> GeometryMigrationExtension::copy() const
{
    auto cpy = std::make_unique<GeometryMigrationExtension>();

    copyAttributes(cpy.get());

    return cpy;
}

PyObject* GeometryMigrationExtension::getPyObject()
{
    THROWM(Base::NotImplementedError, "GeometryMigrationExtension does not have a Python counterpart");
}
