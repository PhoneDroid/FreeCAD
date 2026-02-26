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


#include <SMESH_Mesh.hxx>


#include <App/FeaturePythonPyImp.h>
#include <App/GeoFeaturePy.h>
#include <Mod/Part/App/PartFeature.h>

#include "FemMesh.h"
#include "FemMeshShapeObject.h"


using namespace Fem;
using namespace App;

PROPERTY_SOURCE(Fem::FemMeshShapeBaseObject, Fem::FemMeshObject)

FemMeshShapeBaseObject::FemMeshShapeBaseObject()
{
    ADD_PROPERTY_TYPE(
        Shape,
        (nullptr),
        "FEM Mesh",
        Prop_None,
        "Geometry object, the mesh is made from. The geometry object has to have a Shape."
    );
    ADD_PROPERTY_TYPE(
        Tool,
        (Py::Object()),
        "FEM Mesh",
        App::PropertyType(
            App::Prop_Transient | App::Prop_Hidden | App::Prop_ReadOnly | App::Prop_Output
        ),
        "Tool object for run the mesher"
    );
    ADD_PROPERTY_TYPE(
        WorkingDirectory,
        (""),
        "FEM Mesh",
        App::PropertyType(App::Prop_Transient | App::Prop_Hidden | App::Prop_Output),
        "Mesher working directory"
    );

    Shape.setScope(LinkScope::Global);
}

FemMeshShapeBaseObject::~FemMeshShapeBaseObject() = default;

// ------------------------------------------------------------------------

PROPERTY_SOURCE(Fem::FemMeshShapeObject, Fem::FemMeshShapeBaseObject)

FemMeshShapeObject::FemMeshShapeObject() = default;

FemMeshShapeObject::~FemMeshShapeObject() = default;

App::DocumentObjectExecReturn* FemMeshShapeObject::execute()
{
    Fem::FemMesh newMesh;

    Part::Feature* feat = Shape.getValue<Part::Feature*>();
    TopoDS_Shape shape = feat->Shape.getValue();

    newMesh.getSMesh()->ShapeToMesh(shape);
    newMesh.setStandardHypotheses();

    newMesh.compute();

    // set the value to the object
    FemMesh.setValue(newMesh);

    return App::DocumentObject::StdReturn;
}

// Python feature ---------------------------------------------------------

namespace App
{

PROPERTY_SOURCE_TEMPLATE(Fem::FemMeshShapeBaseObjectPython, Fem::FemMeshShapeBaseObject)

template<>
const char* Fem::FemMeshShapeBaseObjectPython::getViewProviderName() const
{
    return "FemGui::ViewProviderFemMeshShapeBasePython";
}

template<>
PyObject* Fem::FemMeshShapeBaseObjectPython::getPyObject()
{
    if (PythonObject.is(Py::_None())) {
        // ref counter is set to 1
        PythonObject = Py::asObject(new App::FeaturePythonPyT<App::GeoFeaturePy>(this));
    }
    return Py::new_reference_to(PythonObject);
}

// explicit template instantiation
template class FemExport FeaturePythonT<Fem::FemMeshShapeBaseObject>;

}  // namespace App
