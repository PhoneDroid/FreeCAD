// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2002 Jürgen Riegel <juergen.riegel@web.de>
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

#include <cassert>
#include <iostream>

#include <QAtomicInt>

#include "Handle.h"


using namespace Base;

//**************************************************************************
// Construction/Destruction

Handled::Handled()
    : _lRefCount(new QAtomicInt(0))
{}

Handled::~Handled()
{
    if (static_cast<int>(*_lRefCount) != 0) {
        std::cerr << "Reference counter of deleted object is not zero!!!!!" << std::endl;
    }
    delete _lRefCount;
}

void Handled::ref() const
{
    _lRefCount->ref();
}

void Handled::unref() const
{
    assert(*_lRefCount > 0);
    if (!_lRefCount->deref()) {
        delete this;
    }
}

int Handled::unrefNoDelete() const
{
    int res = _lRefCount->deref();
    assert(res >= 0);
    return res;
}

int Handled::getRefCount() const
{
    return static_cast<int>(*_lRefCount);
}

Handled& Handled::operator=(const Handled& /*unused*/)
{
    // we must not assign _lRefCount
    return *this;
}
