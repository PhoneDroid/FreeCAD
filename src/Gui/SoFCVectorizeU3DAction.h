// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2010 Werner Mayer <wmayer@users.sourceforge.net>
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

#pragma once

#include <fstream>

#include <Inventor/annex/HardCopy/SoVectorizeAction.h>
#include <Inventor/annex/HardCopy/SoVectorOutput.h>

#include <FCGlobal.h>

namespace Gui
{

class GuiExport SoU3DVectorOutput: public SoVectorOutput
{
public:
    SoU3DVectorOutput();
    ~SoU3DVectorOutput() override;

    SbBool openFile(const char* filename) override;
    void closeFile() override;
    std::fstream& getFileStream();

private:
    std::fstream file;
};

/**
 * @author Werner Mayer
 */
class SoFCVectorizeU3DActionP;
class GuiExport SoFCVectorizeU3DAction: public SoVectorizeAction
{
    using inherited = SoVectorizeAction;

    SO_ACTION_HEADER(SoFCVectorizeU3DAction);

public:
    SoFCVectorizeU3DAction();
    ~SoFCVectorizeU3DAction() override;

    static void initClass();
    SoU3DVectorOutput* getU3DOutput() const;

protected:
    void beginTraversal(SoNode* node) override;
    void endTraversal(SoNode* node) override;
    void printHeader() const override;
    void printFooter() const override;
    void printBackground() const override;
    void printItem(const SoVectorizeItem* item) const override;
    void printViewport() const override;

private:
    static void actionMethod(SoAction*, SoNode*);

private:
    SoFCVectorizeU3DActionP* p;
    friend class SoFCVectorizeU3DActionP;
};

}  // namespace Gui
