// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2024 Florian Foinant-Willig <ffw@2f2v.fr>
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


#include <App/Document.h>
#include <App/SuppressibleExtension.h>

#include "ActionFunction.h"
#include "Control.h"
#include "Document.h"

#include "Application.h"
#include "TreeItemMode.h"

#include "ViewProviderSuppressibleExtension.h"
#include "BitmapFactory.h"
#include "ViewProviderDocumentObject.h"
#include "qmenu.h"


using namespace Gui;

EXTENSION_PROPERTY_SOURCE(Gui::ViewProviderSuppressibleExtension, Gui::ViewProviderExtension)

ViewProviderSuppressibleExtension::ViewProviderSuppressibleExtension()
{
    initExtensionType(ViewProviderSuppressibleExtension::getExtensionClassTypeId());
}

ViewProviderSuppressibleExtension::~ViewProviderSuppressibleExtension() = default;

void ViewProviderSuppressibleExtension::extensionUpdateData(const App::Property* prop)
{
    auto vp = getExtendedViewProvider();
    auto owner = vp->getObject();
    if (!owner || !owner->isValid()) {
        return;
    }

    auto ext = owner->getExtensionByType<App::SuppressibleExtension>();

    if (ext && prop == &ext->Suppressed) {
        // update the tree item
        bool suppressed = ext->Suppressed.getValue();
        setSuppressedIcon(suppressed);
        getExtendedViewProvider()->signalChangeHighlight(suppressed, Gui::HighlightMode::StrikeOut);
    }
}

void ViewProviderSuppressibleExtension::setSuppressedIcon(bool onoff)
{
    isSetSuppressedIcon = onoff;

    getExtendedViewProvider()->signalChangeIcon();  // signal icon change
}

QIcon ViewProviderSuppressibleExtension::extensionMergeColorfullOverlayIcons(const QIcon& orig) const
{
    QIcon mergedicon = orig;

    if (isSetSuppressedIcon) {
        static QPixmap px(Gui::BitmapFactory().pixmapFromSvg("feature_suppressed", QSize(16, 16)));

        mergedicon
            = Gui::BitmapFactoryInst::mergePixmap(mergedicon, px, Gui::BitmapFactoryInst::TopLeft);
    }
    return Gui::ViewProviderExtension::extensionMergeColorfullOverlayIcons(mergedicon);
}


void ViewProviderSuppressibleExtension::extensionSetupContextMenu(QMenu* menu, QObject*, const char*)
{
    auto vp = getExtendedViewProvider();
    auto obj = vp->getObject()->getExtensionByType<App::SuppressibleExtension>();
    // Show Suppressed toggle action if the Suppressed property is visible
    if (obj && !obj->Suppressed.testStatus(App::Property::Hidden)) {
        Gui::ActionFunction* func = new Gui::ActionFunction(menu);
        QAction* act = menu->addAction(QObject::tr("Suppressed"));
        act->setCheckable(true);
        act->setChecked(obj->Suppressed.getValue());
        func->trigger(act, [obj]() { obj->Suppressed.setValue(!obj->Suppressed.getValue()); });
    }
}


namespace Gui
{
EXTENSION_PROPERTY_SOURCE_TEMPLATE(
    Gui::ViewProviderSuppressibleExtensionPython,
    Gui::ViewProviderSuppressibleExtension
)

// explicit template instantiation
template class GuiExport ViewProviderExtensionPythonT<ViewProviderSuppressibleExtension>;

}  // namespace Gui
