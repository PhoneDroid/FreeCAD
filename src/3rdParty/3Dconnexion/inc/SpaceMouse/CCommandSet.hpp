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

#ifndef CCommandSet_HPP_INCLUDED
#define CCommandSet_HPP_INCLUDED

#include <SpaceMouse/CCommandTreeNode.hpp>

#ifndef _MSC_VER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif

namespace TDx {
namespace SpaceMouse {
/// <summary>
/// The helper class implements the <see cref="SiActionNodeType_t::SI_ACTIONSET_NODE"/> node type.
/// </summary>
class CCommandSet : public CCommandTreeNode {
  typedef CCommandTreeNode base_type;

public:
  CCommandSet() {
  }

  explicit CCommandSet(std::string id, std::string name)
      : base_type(std::move(id), std::move(name), SiActionNodeType_t::SI_ACTIONSET_NODE) {
  }
#if defined(_MSC_VER) && _MSC_VER < 1900
  CCommandSet(CCommandSet &&other) : base_type(std::forward<base_type>(other)) {
  }
  CCommandSet &operator=(CCommandSet &&other) {
    base_type::operator=(std::forward<base_type>(other));
    return *this;
  }
#else
  CCommandSet(CCommandSet &&) = default;
  CCommandSet &operator=(CCommandSet &&) = default;
#endif
};
} // namespace SpaceMouse
} // namespace TDx

#ifndef _MSC_VER
#pragma GCC diagnostic pop
#endif

#endif // CCommandSet_HPP_INCLUDED
