// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2022 Zheng Lei <realthunder.dev@gmail.com>
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

#include <memory>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Version.hxx>
#include "TopoShape.h"

#include <Mod/Part/PartGlobal.h>

namespace Part
{

class PartExport WireJoiner: public BRepBuilderAPI_MakeShape
{
public:
    WireJoiner();
    ~WireJoiner() override;

    void addShape(const TopoShape& shape);
    void addShape(const std::vector<TopoShape>& shapes);
    void addShape(const std::vector<TopoDS_Shape>& shapes);

    void setOutline(bool enable = true);
    void setTightBound(bool enable = true);
    void setSplitEdges(bool enable = true);
    void setMergeEdges(bool enable = true);
    void setTolerance(double tolerance, double atol = 0.0);

    bool getOpenWires(TopoShape& shape, const char* op = "", bool noOriginal = true);
    bool getResultWires(TopoShape& shape, const char* op = "");

#if OCC_VERSION_HEX < 0x070600
    void Build() override;
#else
    void Build(const Message_ProgressRange& theRange = Message_ProgressRange()) override;
#endif
    const TopTools_ListOfShape& Modified(const TopoDS_Shape& SThatModifies) override;
    const TopTools_ListOfShape& Generated(const TopoDS_Shape& SThatGenerates) override;
    Standard_Boolean IsDeleted(const TopoDS_Shape& SDeleted) override;

private:
    class WireJoinerP;
    std::unique_ptr<WireJoinerP> pimpl;
};

}  // namespace Part
