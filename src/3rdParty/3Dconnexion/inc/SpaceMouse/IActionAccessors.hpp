// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2014-2023 3Dconnexion
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

#ifndef IActionAccessors_HPP_INCLUDED
#define IActionAccessors_HPP_INCLUDED

#include <SpaceMouse/IEvents.hpp>

namespace TDx {
namespace SpaceMouse {
namespace ActionInput {
/// <summary>
/// The accessor interface to the client action input properties.
/// </summary>
class IActionAccessors : public Navigation3D::IEvents {
};
} // namespace ActionInput
} // namespace SpaceMouse
} // namespace TDx
#endif // IActionAccessors_HPP_INCLUDED
