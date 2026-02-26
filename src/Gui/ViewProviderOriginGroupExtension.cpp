// SPDX-FileCopyrightText: 2015 Alexander Golubev <fatzer2@gmail.com>
// SPDX-FileCopyrightText: 2016 Stefan Tröger <stefantroeger@gmx.net>
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


#include <Inventor/actions/SoGetBoundingBoxAction.h>
#include <Inventor/nodes/SoSeparator.h>


#include <App/Document.h>
#include <App/Origin.h>
#include <App/OriginGroupExtension.h>
#include <Base/Console.h>

#include "ViewProviderOriginGroupExtension.h"
#include "Application.h"
#include "Document.h"
#include "View3DInventor.h"
#include "View3DInventorViewer.h"
#include "ViewProviderCoordinateSystem.h"
#include "ViewProviderDatum.h"


using namespace Gui;
namespace sp = std::placeholders;


EXTENSION_PROPERTY_SOURCE(Gui::ViewProviderOriginGroupExtension, Gui::ViewProviderGeoFeatureGroupExtension)

ViewProviderOriginGroupExtension::ViewProviderOriginGroupExtension()
{
    initExtensionType(ViewProviderOriginGroupExtension::getExtensionClassTypeId());
}

ViewProviderOriginGroupExtension::~ViewProviderOriginGroupExtension()
{}

std::vector<App::DocumentObject*> ViewProviderOriginGroupExtension::constructChildren(
    const std::vector<App::DocumentObject*>& children
) const
{
    auto* obj = getExtendedViewProvider()->getObject();
    auto* group = obj ? obj->getExtensionByType<App::OriginGroupExtension>() : nullptr;
    if (!group) {
        return children;
    }

    App::DocumentObject* originObj = group->Origin.getValue();

    // Origin must be first
    if (originObj) {
        std::vector<App::DocumentObject*> rv;
        rv.push_back(originObj);
        std::copy(children.begin(), children.end(), std::back_inserter(rv));
        return rv;
    }
    else {  // Generally shouldn't happen but must be handled in case origin is lost
        return children;
    }
}


std::vector<App::DocumentObject*> ViewProviderOriginGroupExtension::extensionClaimChildren() const
{
    return constructChildren(ViewProviderGeoFeatureGroupExtension::extensionClaimChildren());
}

std::vector<App::DocumentObject*> ViewProviderOriginGroupExtension::extensionClaimChildren3D() const
{
    return constructChildren(ViewProviderGeoFeatureGroupExtension::extensionClaimChildren3D());
}


namespace Gui
{
EXTENSION_PROPERTY_SOURCE_TEMPLATE(
    Gui::ViewProviderOriginGroupExtensionPython,
    Gui::ViewProviderOriginGroupExtension
)

// explicit template instantiation
template class GuiExport ViewProviderExtensionPythonT<ViewProviderOriginGroupExtension>;
}  // namespace Gui
