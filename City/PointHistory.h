/**
* \file PointHistory.cpp
*
* \author Charles B. Owen
* \author Liam Bok
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);


protected:
    /**
    * Nested class that stores up to five points in a bin.
    */
    class PointBin
    {
    public:
        PointBin(int max);
        virtual ~PointBin();

        /// Get the current count of items in this bin
        /// \return Count (zero to MaxPoints)
        int GetCnt() { return mCnt; }

        /// Get the maximum points we allow in this bin
        /// \return Maximum integer value
        int GetMax() { return mMax; }

        bool Add(Gdiplus::Point point);

        /// Get a stored point
        /// \param i Index to the point (0 to mCnt-1)
        /// \return Stored point value
        Gdiplus::Point Get(int i) { return mPoints[i]; }

        /// Get the next bin in the list
        /// \return Pointer to next bin or null if none
        std::shared_ptr<PointBin> GetNext() { return mNext; }

        /// Set the next bin in the list
        /// \param next Next pointer to set
        void SetNext(std::shared_ptr<PointBin> next) { mNext = next; }

    private:
        PointBin() = delete;

        /// Array to store the points
        Gdiplus::Point *mPoints;

        /// Maximum number of elements we can store in the array
        int mMax;

        /// Number of elements currently stored in array
        int mCnt = 0;

        /// Next bin
        std::shared_ptr<PointBin> mNext;
    };


    /// Pointer to the head of the linked list of bins
    std::shared_ptr<PointBin> mHead;

private:
    int MakeSize();


    /// Random number generator
    std::mt19937 mGen;

    /// Pointer to the tail of the linked list of bins (last node)
    std::shared_ptr<PointBin> mTail;


public:
	
	class PointIterator
	{
	public:
		/** Constructor
		* \param history The history we are iterating over 
		* \param bin Pointer to bin 
		* \param pos Position of iterator */
		PointIterator(CPointHistory* history, std::shared_ptr<PointBin> bin, int pos) : mHistory(history), mBin(bin), mPos(pos) {}

		/** Test for end of the iterator
		* \returns True if we this position equals not equal to the other position */
		bool operator!=(const PointIterator& other) const
		{
			return mBin != other.mBin;
		}

		/** Get position of bin
		* \returns Position of bin */
		Gdiplus::Point operator *() const { return mBin->Get(mPos); };

		/** Get position of bin
		* \returns Position of bin */
		const PointIterator& operator++()
		{
			if (mBin != nullptr)
			{
				mBin = mBin->GetNext();
			}

			return *this;
		}

	private:
		/// Collection being iterated over
		CPointHistory* mHistory;

		/// Bin position in collection
		std::shared_ptr<PointBin> mBin;

		/// Position of bin
		int mPos;
		
	};

	/** Get an iterator for the beginning of the collection
	* \returns Iter object at last location in the array */
	PointIterator begin() { return PointIterator(this, mHead, 0); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the front */
	PointIterator end() { return PointIterator(this, nullptr, 0); }

};

