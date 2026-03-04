// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2015 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <QObject>
#include <QVariant>
#include <functional>
#include <FCGlobal.h>

class QAction;

namespace Gui
{

class ActionFunctionPrivate;

/*!
  The class connects the triggered() signal of a QAction instance with the method
  of a usual C++ class not derived from QObject.

  The class can e.g be used to fill up the context-menu of the view provider classes.
  \code
    void MyViewProvider::setupContextMenu(QMenu* menu, QObject* receiver, const char* member)
    {
        Gui::ActionFunction* func = new Gui::ActionFunction(menu);

        QAction* a1 = menu->addAction(QObject::tr("Menu item 1..."));
        func->triggered(a1, std::bind(&MyViewProvider::doItem1, this));

        QAction* a2 = menu->addAction(QObject::tr("Menu item 2..."));
        func->triggered(a2, std::bind(&MyViewProvider::doItem2, this));

        QAction* a3 = menu->addAction(QObject::tr("Menu item 3..."));
        func->triggered(a3, std::bind(&MyViewProvider::doItem3, this));
    }
  \endcode

  @author Werner Mayer

  http://www.boost.org/doc/libs/1_57_0/libs/bind/bind.html#with_boost_function
*/
class GuiExport ActionFunction: public QObject
{
    Q_OBJECT

public:
    /// Constructor
    explicit ActionFunction(QObject*);
    ~ActionFunction() override;

    /*!
       Connects the QAction's triggered() signal with the function \a func
     */
    void trigger(QAction* a, std::function<void()> func);
    void toggle(QAction* a, std::function<void(bool)> func);
    void hover(QAction* a, std::function<void()> func);

private Q_SLOTS:
    void triggered();
    void toggled(bool);
    void hovered();

private:
    QScopedPointer<ActionFunctionPrivate> d_ptr;
    Q_DISABLE_COPY(ActionFunction)
    Q_DECLARE_PRIVATE(ActionFunction)
};

class TimerFunctionPrivate;

class GuiExport TimerFunction: public QObject
{
    Q_OBJECT

public:
    /// Constructor
    explicit TimerFunction(QObject* = nullptr);
    ~TimerFunction() override;

    void setFunction(std::function<void()> func);
    void setFunction(std::function<void(QObject*)> func, QObject* args);
    void setFunction(std::function<void(QVariant)> func, QVariant args);
    void setAutoDelete(bool);
    void singleShot(int ms);

private Q_SLOTS:
    void timeout();

private:
    QScopedPointer<TimerFunctionPrivate> d_ptr;
    Q_DISABLE_COPY(TimerFunction)
    Q_DECLARE_PRIVATE(TimerFunction)
};

}  // namespace Gui
