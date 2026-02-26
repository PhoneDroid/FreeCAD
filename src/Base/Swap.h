// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2005 Imetric 3D GmbH
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

#define LOW_ENDIAN (unsigned short)0x4949
#define HIGH_ENDIAN (unsigned short)0x4D4D


namespace Base
{

/**
 * \brief Definition of functions that allow swapping of data types
 * dependent on the architecture.
 */

/** Returns machine type (low endian, high endian) */
unsigned short SwapOrder();

void SwapVar(char&);
void SwapVar(unsigned char&);
void SwapVar(short&);
void SwapVar(unsigned short&);
void SwapVar(long&);
void SwapVar(unsigned long&);
void SwapVar(float&);
void SwapVar(double&);

template<class T>
void SwapEndian(T& v)
{
    T tmp = v;
    int i = 0;

    for (i = 0; i < (int)sizeof(T); i++) {
        *(((char*)&tmp) + i) = *(((char*)&v) + sizeof(T) - i - 1);
    }
    v = tmp;
}

}  // namespace Base
