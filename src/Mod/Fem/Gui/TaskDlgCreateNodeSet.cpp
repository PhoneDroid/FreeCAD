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


#include <Base/Console.h>
#include <Base/Exception.h>
#include <Gui/Application.h>
#include <Gui/Command.h>
#include <Gui/Document.h>

#include "TaskDlgCreateNodeSet.h"
#include "ViewProviderFemMesh.h"


using namespace FemGui;


//**************************************************************************
//**************************************************************************
// TaskDialog
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TaskDlgCreateNodeSet::TaskDlgCreateNodeSet(Fem::FemSetNodesObject* obj)
    : TaskDialog()
    , FemSetNodesObject(obj)
{
    name = new TaskObjectName(obj);
    param = new TaskCreateNodeSet(obj);

    Content.push_back(name);
    Content.push_back(param);
}

TaskDlgCreateNodeSet::~TaskDlgCreateNodeSet() = default;

//==== calls from the TaskView ===============================================================


void TaskDlgCreateNodeSet::open()
{
    // select->activate();
    // Edge2TaskObject->execute();
    // param->setEdgeAndClusterNbr(Edge2TaskObject->NbrOfEdges,Edge2TaskObject->NbrOfCluster);
}

bool TaskDlgCreateNodeSet::accept()
{
    try {
        FemSetNodesObject->Nodes.setValues(param->tempSet);
        FemSetNodesObject->recomputeFeature();
        // Gui::Document* doc = Gui::Application::Instance->activeDocument();
        // if(doc)
        //     doc->resetEdit();
        param->MeshViewProvider->resetHighlightNodes();
        FemSetNodesObject->Label.setValue(name->name);
        Gui::Command::doCommand(Gui::Command::Gui, "Gui.activeDocument().resetEdit()");

        return true;
    }
    catch (const Base::Exception& e) {
        Base::Console().warning("TaskDlgCreateNodeSet::accept(): %s\n", e.what());
    }

    return false;
}

bool TaskDlgCreateNodeSet::reject()
{
    FemSetNodesObject->execute();
    // Gui::Document* doc = Gui::Application::Instance->activeDocument();
    // if(doc)
    //     doc->resetEdit();
    param->MeshViewProvider->resetHighlightNodes();
    Gui::Command::abortCommand();
    Gui::Command::doCommand(Gui::Command::Gui, "Gui.activeDocument().resetEdit()");

    return true;
}

void TaskDlgCreateNodeSet::helpRequested()
{}

#include "moc_TaskDlgCreateNodeSet.cpp"
