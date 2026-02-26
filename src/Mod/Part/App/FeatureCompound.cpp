// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2013 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <BRep_Builder.hxx>
#include <Standard_Failure.hxx>
#include <TopoDS_Compound.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>


#include "FeatureCompound.h"


using namespace Part;

PROPERTY_SOURCE(Part::Compound, Part::Feature)

Compound::Compound()
{
    ADD_PROPERTY(Links, (nullptr));
    Links.setSize(0);
}

Compound::~Compound() = default;

short Compound::mustExecute() const
{
    if (Links.isTouched()) {
        return 1;
    }
    return 0;
}

App::DocumentObjectExecReturn* Compound::execute()
{
    try {
        // avoid duplicates without changing the order
        // See also ViewProviderCompound::updateData
        std::set<DocumentObject*> tempLinks;

        std::vector<TopoShape> shapes;
        for (auto obj : Links.getValues()) {
            if (!tempLinks.insert(obj).second) {
                continue;
            }
            auto sh = Feature::getTopoShape(obj, ShapeOption::ResolveLink | ShapeOption::Transform);
            if (!sh.isNull()) {
                shapes.push_back(sh);
            }
        }
        this->Shape.setValue(TopoShape().makeElementCompound(shapes));
        if (Links.getSize() > 0) {
            App::DocumentObject* link = Links.getValues()[0];
            copyMaterial(link);
        }
        return Part::Feature::execute();
    }
    catch (Standard_Failure& e) {
        return new App::DocumentObjectExecReturn(e.GetMessageString());
    }
}

////////////////////////////////////////////////////////////////////////

PROPERTY_SOURCE(Part::Compound2, Part::Compound)

Compound2::Compound2()
{
    Shape.setStatus(App::Property::Transient, true);
}

void Compound2::onDocumentRestored()
{
    Base::Placement pla = Placement.getValue();
    auto res = execute();
    delete res;
    Placement.setValue(pla);
}
