#!/bin/bash
# SPDX-License-Identifier: LGPL-2.1-or-later
# SPDX-FileNotice: Part of the FreeCAD project.

# Change to the directory of this script (any subdirectory in the repository should work)
cd "$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")" &> /dev/null && pwd -P)"

# Activate pixi default environment
eval "$(pixi shell-hook)"
