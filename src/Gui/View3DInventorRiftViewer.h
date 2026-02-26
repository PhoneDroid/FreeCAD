// SPDX-FileCopyrightText: 2014 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#if BUILD_VR

# include "CoinRiftWidget.h"

namespace Gui
{

class View3DInventorRiftViewer: public CoinRiftWidget
{
public:
    View3DInventorRiftViewer();
    ~View3DInventorRiftViewer();

    virtual void setSceneGraph(SoNode* sceneGraph);

protected:
    SoGroup* workplace;
    SoTranslation* translation;
    SoRotationXYZ* rotation1;
    SoRotationXYZ* rotation2;
    SoScale* scale;

protected:
    void keyPressEvent(QKeyEvent*);
};


}  // namespace Gui

#endif  // BUILD_VR
