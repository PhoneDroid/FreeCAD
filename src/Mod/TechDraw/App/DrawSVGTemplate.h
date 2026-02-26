// SPDX-FileCopyrightText: 2014 Luke Parry <l.parry@warwick.ac.uk>
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

# include <QDomDocument>

#include <App/DocumentObserver.h>
#include <App/FeaturePython.h>
#include <App/PropertyFile.h>
#include <Mod/TechDraw/TechDrawGlobal.h>

#include "DrawTemplate.h"


namespace TechDraw
{

class TechDrawExport DrawSVGTemplate: public TechDraw::DrawTemplate,
                                      public App::DocumentObserver
{
    PROPERTY_HEADER_WITH_OVERRIDE(TechDraw::DrawSVGTemplate);

public:
    DrawSVGTemplate();
    ~DrawSVGTemplate() override;

    App::PropertyFileIncluded PageResult;
    App::PropertyFile Template;

    void onChanged(const App::Property* prop) override;
   /// returns the type name of the ViewProvider
    const char* getViewProviderName(void) const override {
        return "TechDrawGui::ViewProviderTemplate";
    }

    PyObject *getPyObject(void) override;

    double getWidth() const override;
    double getHeight() const override;

    QString processTemplate();
    void extractTemplateAttributes(QDomDocument& templateDocument);
    bool getTemplateDocument(std::string sourceFile, QDomDocument& templateDocument) const;
    QString getAutofillByEditableName(QString nameToMatch);

    void translateLabel(std::string context, std::string baseName, std::string uniqueName);


protected:
    void onSettingDocument() override;

    void replaceFileIncluded(std::string newTemplateFileName);
    std::map<std::string, std::string> getEditableTextsFromTemplate();

private:
    void slotCreatedObject(const App::DocumentObject& obj) override;
    void slotDeletedObject(const App::DocumentObject& obj) override;

};

using DrawSVGTemplatePython = App::FeaturePythonT<DrawSVGTemplate>;

} //namespace TechDraw