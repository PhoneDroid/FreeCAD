// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2020 Victor Titov (DeepSOIC) <vv.titov@gmail.com>
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


#include <Inventor/events/SoEvent.h>
#include <Inventor/events/SoSubEvent.h>
#include <FCGlobal.h>

/**
 * @brief The SoMouseWheelEvent class is a temporary replacement for
 * SoMouseWheelEvent from Coin, for until freecad stops using Coin version that
 * doesn't have one (coin v 4.0.0a doesn't have SoMouseWheelEvent).
 */
class GuiExport SoMouseWheelEvent: public SoEvent
{
    SO_EVENT_HEADER();

public:  // methods
    static void initClass()
    {
        SO_EVENT_INIT_CLASS(SoMouseWheelEvent, SoEvent);
    }
    SoMouseWheelEvent()
        : delta(0)
    {}
    SoMouseWheelEvent(int delta)
        : delta(delta)
    {}
    /// returns wheel position change. One click is usually 120 units,
    ///  smaller values come from high-resolution devices like touchpads
    int getDelta() const
    {
        return delta;
    }
    void setDelta(int delta)
    {
        this->delta = delta;
    }
    ~SoMouseWheelEvent() override = default;

private:  // data
    int delta;
};
