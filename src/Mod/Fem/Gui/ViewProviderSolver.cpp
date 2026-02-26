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
#include <QMessageBox>
#include <QTextStream>


#include <Gui/Document.h>
#include <Gui/MainWindow.h>

#include "ViewProviderAnalysis.h"
#include "ViewProviderSolver.h"


using namespace FemGui;

PROPERTY_SOURCE(FemGui::ViewProviderSolver, Gui::ViewProviderDocumentObject)

ViewProviderSolver::ViewProviderSolver()
{
    setToggleVisibility(ToggleVisibilityMode::NoToggleVisibility);
    sPixmap = "FEM_SolverStandard";
}

ViewProviderSolver::~ViewProviderSolver() = default;

std::vector<std::string> ViewProviderSolver::getDisplayModes() const
{
    return {"Solver"};
}

bool ViewProviderSolver::onDelete(const std::vector<std::string>&)
{
    // warn the user if the object has unselected children
    auto objs = claimChildren();
    return ViewProviderFemAnalysis::checkSelectedChildren(objs, this->getDocument(), "solver");
}

bool ViewProviderSolver::canDelete(App::DocumentObject* obj) const
{
    // deletions of objects from a FemSolver don't necessarily destroy anything
    // thus we can pass this action
    // we can warn the user if necessary in the object's ViewProvider in the onDelete() function
    Q_UNUSED(obj)
    return true;
}


// Python feature -----------------------------------------------------------------------

namespace Gui
{
/// @cond DOXERR
PROPERTY_SOURCE_TEMPLATE(FemGui::ViewProviderSolverPython, FemGui::ViewProviderSolver)
/// @endcond

// explicit template instantiation
template class FemGuiExport ViewProviderFeaturePythonT<ViewProviderSolver>;
}  // namespace Gui
