/**
 * \file IsAdjRoadVisitor.cpp
 *
 * \author Liam Bok
 */

#include "pch.h"
#include "IsAdjRoadVisitor.h"


/** Visit road tile
 * 
 * \param road Road tile
 */
void CIsAdjRoadVisitor::VisitRoad(CTileRoad* road)
{
	mIsRoad = true;
}
