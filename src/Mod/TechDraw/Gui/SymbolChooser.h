// SPDX-FileCopyrightText: 2019 WandererFan <wandererfan@gmail.com>
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

#include <Mod/TechDraw/TechDrawGlobal.h>

#include <QDialog>

class QListWidgetItem;

namespace TechDrawGui {

class Ui_SymbolChooser;
class TechDrawGuiExport SymbolChooser : public QDialog
{
    Q_OBJECT

public:
    SymbolChooser(QWidget *parent = nullptr,
                  QString startDir = QString(),
                  QString source = QString());
    ~SymbolChooser() override;

public Q_SLOTS:
    void onOKClicked();
    void onCancelClicked();
    void onItemClicked(QListWidgetItem* item);
    void onDirectoryChanged(const QString& newDir);

Q_SIGNALS:
    void symbolSelected(QString symbolPath,
                        QString source);

protected:
    void setUiPrimary(void);
    void loadSymbolNames(QString pathToSymbols);

private:
    std::unique_ptr<Ui_SymbolChooser> ui;
    QString m_symbolDir;
    QString m_symbolPath;
    QString m_source;
};

}