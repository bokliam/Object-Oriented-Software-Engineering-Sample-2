/**
* \file TileLandscape.h
*
* \author Charles B. Owen
* \author Liam Bok
*
*  Class that implements a Landscape tile
*/

#pragma once

#include "Tile.h"


/**
*  A Landscape tile
*/
class CTileLandscape : public CTile
{
public:
	/// Constructor
    CTileLandscape(CCity *city);

    ///  Default constructor (disabled)
    CTileLandscape() = delete;

    ///  Copy constructor (disabled)
    CTileLandscape(const CTileLandscape &) = delete;

	/// Destructor
    ~CTileLandscape();
	
	/// Save function
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/// Load function
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor* visitor) override { visitor->VisitLandscape(this); }
};

