// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2014 Yorik van Havre <yorik@uncreated.net>
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


#include <Gui/Application.h>
#include <Gui/BitmapFactory.h>
#include <Mod/CAM/App/FeaturePathShape.h>

#include "ViewProviderPathShape.h"


using namespace Gui;
using namespace PathGui;

PROPERTY_SOURCE(PathGui::ViewProviderPathShape, PathGui::ViewProviderPath)

QIcon ViewProviderPathShape::getIcon() const
{
    return Gui::BitmapFactory().pixmap("CAM_Shape");
}

std::vector<App::DocumentObject*> ViewProviderPathShape::claimChildren() const
{
    return std::vector<App::DocumentObject*>(getObject<Path::FeatureShape>()->Sources.getValues());
}

bool ViewProviderPathShape::canDragObjects() const
{
    return true;
}

bool ViewProviderPathShape::canDragObject(App::DocumentObject* obj) const
{
    return obj && obj->isDerivedFrom<Part::Feature>();
}

void ViewProviderPathShape::dragObject(App::DocumentObject* obj)
{
    Path::FeatureShape* feature = getObject<Path::FeatureShape>();
    std::vector<App::DocumentObject*> sources = feature->Sources.getValues();
    for (std::vector<App::DocumentObject*>::iterator it = sources.begin(); it != sources.end(); ++it) {
        if (*it == obj) {
            sources.erase(it);
            feature->Sources.setValues(sources);
            break;
        }
    }
}

bool ViewProviderPathShape::canDropObjects() const
{
    return true;
}

bool ViewProviderPathShape::canDropObject(App::DocumentObject* obj) const
{
    return canDragObject(obj);
}

void ViewProviderPathShape::dropObject(App::DocumentObject* obj)
{
    Path::FeatureShape* feature = getObject<Path::FeatureShape>();
    std::vector<App::DocumentObject*> sources = feature->Sources.getValues();
    sources.push_back(obj);
    feature->Sources.setValues(sources);
}

void ViewProviderPathShape::updateData(const App::Property* prop)
{
    PathGui::ViewProviderPath::updateData(prop);
    if (prop->isDerivedFrom<App::PropertyLinkList>()) {
        std::vector<App::DocumentObject*> pShapes
            = static_cast<const App::PropertyLinkList*>(prop)->getValues();
        for (std::vector<App::DocumentObject*>::iterator it = pShapes.begin(); it != pShapes.end();
             ++it) {
            if (*it) {
                Gui::Application::Instance->hideViewProvider(*it);
            }
        }
    }
}

bool ViewProviderPathShape::onDelete(const std::vector<std::string>&)
{
    // get the input shapes
    Path::FeatureShape* feature = getObject<Path::FeatureShape>();
    std::vector<App::DocumentObject*> pShapes = feature->Sources.getValues();
    for (std::vector<App::DocumentObject*>::iterator it = pShapes.begin(); it != pShapes.end(); ++it) {
        if (*it) {
            Gui::Application::Instance->showViewProvider(*it);
        }
    }
    return true;
}
