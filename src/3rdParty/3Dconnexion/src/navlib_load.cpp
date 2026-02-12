// SPDX-FileCopyrightText: 2014-2023 3Dconnexion

/******************************************************************************
  This file is part of the FreeCAD CAx development system.

  This source code is released under the GNU Library General Public License, (see "LICENSE").
******************************************************************************/

extern "C" {
  extern long NlLoadLibrary();
  extern const long NlErrorCode = NlLoadLibrary();
}
