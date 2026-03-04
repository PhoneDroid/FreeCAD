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

// This header file defines the classes used for error reporting.

#ifndef NAVLIB_ERROR_H_INCLUDED_
#define NAVLIB_ERROR_H_INCLUDED_

#include <system_error>

#include <navlib/navlib_types.h>


namespace std {
template <> struct is_error_code_enum<NAVLIB_ navlib_errc::navlib_errc_t> : true_type {};
} // namespace std

namespace { // Anonymous namespace
/// <summary>
/// Navigation library error category.
/// </summary>
struct navlib_error_category : public std::error_category {
  typedef std::error_category base_type;

public:
  navlib_error_category() NOEXCEPT {
  }

  const char *name() const NOEXCEPT override {
    return "navlib";
  }

  std::string message(int errorValue) const override {
    namespace navlib_errc = navlib::navlib_errc;
    switch (static_cast<navlib_errc::navlib_errc_t>(errorValue)) {
    case navlib_errc::property_not_found:
      return "Cannot locate the requested navlib property.";

    case navlib_errc::invalid_function:
      return "The requested function is not valid.";

    case navlib_errc::insufficient_buffer:
      return "Insufficient buffer space.";

    default:
      return std::generic_category().message(errorValue);
    }
  }
};

/// <summary>
/// Navigation library error category.
/// </summary>
static const navlib_error_category navlib_category;
} // namespace

NAVLIB_BEGIN_
/// <summary>
/// Makes a <see cref="std::error_code"/>.
/// </summary>
/// <param name="errc">The Navigation library error.</param>
/// <returns>A <see cref="std::error_code"/> with the Navigation library category.</returns>
inline std::error_code make_error_code(navlib_errc::navlib_errc_t errc) {
  std::error_code ec(static_cast<int>(errc), navlib_category);
  return ec;
}
NAVLIB_END_ // namespace navlib
#endif /* NAVLIB_ERROR_H_INCLUDED_ */
