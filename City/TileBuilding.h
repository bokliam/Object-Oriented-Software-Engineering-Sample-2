/**
* \file TileBuilding.h
*
* \author Charles B. Owen
* \author Liam Bok
*
*  Class that implements a Building tile
*/

#pragma once

#include "Tile.h"


/**
*  A Building tile
*/
class CTileBuilding : public CTile
{
public:
	/// Constructor
    CTileBuilding(CCity *city);

    ///  Default constructor (disabled)
    CTileBuilding() = delete;

    ///  Copy constructor (disabled)
    CTileBuilding(const CTileBuilding &) = delete;

	/// Destructor
    ~CTileBuilding();

	/// Save function
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/// Load function
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CTileVisitor* visitor) override { visitor->VisitBuilding(this); }
};

