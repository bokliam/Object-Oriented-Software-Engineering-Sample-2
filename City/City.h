/**
 * \file City.h
 *
 * \author Charles B. Owen
 * \author Liam Bok
 *
 *  Class that implements a simple city with tiles we can manipulate
 */

#pragma once

#include <memory>
#include <vector>
#include <map>
#include <utility>
#include "XmlNode.h"
#include "Tile.h"

/**
 *  Implements a simple city with tiles we can manipulate
 */
class CCity
{
public:
	/// Constructor
    CCity();

	/// Destructor
    virtual ~CCity();

    /// The spacing between grid locations
    static const int GridSpacing = 32;

	/// Add tile
    void Add(std::shared_ptr<CTile> item);

	/// Hit test
    std::shared_ptr<CTile> HitTest(int x, int y);

	/// Move tile to front
    void MoveToFront(std::shared_ptr<CTile> item);

	/// Delete tile
    void DeleteItem(std::shared_ptr<CTile> item);

	/// Draw tiles
    void OnDraw(Gdiplus::Graphics *graphics);

	/// Save file
    void Save(const std::wstring &filename);

	/// Load file
    void Load(const std::wstring &filename);

	/// Clear function
    void Clear();

	/// Update function
    void Update(double elapsed);

	/// Sort tiles function
    void SortTiles();
	
	/// Get adjacent tiles using shared pointer to tile
	///\param tile Shared pointer to tile
    std::shared_ptr<CTile> GetAdjacent(std::shared_ptr<CTile> tile, int dx, int dy);

	/// Get adjacent tiles using tile object
	///\param tile Tile object
    std::shared_ptr<CTile> GetAdjacent(CTile *tile, int dx, int dy);

	/// Accept function for visitor
	void Accept(CTileVisitor* visitor);

	/** Iterator that iterates over the city tiles */
	class Iter
	{
	public:
		/** Constructor
		 * \param city The city we are iterating over */
		Iter(CCity* city, int pos) : mCity(city), mPos(pos) {}

		/** Test for end of the iterator
		 * \returns True if we this position equals not equal to the other position */
		bool operator!=(const Iter& other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		 * \returns Value at mPos in the collection */
		std::shared_ptr<CTile> operator *() const { return mCity->mTiles[mPos]; }

		/** Increment the iterator
		 * \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}


	private:
		CCity* mCity;   ///< City we are iterating over
		int mPos;       ///< Position in the collection
	};

	/** Get an iterator for the beginning of the collection
	 * \returns Iter object at position 0 */
	Iter begin() { return Iter(this, 0); }

	/** Get an iterator for the end of the collection
	 * \returns Iter object at position past the end */
	Iter end() { return Iter(this, mTiles.size()); }

private:
	void XmlTile(const std::shared_ptr<xmlnode::CXmlNode> &node);
	void BuildAdjacencies();

	/// All of the tiles that make up our city
	std::vector<std::shared_ptr<CTile> > mTiles;

	/// Adjacency lookup support
	std::map<std::pair<int, int>, std::shared_ptr<CTile> > mAdjacency;
};

