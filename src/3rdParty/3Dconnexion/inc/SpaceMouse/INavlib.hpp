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

#ifndef INavlib_HPP_INCLUDED
#define INavlib_HPP_INCLUDED

#include <navlib/navlib_types.h>

// stdlib
#include <string>

namespace TDx {
namespace SpaceMouse {
namespace Navigation3D {
/// <summary>
/// The interface to access the navigation library properties.
/// </summary>
class INavlibProperty {
public:
#if !defined(_MSC_VER) || (_MSC_VER > 1700)
  virtual ~INavlibProperty() = default;
#else
  virtual ~INavlibProperty() = 0 {
  }
#endif

  /// <summary>
  /// Writes the value of a property to the navlib.
  /// </summary>
  /// <param name="propertyName">The <see cref="navlib::property_t"/> name of the navlib property to
  /// write.</param>
  /// <param name="value">The <see cref="navlib::value"/> to write.</param>
  /// <returns>0 =no error, otherwise a value from <see cref="navlib::make_result_code"/>.</returns>
  /// <exception cref="std::system_error">No connection to the navlib / 3D Mouse.</exception>
  virtual long Write(const std::string &propertyName, const navlib::value &value) = 0;

  /// <summary>
  /// Reads the value of a navlib property.
  /// </summary>
  /// <param name="propertyName">The <see cref="navlib::property_t"/> name of the navlib property to
  /// read.</param>
  /// <param name="value">The <see cref="navlib::value"/> to read.</param>
  /// <returns>0 =no error, otherwise a value from <see cref="navlib::make_result_code"/>.</returns>
  /// <exception cref="std::system_error">No connection to the navlib / 3D Mouse.</exception>
  virtual long Read(const std::string &propertyName, navlib::value &value) const = 0;

  /// <summary>
  /// Reads the value of a navlib string property.
  /// </summary>
  /// <param name="propertyName">The <see cref="navlib::property_t"/> name of the navlib property to
  /// read.</param>
  /// <param name="string">The <see cref="std::string"/> value of the property.</param>
  /// <returns>0 =no error, otherwise a value from <see cref="navlib::make_result_code"/>.</returns>
  /// <exception cref="std::system_error">No connection to the navlib.</exception>
  virtual long Read(const std::string &propertyName, std::string &string) const = 0;
};

/// <summary>
/// The interface to access the navigation library.
/// </summary>
class INavlib : public INavlibProperty {
public:
  /// <summary>
  /// Close the connection to the 3D navigation library.
  /// </summary>
  virtual void Close() = 0;

  /// <summary>
  /// Opens a connection to the 3D navigation library.
  /// </summary>
  virtual void Open() = 0;

  /// <summary>
  /// Opens a connection to the 3D navigation library
  /// </summary>
  /// <param name="profileName">The name of the 3Dconnexion profile to use.</param>
  /// <exception cref="std::system_error">The connection to the library is already open.</exception>
  /// <exception cref="std::system_error">Cannot create a connection to the library.</exception>
  /// <exception cref="std::invalid_argument">The name of the profile is empty.</exception>
  virtual void Open(std::string profileName) = 0;
};
} // namespace Navigation3D
} // namespace SpaceMouse
} // namespace TDx
#endif // INavlib_HPP_INCLUDED

