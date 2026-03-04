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

#ifndef IEvents_HPP_INCLUDED
#define IEvents_HPP_INCLUDED

// navlib
#include <navlib/navlib_types.h>

//stdlib
#include <string>

namespace TDx {
namespace SpaceMouse {
namespace Navigation3D {
/// <summary>
/// The Events interface
/// </summary>
class IEvents {
public:
#if !defined(_MSC_VER) || (_MSC_VER > 1700)
  virtual ~IEvents() = default;
#else
  virtual ~IEvents() = 0 {
  }
#endif

  /// <summary>
  /// Is called when the user invokes an application command from the SpaceMouse.
  /// </summary>
  /// <param name="commandId">The id of the command to invoke.</param>
  /// <returns>The result of the function: 0 = no error, otherwise &lt;0.</returns>
  virtual long SetActiveCommand(std::string commandId) = 0;

  /// <summary>
  /// Is called when the navigation settings change.
  /// </summary>
  /// <param name="count">The change count.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long SetSettingsChanged(long count) = 0;

  /// <summary>
  /// Is invoked when the user releases a key on the 3D Mouse, which has been programmed to send a
  /// virtual key code.
  /// </summary>
  /// <param name="vkey">The virtual key code of the key pressed.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long SetKeyPress(long vkey) = 0;

  /// <summary>
  /// Is invoked when the user releases a key on the 3D Mouse, which has been programmed to send a
  /// virtual key code.
  /// </summary>
  /// <param name="vkey">The virtual key code of the key released.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long SetKeyRelease(long vkey) = 0;
};
} // namespace Navigation3D
} // namespace SpaceMouse
} // namespace TDx
#endif // IEvents_HPP_INCLUDED
