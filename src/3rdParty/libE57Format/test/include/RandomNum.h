// SPDX-License-Identifier: BSL-1.0
// SPDX-FileCopyrightText: 2022 Andy Maloney <asmaloney@gmail.com>
// SPDX-FileNotice: Part of the FreeCAD project.

#pragma once

#include <cstdint>

namespace Random
{
   // Seed our pseudo-random number generator for reproducibility.
   void seed( uint32_t inSeed );

   // Get a pseudo-random number.
   float num();
}
