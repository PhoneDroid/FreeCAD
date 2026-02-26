// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2017 Abdullah Tahiri <abdullah.tahiri.yo@gmail.com>
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


#include "ExceptionFactory.h"
#include <CXX/Objects.hxx>


using namespace Base;

ExceptionFactory* ExceptionFactory::_pcSingleton = nullptr;  // NOLINT

ExceptionFactory& ExceptionFactory::Instance()
{
    if (!_pcSingleton) {
        _pcSingleton = new ExceptionFactory;  // NOLINT
    }
    return *_pcSingleton;
}

void ExceptionFactory::Destruct()
{
    delete _pcSingleton;
    _pcSingleton = nullptr;
}

void ExceptionFactory::raiseException(PyObject* pydict) const
{
    std::string classname;

    Py::Dict edict(pydict);
    if (edict.hasKey("sclassname")) {
        classname = static_cast<std::string>(Py::String(edict.getItem("sclassname")));

        auto pProd = _mpcProducers.find(classname);
        if (pProd != _mpcProducers.end()) {
            static_cast<AbstractExceptionProducer*>(pProd->second)->raiseException(pydict);
        }
    }
}

void ExceptionFactory::raiseExceptionByType(const PyExceptionData& data) const
{
    for (const auto& it : _mpcProducers) {
        static_cast<AbstractExceptionProducer*>(it.second)->raiseExceptionByType(data);  // NOLINT
    }
}
