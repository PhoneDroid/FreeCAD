// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2011 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#include "FeatureRefine.h"

#include <QtCore>

/// Base class of all additive features in PartDesign
namespace PartDesign
{

class PartDesignExport FeatureAddSub: public PartDesign::FeatureRefine
{
    Q_DECLARE_TR_FUNCTIONS(PartDesign::FeatureAddSub)
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesign::FeatureAddSub);

public:
    enum Type
    {
        Additive = 0,
        Subtractive
    };

    FeatureAddSub();

    void onChanged(const App::Property*) override;
    Type getAddSubType();

    short mustExecute() const override;

    virtual void getAddSubShape(Part::TopoShape& addShape, Part::TopoShape& subShape);

    void updatePreviewShape() override;

    Part::PropertyPartShape AddSubShape;


protected:
    Type addSubType {Additive};
};

using FeatureAddSubPython = App::FeaturePythonT<FeatureAddSub>;

class FeatureAdditivePython: public FeatureAddSubPython
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesign::FeatureAdditivePython);

public:
    FeatureAdditivePython();
    ~FeatureAdditivePython() override;
};

class FeatureSubtractivePython: public FeatureAddSubPython
{
    PROPERTY_HEADER_WITH_OVERRIDE(PartDesign::FeatureSubtractivePython);

public:
    FeatureSubtractivePython();
    ~FeatureSubtractivePython() override;
};

}  // namespace PartDesign
