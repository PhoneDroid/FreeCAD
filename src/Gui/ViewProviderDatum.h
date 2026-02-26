// SPDX-FileCopyrightText: 2015 Alexander Golubev <fatzer2@gmail.com>
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

#include "ViewProviderGeometryObject.h"

class SoScale;

namespace Gui
{

class SoShapeScale;

/**
 * View provider associated with an App::DatumElement.
 */
class GuiExport ViewProviderDatum: public ViewProviderGeometryObject
{
    PROPERTY_HEADER_WITH_OVERRIDE(Gui::ViewProviderDatum);

public:
    ViewProviderDatum();
    ~ViewProviderDatum() override;

    /// Get point derived classes will add their specific stuff
    SoSeparator* getDatumRoot() const
    {
        return pRoot;
    }

    void attach(App::DocumentObject*) override;
    std::vector<std::string> getDisplayModes() const override;
    void setDisplayMode(const char* ModeName) override;

    /// @name Suppress ViewProviderGeometryObject's behaviour
    ///@{
    bool setEdit(int) override
    {
        return false;
    }
    void unsetEdit(int) override
    {}
    ///@}

    void setTemporaryScale(double factor);
    void resetTemporarySize();

protected:
    void onChanged(const App::Property* prop) override;
    bool onDelete(const std::vector<std::string>&) override;

protected:
    SoSeparator* pRoot;
    SoShapeScale* soScale;
    double lineThickness;
};

}  // namespace Gui
