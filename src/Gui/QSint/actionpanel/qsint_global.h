// SPDX-License-Identifier: LGPL-3.0-only
// SPDX-FileCopyrightText: 2011 Sintegrial Technologies 
// SPDX-FileNotice: Part of the FreeCAD project.
// SPDX-FileNotice: https://code.google.com/p/qsint

#pragma once

#include <qglobal.h>

#ifdef QSINT_STATICLIB
#  undef QSINT_SHAREDLIB
#  define QSINT_EXPORT
#else
#  ifdef QSINT_MAKEDLL
#   define QSINT_EXPORT Q_DECL_EXPORT
#  else
#   define QSINT_EXPORT Q_DECL_IMPORT
#  endif
#endif
