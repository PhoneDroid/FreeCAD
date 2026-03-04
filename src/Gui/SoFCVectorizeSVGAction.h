// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2008 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <Inventor/annex/HardCopy/SoVectorizeAction.h>
#include <Inventor/annex/HardCopy/SoVectorOutput.h>

#include <fstream>
#include <FCGlobal.h>


namespace Gui
{

class GuiExport SoSVGVectorOutput: public SoVectorOutput
{
public:
    SoSVGVectorOutput();
    ~SoSVGVectorOutput() override;

    SbBool openFile(const char* filename) override;
    void closeFile() override;
    std::fstream& getFileStream();

private:
    std::fstream file;
};

/**
 * @author Werner Mayer
 */
class SoFCVectorizeSVGActionP;
class GuiExport SoFCVectorizeSVGAction: public SoVectorizeAction
{
    using inherited = SoReplacedElement;

    SO_ACTION_HEADER(SoFCVectorizeSVGAction);

public:
    SoFCVectorizeSVGAction();
    ~SoFCVectorizeSVGAction() override;

    static void initClass();
    SoSVGVectorOutput* getSVGOutput() const;

    virtual void setBackgroundState(bool b)
    {
        m_backgroundState = b;
    }
    virtual bool getBackgroundState() const
    {
        return m_backgroundState;
    }
    virtual void setLineWidth(double w)
    {
        m_lineWidth = w;
    }
    virtual double getLineWidth() const
    {
        return m_lineWidth;
    }
    virtual void setUseMM(bool b)
    {
        m_usemm = b;
    }
    virtual bool getUseMM() const
    {
        return m_usemm;
    }

protected:
    void printHeader() const override;
    void printFooter() const override;
    void printBackground() const override;
    void printItem(const SoVectorizeItem* item) const override;
    void printViewport() const override;

private:
    SoFCVectorizeSVGActionP* p;
    friend class SoFCVectorizeSVGActionP;
    bool m_backgroundState {true};
    double m_lineWidth {1.0};
    bool m_usemm {false};
};

}  // namespace Gui
