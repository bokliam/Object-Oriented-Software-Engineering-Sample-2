/**
 * \file IsRoadVisitor.h
 *
 * \author Liam Bok
 *
 * This class describes the road tile visitor and determines if a tile is a road.
 */

#pragma once
#include "TileVisitor.h"


/** This class describes the visitor for road tiles
 * 
 */
class CIsRoadVisitor :
	public CTileVisitor
{
public:

	/// Visit road tile and determine adjacent road tiles
	/// \param road Road tile
	virtual void VisitRoad(CTileRoad* road) override;
};

