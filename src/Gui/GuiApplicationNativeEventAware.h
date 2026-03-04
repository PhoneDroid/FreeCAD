// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2010 Thomas Anderson <ta@nextgenengineering>
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

#include <QApplication>
#include <vector>


class QMainWindow;

namespace Gui
{
#if defined(_USE_3DCONNEXION_SDK) || defined(SPNAV_FOUND)
class GuiNativeEvent;
#endif  // Spacemice
class GUIApplicationNativeEventAware: public QApplication
{
    Q_OBJECT
public:
    GUIApplicationNativeEventAware(int& argc, char* argv[]);
    ~GUIApplicationNativeEventAware() override;
    void initSpaceball(QMainWindow* window);
    bool isSpaceballPresent() const
    {
        return spaceballPresent;
    }
    void setSpaceballPresent(bool present)
    {
        spaceballPresent = present;
    }
    bool processSpaceballEvent(QObject* object, QEvent* event);
    void postMotionEvent(std::vector<int> motionDataArray);
    void postButtonEvent(int buttonNumber, int buttonPress);

private:
    bool spaceballPresent;
    void importSettings(std::vector<int>& motionDataArray);
    float convertPrefToSensitivity(int value);
#if defined(_USE_3DCONNEXION_SDK) || defined(SPNAV_FOUND)
    GuiNativeEvent* nativeEvent;
#endif
};  // end class GUIApplicationNativeEventAware
}  // end namespace Gui
