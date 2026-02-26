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

#pragma once

#include <App/Datums.h>

#include <Mod/Part/PartGlobal.h>

#include "AttachExtension.h"

namespace Part
{

class PartExport DatumPlane: public App::Plane, public AttachExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(Part::DatumPlane);

public:
    DatumPlane();
    ~DatumPlane() override = default;
    const char* getViewProviderName() const override
    {
        return "PartGui::ViewProviderPlane";
    }
};

class PartExport DatumLine: public App::Line, public AttachExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(Part::DatumLine);

public:
    DatumLine();
    ~DatumLine() override = default;
    const char* getViewProviderName() const override
    {
        return "PartGui::ViewProviderLine";
    }
};

class PartExport DatumPoint: public App::Point, public AttachExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(Part::DatumPoint);

public:
    DatumPoint();
    ~DatumPoint() override = default;
    const char* getViewProviderName() const override
    {
        return "PartGui::ViewProviderPoint";
    }
};

class PartExport LocalCoordinateSystem: public App::LocalCoordinateSystem, public AttachExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(Part::LocalCoordinateSystem);

public:
    LocalCoordinateSystem();
    ~LocalCoordinateSystem() override = default;
    const char* getViewProviderName() const override
    {
        return "PartGui::ViewProviderLCS";
    }
};

}  // namespace Part
