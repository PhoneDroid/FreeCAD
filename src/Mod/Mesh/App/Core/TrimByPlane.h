// SPDX-License-Identifier: LGPL-2.1-or-later
// SPDX-FileCopyrightText: 2019 Werner Mayer <wmayer@users.sourceforge.net>
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

#include "MeshKernel.h"


namespace MeshCore
{

/**
 * Trim the facets in 3D with a plane
 * \author Werner Mayer
 */
class MeshExport MeshTrimByPlane
{
public:
    explicit MeshTrimByPlane(MeshKernel& mesh);

public:
    /**
     * Checks all facets for intersection with the plane and writes all touched facets into the
     * vector
     */
    void CheckFacets(
        const MeshFacetGrid& rclGrid,
        const Base::Vector3f& base,
        const Base::Vector3f& normal,
        std::vector<FacetIndex>& trimFacets,
        std::vector<FacetIndex>& removeFacets
    ) const;

    /**
     * The facets from \a trimFacets will be trimmed or deleted and \a trimmedFacets holds the newly
     * generated facets
     */
    void TrimFacets(
        const std::vector<FacetIndex>& trimFacets,
        const Base::Vector3f& base,
        const Base::Vector3f& normal,
        std::vector<MeshGeomFacet>& trimmedFacets
    );

private:
    void CreateOneFacet(
        const Base::Vector3f& base,
        const Base::Vector3f& normal,
        unsigned short shift,
        const MeshGeomFacet& facet,
        std::vector<MeshGeomFacet>& trimmedFacets
    ) const;
    void CreateTwoFacet(
        const Base::Vector3f& base,
        const Base::Vector3f& normal,
        unsigned short shift,
        const MeshGeomFacet& facet,
        std::vector<MeshGeomFacet>& trimmedFacets
    ) const;

private:
    MeshKernel& myMesh;
};

}  // namespace MeshCore
