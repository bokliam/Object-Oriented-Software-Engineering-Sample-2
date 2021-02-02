/**
 * \file IsAdjRoadVisitor.h
 *
 * \author Liam Bok
 *
 * This class describe the adjacent tile visitor to tell if adjacent tile is road.
 */

#pragma once
#include "TileVisitor.h"


/** This class describes the adjacent tile visitor
 * 
 */
class CIsAdjRoadVisitor :
	public CTileVisitor
{
public:
	/// Visit road tile
	/// \param road Road tile
	virtual void VisitRoad(CTileRoad* road) override;

	/// Is road bool
	/// \return True if tile is road, false if not
	bool IsRoad() { return mIsRoad; };

private:
	/// bool indicating if tile is road or not
	bool mIsRoad = false;
};

