// SPDX-FileCopyrightText: 2020 WandererFan <wandererfan@gmail.com>
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

#include <QColor>

#include "QGIView.h"

class QColor;
class QString;

namespace Base
{
class Color;
}

class QFont;
class QString;

#include <Mod/TechDraw/App/Preferences.h>

namespace TechDraw{
enum class ArrowType : int;
}

namespace TechDrawGui
{

//getters for parameters used in multiple places.
class TechDrawGuiExport PreferencesGui {

public:
static QFont       labelFontQFont();
static int         labelFontSizePX();
static int         dimFontSizePX();

static QColor      normalQColor();
static QColor      selectQColor();
static QColor      preselectQColor();
static Base::Color sectionLineColor();
static QColor      sectionLineQColor();
static Base::Color centerColor();
static QColor      centerQColor();
static QColor      vertexQColor();
static Base::Color leaderColor();
static QColor      leaderQColor();
static Base::Color dimColor();
static QColor      dimQColor();
static Base::Color pageColor();
static QColor      pageQColor();
static Base::Color breaklineColor();
static QColor      breaklineQColor();

static TechDraw::ArrowType dimArrowStyle();
static double      dimArrowSize();

static double      edgeFuzz();

static QString     weldingDirectory();

static bool showGrid();
static Base::Color gridColor();
static QColor gridQColor();
static double gridSpacing();
static bool multiSelection();

static QColor       getAccessibleQColor(QColor orig);
static QColor       lightTextQColor();
static QColor       reverseColor(QColor orig);
static QColor       lightenColor(QColor orig);

static double       templateClickBoxSize();
static QColor       templateClickBoxColor();

static int          get3dMarkerSize();

static ViewFrameMode getViewFrameMode();
static void setViewFrameMode(ViewFrameMode newMode);


};

} //end namespace TechDrawGui