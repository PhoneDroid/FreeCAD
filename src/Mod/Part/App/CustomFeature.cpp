// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2008 Werner Mayer <wmayer@users.sourceforge.net>
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


#include "CustomFeature.h"


using namespace Part;


PROPERTY_SOURCE(Part::CustomFeature, Part::Feature)


CustomFeature::CustomFeature() = default;

CustomFeature::~CustomFeature() = default;

short CustomFeature::mustExecute() const
{
    return Part::Feature::mustExecute();
}

App::DocumentObjectExecReturn* CustomFeature::execute()
{
    return App::DocumentObject::StdReturn;
}

// ---------------------------------------------------------

namespace App
{
/// @cond DOXERR
PROPERTY_SOURCE_TEMPLATE(Part::CustomFeaturePython, Part::CustomFeature)
template<>
const char* Part::CustomFeaturePython::getViewProviderName() const
{
    return "PartGui::ViewProviderCustomPython";
}
/// @endcond

// explicit template instantiation
template class PartExport FeaturePythonT<Part::CustomFeature>;
}  // namespace App
