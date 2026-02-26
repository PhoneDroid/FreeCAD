// SPDX-FileCopyrightText: 2018 Torsten Sadowski <tsadowski@gmx.net>
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

#include "GuiAbstractNativeEvent.h"

class QMainWindow;

namespace Gui
{
class GUIApplicationNativeEventAware;

class GuiNativeEvent: public GuiAbstractNativeEvent
{
    Q_OBJECT
public:
    GuiNativeEvent(GUIApplicationNativeEventAware* app);
    ~GuiNativeEvent() override;
    void initSpaceball(QMainWindow* window) override final;

private:
    GuiNativeEvent();
    GuiNativeEvent(const GuiNativeEvent&);
    GuiNativeEvent& operator=(const GuiNativeEvent&);
private Q_SLOTS:
    void pollSpacenav();
};
}  // namespace Gui
