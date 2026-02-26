// SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
// SPDX-FileCopyrightText: 2015 Alexander Golubev <fatzer2@gmail.com>
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


#include "ViewProviderDocumentObject.h"
#include "ViewProviderGeoFeatureGroupExtension.h"
#include "ViewProviderFeaturePython.h"

namespace Gui
{

class GuiExport ViewProviderGeoFeatureGroup: public ViewProviderDocumentObject,
                                             public ViewProviderGeoFeatureGroupExtension
{
    PROPERTY_HEADER_WITH_EXTENSIONS(Gui::ViewProviderGeoFeatureGroup);

public:
    /// constructor.
    ViewProviderGeoFeatureGroup();
    /// destructor.
    ~ViewProviderGeoFeatureGroup() override;
};

using ViewProviderGeoFeatureGroupPython = ViewProviderFeaturePythonT<ViewProviderGeoFeatureGroup>;

}  // namespace Gui
