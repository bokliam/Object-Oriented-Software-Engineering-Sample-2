/**
 * \file IsRoadVisitor.cpp
 *
 * \author Liam Bok
 */


#include "pch.h"
#include "IsRoadVisitor.h"
#include "City.h"
#include "TileRoad.h"
#include "IsAdjRoadVisitor.h"


/** Visit CTileRoad object
 * 
 * \param road Road tile being visited
 */
void CIsRoadVisitor::VisitRoad(CTileRoad* road)
{
	// Create adjacent tile visitor for road tile
	CIsAdjRoadVisitor visitor;

	// Get all real adjacent tiles and determine if road or not
	auto ulTile = road->GetAdjacent(-1, -1);
	bool upperLeft = false;
	if (ulTile != nullptr)
	{
		upperLeft = true;
		ulTile->Accept(&visitor);
		if (! visitor.IsRoad())
		{
			upperLeft = false;
		}
	}

	auto urTile = road->GetAdjacent(1, -1);
	bool upperRight = false;
	if (urTile != nullptr)
	{
		upperRight = true;
		urTile->Accept(&visitor);
		if (! visitor.IsRoad())
		{
			upperRight = false;
		}
	}

	auto llTile = road->GetAdjacent(-1, 1);
	bool lowerLeft = false;
	if (llTile != nullptr)
	{
		lowerLeft = true;
		llTile->Accept(&visitor);
		if (! visitor.IsRoad())
		{
			lowerLeft = false;
		}
	}

	auto lrTile = road->GetAdjacent(1, 1);
	bool lowerRight = false;
	if (lrTile != nullptr)
	{
		lowerRight = true;
		lrTile->Accept(&visitor);
		if (! visitor.IsRoad())
		{
			lowerRight = false;
		}
		                                 
	}

	// Set adjacencies for road tile
	road->SetAdjacencies(upperLeft, upperRight, lowerLeft, lowerRight);
};
