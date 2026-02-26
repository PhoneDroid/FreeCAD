// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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


#include <QAction>
#include <QMenu>


#include <Mod/PartDesign/App/FeatureHelix.h>
#include <Gui/BitmapFactory.h>

#include <Gui/Application.h>
#include <Mod/Sketcher/App/SketchObject.h>

#include "TaskHelixParameters.h"
#include "ViewProviderHelix.h"

using namespace PartDesignGui;

PROPERTY_SOURCE(PartDesignGui::ViewProviderHelix, PartDesignGui::ViewProvider)


ViewProviderHelix::ViewProviderHelix() = default;

ViewProviderHelix::~ViewProviderHelix() = default;

void ViewProviderHelix::setupContextMenu(QMenu* menu, QObject* receiver, const char* member)
{
    addDefaultAction(menu, QObject::tr("Edit Helix"));
    ViewProvider::setupContextMenu(menu, receiver, member);
}

TaskDlgFeatureParameters* ViewProviderHelix::getEditDialog()
{
    return new TaskDlgHelixParameters(this);
}

QIcon ViewProviderHelix::getIcon() const
{
    QString str = QStringLiteral("PartDesign_");
    auto* prim = getObject<PartDesign::Helix>();
    if (prim->getAddSubType() == PartDesign::FeatureAddSub::Additive) {
        str += QStringLiteral("Additive");
    }
    else {
        str += QStringLiteral("Subtractive");
    }

    str += QStringLiteral("Helix.svg");
    return PartDesignGui::ViewProvider::mergeGreyableOverlayIcons(
        Gui::BitmapFactory().pixmap(str.toStdString().c_str())
    );
}

std::vector<App::DocumentObject*> ViewProviderHelix::claimChildren() const
{
    std::vector<App::DocumentObject*> temp;
    App::DocumentObject* sketch = getObject<PartDesign::ProfileBased>()->Profile.getValue();
    if (sketch && sketch->isDerivedFrom<Part::Part2DObject>()) {
        temp.push_back(sketch);
    }

    return temp;
}
