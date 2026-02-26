// SPDX-FileCopyrightText: 2019 WandererFan <wandererfan@gmail.com>
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

# include <cmath>

#include <Mod/TechDraw/App/CosmeticExtension.h>
#include "ViewProviderCosmeticExtension.h"

using namespace TechDrawGui;

EXTENSION_PROPERTY_SOURCE(TechDrawGui::ViewProviderCosmeticExtension, Gui::ViewProviderExtension)


ViewProviderCosmeticExtension::ViewProviderCosmeticExtension()
{
    initExtensionType(ViewProviderCosmeticExtension::getExtensionClassTypeId());
}

QIcon ViewProviderCosmeticExtension::extensionMergeGreyableOverlayIcons(const QIcon & orig) const
{
    QIcon mergedicon = orig;

    return mergedicon;
}

namespace Gui {
    EXTENSION_PROPERTY_SOURCE_TEMPLATE(TechDrawGui::ViewProviderCosmeticExtensionPython, TechDrawGui::ViewProviderCosmeticExtension)

// explicit template instantiation
    template class TechDrawGuiExport ViewProviderExtensionPythonT<TechDrawGui::ViewProviderCosmeticExtension>;
}
