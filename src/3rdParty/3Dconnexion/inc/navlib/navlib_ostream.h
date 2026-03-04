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

// This header file defines stream operators for the navlib types.

#ifndef NAVLIB_OSTREAM_INCLUDED_
#define NAVLIB_OSTREAM_INCLUDED_

#include <navlib/navlib_types.h>
// C++ convenience functions

#include <iomanip>
#include <limits>
#include <ostream>
#include <string>

NAVLIB_BEGIN_
template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const vector_t &vector) {
  stream << std::setprecision(std::numeric_limits<float>::digits10 + 1);
  stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const point_t &position) {
  stream << std::setprecision(std::numeric_limits<float>::digits10 + 1);
  stream << "[" << position.x << ", " << position.y << ", " << position.z << "]";
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const plane_t &plane) {
  stream << std::setprecision(std::numeric_limits<float>::digits10 + 1);
  stream << "[" << plane.n.x << ", " << plane.n.y << ", " << plane.n.z << ", " << plane.d << "]";
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const box_t &box) {
  stream << std::setprecision(std::numeric_limits<float>::digits10 + 1);
  stream << box.min << ", " << box.max;
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const frustum_t &frustum) {
  stream << std::setprecision(std::numeric_limits<float>::digits10 + 1);
  stream << "[" << frustum.left << ", " << frustum.right << ", " << frustum.bottom << ", "
         << frustum.top << ", " << frustum.nearVal << ", " << frustum.farVal << "]";
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const matrix_t &matrix) {
  stream << std::endl;
  stream << std::setprecision(std::numeric_limits<float>::digits10 + 1);
  stream << "\t[" << matrix.m00 << ", " << matrix.m01 << ", " << matrix.m02 << ", " << matrix.m03
         << "]" << std::endl;
  stream << "\t[" << matrix.m10 << ", " << matrix.m11 << ", " << matrix.m12 << ", " << matrix.m13
         << "]" << std::endl;
  stream << "\t[" << matrix.m20 << ", " << matrix.m21 << ", " << matrix.m22 << ", " << matrix.m23
         << "]" << std::endl;
  stream << "\t[" << matrix.m30 << ", " << matrix.m31 << ", " << matrix.m32 << ", " << matrix.m33
         << "]";
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const struct siResource_s &resource) {
  stream << "{file_name: " << (resource.file_name ? resource.file_name : "nullptr")
         << ", id: " << (resource.id ? resource.id : "nullptr")
         << ", type: " << (resource.type ? resource.type : "nullptr")
         << ", index: " << resource.index << "}";

  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const struct siImageFile_s &file) {
  stream << "{file_name: " << (file.file_name ? file.file_name : "nullptr")
         << ", index: " << file.index << "}";

  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const struct siImageData_s &image) {
  stream << "{data: 0x" << std::hex << reinterpret_cast<uintptr_t>(image.data) << std::dec
         << ", size: " << image.size << ", index: " << image.index << "}";

  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const imagearray_t &images) {
  stream << "count: " << images.count;

  std::string indent("\n");
  indent.resize(5, ' ');

  for (size_t i = 0; i < images.count; ++i) {
    SiImage_t const &image = images.p[i];
    stream << indent << "{size: " << image.size << ", id: " << (image.id ? image.id : "nullptr");
    if (image.type == e_image_file)
      stream << ", type: e_image_file, " << image.file;
    else if (image.type == e_resource_file)
      stream << ", type: e_resource_file, " << image.resource;
    if (image.type == e_image)
      stream << ", type: e_image, " << image.image;
    else
      stream << ", type: e_none";
    stream << "}";
  }
  return stream;
}

template <class Elem_, class Traits_>
void StreamActionNodeHeader(std::basic_ostream<Elem_, Traits_> &stream,
                            const SiActionNodeEx_t &node, size_t level) {
  std::string indent("\n");
  indent.resize(4 * level + 1, ' ');

  stream << indent << "{size: " << node.size << ", type: " << node.type
         << ", id: " << (node.id ? node.id : "nullptr")
         << ", label: " << (node.label ? node.label : "nullptr")
         << ", description: " << (node.description ? node.description : "nullptr") << "}";
  if (node.children != nullptr)
    StreamActionNodeHeader(stream, *node.children, level + 1);
  if (node.next != nullptr)
    StreamActionNodeHeader(stream, *node.next, level);
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const SiActionNodeEx_t &node) {
  StreamActionNodeHeader(stream, node, 1);
  return stream;
}

template <class Elem_, class Traits_>
std::basic_ostream<Elem_, Traits_> &operator<<(std::basic_ostream<Elem_, Traits_> &stream,
                                               const value_t &value) {
  try {
    switch (value.type) {
    case voidptr_type:
      stream << value.p;
      break;
    case bool_type:
      stream << (value.b ? "true" : "false");
      break;
    case long_type:
      stream << value.l;
      break;
    case float_type:
      stream << std::setprecision(std::numeric_limits<float>::digits10 + 1) << value.f;
      break;
    case double_type:
      stream << std::setprecision(std::numeric_limits<double>::digits10 + 2) << value.d;
      break;
    case point_type:
      stream << value.point;
      break;
    case vector_type:
      stream << value.vector;
      break;
    case matrix_type:
      stream << value.matrix;
      break;
    case string_type:
      if (value.string.p)
        stream << value.string.p;
      else
        stream << "empty";
      break;
    case actionnodeexptr_type:
      stream << *value.pnode;
      break;
    case imagearray_type:
      stream << value.imagearray;
      break;
    case plane_type:
      stream << value.plane;
      break;
    case box_type:
      stream << value.box;
      break;
    case frustum_type:
      stream << value.frustum;
      break;
    case cstr_type:
      if (value.cstr_.p)
        stream << value.cstr_.p;
      else
        stream << "empty";
      break;
    default:
      stream << "null";
      break;
    }
  } catch (std::runtime_error &e) {
    stream << "std::runtime_error " << e.what();
  }
  return stream;
}
NAVLIB_END_
#endif // NAVLIB_OSTREAM_INCLUDED_
