// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: Jürgen Riegel 2007    <juergen.riegel@web.de>
// SPDX-FileNotice: Part of the FreeCAD project.

/*************************************************************************** *   LGPL                                                                  *
 ***************************************************************************/

#include "JrJt/JtReader.h"


class TestJtReader: public JtReader
{
public:
    TestJtReader();
    ~TestJtReader();

    void read(void);
};
