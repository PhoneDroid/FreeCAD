// SPDX-FileCopyrightText: 2016 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <App/Transactions.h>

namespace Gui
{
class TransactionViewProvider: public App::TransactionObject
{
    TYPESYSTEM_HEADER_WITH_OVERRIDE();

public:
    TransactionViewProvider();
    ~TransactionViewProvider() override;

    void applyNew(App::Document& Doc, App::TransactionalObject* pcObj) override;
    void applyDel(App::Document& Doc, App::TransactionalObject* pcObj) override;
};

}  // namespace Gui
