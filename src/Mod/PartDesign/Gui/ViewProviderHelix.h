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


#pragma once

#include "ViewProvider.h"


namespace PartDesignGui
{

class PartDesignGuiExport ViewProviderHelix: public ViewProvider
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesignGui::ViewProviderHelix);

public:
    /// constructor
    ViewProviderHelix();
    /// destructor
    ~ViewProviderHelix() override;

    void setupContextMenu(QMenu*, QObject*, const char*) override;

    /// grouping handling
    std::vector<App::DocumentObject*> claimChildren() const override;

protected:
    QIcon getIcon() const override;

    /// Returns a newly created TaskDlgHelixParameters
    TaskDlgFeatureParameters* getEditDialog() override;
};


}  // namespace PartDesignGui
