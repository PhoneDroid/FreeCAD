// SPDX-FileCopyrightText: 2007 Werner Mayer <wmayer@users.sourceforge.net>
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

#include <functional>
#include <CXX/Objects.hxx>
#include <QObject>
#include <QTcpServer>
#include "Command.h"


namespace Gui
{

/// opens a URL in the system Browser
bool GuiExport OpenURLInBrowser(const char* URL);

/**
 * Returns the content of an HTML page which gets sent to
 * the client to be displayed.
 * @author Werner Mayer
 */
class PythonOnlineHelp: public QObject
{
    Q_OBJECT

public:
    PythonOnlineHelp();
    ~PythonOnlineHelp() override;

    QByteArray loadResource(const QString& filename) const;

private:
    QByteArray fileNotFound() const;
    QByteArray loadFailed(const QString& error) const;
    QByteArray loadFavicon() const;
    QByteArray loadIndexPage() const;
    QByteArray loadHelpPage(const QString& filename) const;
    QByteArray invoke(const std::function<std::string(Py::Module&)>& func) const;
    QByteArray tryInvoke(const std::function<std::string(Py::Module&)>& func) const;
};

/**
 * The HttpServer class implements a simple HTTP server.
 */
class HttpServer: public QTcpServer
{
    Q_OBJECT

public:
    explicit HttpServer(QObject* parent = nullptr);

    void incomingConnection(qintptr socket) override;
    void pause();
    void resume();

private Q_SLOTS:
    void readClient();
    void discardClient();

private:
    PythonOnlineHelp help;
    bool disabled;
};

// --------------------------------------------------------------------

class StdCmdPythonHelp: public Command
{
public:
    StdCmdPythonHelp();
    ~StdCmdPythonHelp() override;
    const char* className() const override
    {
        return "Gui::StdCmdPythonHelp";
    }

protected:
    void activated(int iMsg) override;

private:
    HttpServer* server;
};

}  // namespace Gui
