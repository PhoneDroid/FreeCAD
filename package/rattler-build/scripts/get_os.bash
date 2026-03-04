#!/usr/bin/env bash
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

if [[ "$OSTYPE" =~ (msys*|cygwin*|mingw*) ]]; then
    echo windows
elif [[ "$OSTYPE" == darwin* ]]; then
    echo osx
elif [[ "$OSTYPE" == linux* ]]; then
    echo linux
fi
