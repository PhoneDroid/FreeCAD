// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2009 Jürgen Riegel <FreeCAD@juergen-riegel.net>
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

#include <string>
#include <memory>

#include "UnitsSchemasSpecs.h"
#include "Base/Quantity.h"

namespace Base
{
class Quantity;

/**
 * An individual schema object
 */
class BaseExport UnitsSchema
{
public:
    explicit UnitsSchema(UnitsSchemaSpec spec);
    UnitsSchema() = delete;

    [[nodiscard]] bool isMultiUnitLength() const;
    [[nodiscard]] bool isMultiUnitAngle() const;
    [[nodiscard]] std::string getBasicLengthUnit() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] int getNum() const;

    std::string translate(const Quantity& quant) const;
    std::string translate(const Quantity& quant, double& factor, std::string& unitString) const;

private:
    [[nodiscard]] static std::string toLocale(
        const Quantity& quant,
        double factor,
        const std::string& unitString
    );

    UnitsSchemaSpec spec;
};


}  // namespace Base
