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

#ifndef IPivot_HPP_INCLUDED
#define IPivot_HPP_INCLUDED

#include <navlib/navlib_types.h>

namespace TDx {
namespace SpaceMouse {
namespace Navigation3D {
  /// <summary>
  /// The interface to access the pivot.
  /// </summary>
class IPivot {
public:
#if !defined(_MSC_VER) || (_MSC_VER > 1700)
  virtual ~IPivot() = default;
#else
  virtual ~IPivot() = 0 {
  }
#endif

  /// <summary>
  /// Gets the position of the rotation pivot.
  /// </summary>
  /// <param name="position">The pivot <see cref="navlib::point_t"/> in world coordinates.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long GetPivotPosition(navlib::point_t &position) const = 0;

  /// <summary>
  /// Queries if the user has manually set a pivot point.
  /// </summary>
  /// <param name="userPivot">true if the user has set a pivot otherwise false.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long IsUserPivot(navlib::bool_t &userPivot) const = 0;

  /// <summary>
  /// Sets the position of the rotation pivot.
  /// </summary>
  /// <param name="position">The pivot <see cref="navlib::point_t"/> in world coordinates.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long SetPivotPosition(const navlib::point_t& position) = 0;

  /// <summary>
  /// Queries the visibility of the pivot image.
  /// </summary>
  /// <param name="visible">true if the pivot is visible otherwise false.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long GetPivotVisible(navlib::bool_t &visible) const = 0;

  /// <summary>
  /// Sets the visibility of the pivot image.
  /// </summary>
  /// <param name="visible">true if the pivot is visible otherwise false.</param>
  /// <returns>0 = no error, otherwise &lt;0.</returns>
  virtual long SetPivotVisible(bool visible) = 0;
};
} // namespace Navigation3D
} // namespace SpaceMouse
} // namespace TDx
#endif // IPivot_HPP_INCLUDED
