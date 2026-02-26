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

#include <Base/Persistence.h>
#include <QUrl>

class QImage;

namespace Gui
{
class View3DInventorViewer;

class Thumbnail: public Base::Persistence
{
public:
    Thumbnail(int s = 128);
    ~Thumbnail() override;

    void setViewer(View3DInventorViewer*);
    void setSize(int);
    void setFileName(const char*);

    /** @name I/O of the document */
    //@{
    unsigned int getMemSize() const override;
    /// This method is used to save properties or very small amounts of data to an XML document.
    void Save(Base::Writer& writer) const override;
    /// This method is used to restore properties from an XML document.
    void Restore(Base::XMLReader& reader) override;
    /// This method is used to save large amounts of data to a binary file.
    void SaveDocFile(Base::Writer& writer) const override;
    /// This method is used to restore large amounts of data from a binary file.
    void RestoreDocFile(Base::Reader& reader) override;
    //@}

private:
    QUrl uri;
    View3DInventorViewer* viewer {nullptr};
    int size;
};

}  // namespace Gui
