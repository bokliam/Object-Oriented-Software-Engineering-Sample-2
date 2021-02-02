/**
 * \file BuildingCounter.h
 *
 * \author Liam Bok
 *
 *  This class describes the building counter functionality.
 */

#pragma once
#include "TileVisitor.h"


/** This class describes the building counter
 * 
 */
class CBuildingCounter :
	public CTileVisitor
{
public:
	/** Get the number of buildings
	 * \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

	/// Building visitor
	void VisitBuilding(CTileBuilding* building);

private:
	/// Buildings counter
	int mNumBuildings = 0;
	
};

