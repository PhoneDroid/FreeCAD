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

#include <QAbstractNativeEventFilter>

namespace Gui
{
class RawInputEventFilter: public QAbstractNativeEventFilter
{
public:
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    using EventFilter = bool (*)(void* message, long* result);
#else
    using EventFilter = bool (*)(void* message, qintptr* result);
#endif
    RawInputEventFilter(EventFilter filter)
        : eventFilter(filter)
    {}
    virtual ~RawInputEventFilter()
    {}

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    virtual bool nativeEventFilter(const QByteArray& /*eventType*/, void* message, long* result)
    {
        return eventFilter(message, result);
    }
#else
    virtual bool nativeEventFilter(const QByteArray& /*eventType*/, void* message, qintptr* result)
    {
        return eventFilter(message, result);
    }
#endif

private:
    EventFilter eventFilter;
};
}  // namespace Gui
