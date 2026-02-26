// SPDX-FileCopyrightText: 2010 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <map>
#include <vector>
#include <Base/Type.h>


class SoNode;

namespace App
{
class Property;
}

namespace Gui
{

class ViewProvider;
class SoFCSelection;
class GuiExport ViewProviderBuilder
{
public:
    /// Constructor
    ViewProviderBuilder();
    virtual ~ViewProviderBuilder();
    virtual void buildNodes(const App::Property*, std::vector<SoNode*>&) const = 0;

    static void add(const Base::Type&, const Base::Type&);
    static ViewProvider* create(const Base::Type&);
    static SoFCSelection* createSelection();

private:
    static std::map<Base::Type, Base::Type> _prop_to_view;
};

class GuiExport ViewProviderColorBuilder: public ViewProviderBuilder
{
public:
    /// Constructor
    ViewProviderColorBuilder();
    ~ViewProviderColorBuilder() override;
    void buildNodes(const App::Property*, std::vector<SoNode*>&) const override;
};

}  // namespace Gui
