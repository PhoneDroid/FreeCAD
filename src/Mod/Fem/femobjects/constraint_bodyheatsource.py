# SPDX-FileCopyrightText: 2017 Markus Hovorka <m.hovorka@live.de>
# SPDX-FileCopyrightText: 2020 Bernd Hahnebach <bernd@bimstatik.org>
# SPDX-FileCopyrightText: 2024 Mario Passaglia <mpassaglia@cbc.uba.ar>
# SPDX-FileNotice: Part of the FreeCAD project.

################################################################################
#                                                                              #
#   FreeCAD is free software: you can redistribute it and/or modify            #
#   it under the terms of the GNU Lesser General Public License as             #
#   published by the Free Software Foundation, either version 2.1              #
#   of the License, or (at your option) any later version.                     #
#                                                                              #
#   FreeCAD is distributed in the hope that it will be useful,                 #
#   but WITHOUT ANY WARRANTY; without even the implied warranty                #
#   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                    #
#   See the GNU Lesser General Public License for more details.                #
#                                                                              #
#   You should have received a copy of the GNU Lesser General Public           #
#   License along with FreeCAD. If not, see https://www.gnu.org/licenses       #
#                                                                              #
################################################################################

__title__ = "FreeCAD FEM constraint body heat source document object"
__author__ = "Markus Hovorka, Bernd Hahnebach, Mario Passaglia"
__url__ = "https://www.freecad.org"

## @package constraint_bodyheatsource
#  \ingroup FEM
#  \brief constraint body heat source object

import FreeCAD

from . import base_fempythonobject

_PropHelper = base_fempythonobject._PropHelper


class ConstraintBodyHeatSource(base_fempythonobject.BaseFemPythonObject):

    Type = "Fem::ConstraintBodyHeatSource"

    def __init__(self, obj):
        super().__init__(obj)

        for prop in self._get_properties():
            prop.add_to_object(obj)

    def _get_properties(self):
        prop = []

        prop.append(
            _PropHelper(
                type="App::PropertyDissipationRate",
                name="DissipationRate",
                group="Constraint Body Heat Source",
                doc="Power dissipated per unit mass",
                value="0 W/kg",
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyPower",
                name="TotalPower",
                group="Constraint Body Heat Source",
                doc="Total power dissipated",
                value="0 W",
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyEnumeration",
                name="Mode",
                group="Constraint Body Heat Source",
                doc="Switch quantity input mode",
                value=["Dissipation Rate", "Total Power"],
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyBool",
                name="EnableAmplitude",
                group="Constraint Body Heat Source",
                doc="Amplitude of the body heat source",
                value=False,
            )
        )
        prop.append(
            _PropHelper(
                type="App::PropertyStringList",
                name="AmplitudeValues",
                group="Constraint Body Heat Source",
                doc="Amplitude values",
                value=["0, 0", "1, 1"],
            )
        )
        return prop

    def onDocumentRestored(self, obj):
        # update old project with new properties
        for prop in self._get_properties():
            try:
                obj.getPropertyByName(prop.name)
            except FreeCAD.Base.PropertyError:
                prop.add_to_object(obj)

        # migrate old HeatSource property
        try:
            value = obj.getPropertyByName("HeatSource")
            obj.DissipationRate = FreeCAD.Units.Quantity(value, "W/kg")
            obj.Mode = "Dissipation Rate"
            obj.setPropertyStatus("HeatSource", "-LockDynamic")
            obj.removeProperty("HeatSource")
        except FreeCAD.Base.PropertyError:
            pass
