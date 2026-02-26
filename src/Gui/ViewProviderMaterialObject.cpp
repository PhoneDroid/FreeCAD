// SPDX-FileCopyrightText: 2013 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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


#include <QApplication>
#include <QStyle>


#include "ViewProviderMaterialObject.h"
#include "Application.h"
#include "Document.h"


using namespace Gui;


PROPERTY_SOURCE(Gui::ViewProviderMaterialObject, Gui::ViewProviderDocumentObject)


/**
 * Creates the view provider for an object group.
 */
ViewProviderMaterialObject::ViewProviderMaterialObject() = default;

ViewProviderMaterialObject::~ViewProviderMaterialObject() = default;

bool ViewProviderMaterialObject::doubleClicked()
{
    Gui::Application::Instance->activeDocument()->setEdit(this, (int)ViewProvider::Default);
    return true;
}

/**
 * Returns the pixmap for the list item.
 */
QIcon ViewProviderMaterialObject::getIcon() const
{
    QIcon groupIcon;
    groupIcon.addPixmap(
        QApplication::style()->standardPixmap(QStyle::SP_DirClosedIcon),
        QIcon::Normal,
        QIcon::Off
    );
    groupIcon.addPixmap(
        QApplication::style()->standardPixmap(QStyle::SP_DirOpenIcon),
        QIcon::Normal,
        QIcon::On
    );
    return groupIcon;
}


// Python feature -----------------------------------------------------------------------

namespace Gui
{
/// @cond DOXERR
PROPERTY_SOURCE_TEMPLATE(Gui::ViewProviderMaterialObjectPython, Gui::ViewProviderMaterialObject)
/// @endcond

// explicit template instantiation
template class GuiExport ViewProviderFeaturePythonT<ViewProviderMaterialObject>;
}  // namespace Gui
