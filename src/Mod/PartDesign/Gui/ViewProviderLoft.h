// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2015 Stefan Tröger <stefantroeger@gmx.net>
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

class PartDesignGuiExport ViewProviderLoft: public ViewProvider
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesignGui::ViewProviderLoft);

public:
    enum Reference
    {
        Profile,
        Section,
        Both
    };

    /// constructor
    ViewProviderLoft();
    /// destructor
    ~ViewProviderLoft() override;

    /// grouping handling
    std::vector<App::DocumentObject*> claimChildren() const override;
    void setupContextMenu(QMenu*, QObject*, const char*) override;

    void highlightProfile(bool on);
    void highlightSection(bool on);
    void highlightReferences(Reference mode, bool on);

protected:
    QIcon getIcon() const override;
    TaskDlgFeatureParameters* getEditDialog() override;

private:
    void highlightReferences(Part::Feature*, const std::vector<std::string>&, bool);

private:
    std::map<long, std::vector<Base::Color>> originalLineColors;
};


}  // namespace PartDesignGui
