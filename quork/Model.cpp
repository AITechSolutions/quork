/*
* File:   Model.cpp
* Author: TAbracadabra
*
* Created on January 14, 2014, 5:14 PM
*/

#include "Model.h"

#include <iostream>
#include <sstream>
#include <math.h>

// Forward declarations

// Constructor
Model::Model(Engine *GameEngine) : isalive(true)
{
	initPlayerCharacter();
}

// Destructor
Model::~Model()
{
}

/////////////////////////////////////////////////////////////////////
/*
* The initPlayerCharacter() function sets the players attributes and initial map location.
*/
void Model::initPlayerCharacter()
{
	// Player init data settings:
	std::string name = "a Player";
	std::string symbol = "PC";
	bool blocking = true;
	int x = 3; int y = 3; int z = 1;

	pPlayerCharacter->setAttributes(name, symbol, blocking);
	Model::setCharacterPosition(pPlayerCharacter, x, y, z);

	// Set the character's symbol in grid square struct symbol field.
	// Can be used for a console visual representation of the map.
	pMap->setSymbol(x, y, z, pPlayerCharacter->getMapSymbol());

	// Set character name as an occupant value in grid square struct occupant field
	setMapGridOccupant(pPlayerCharacter, x, y, z);
	
	// We can use this to set the pointer to the character in the Map struct
	pMap->setEntity(pPlayerCharacter, x, y, z);
}

/////////////////////////////////////////////////////////////////////

/**
* The getPlayerXYZLocation() accessor function builds a console displayable string
* of the players X, Y, and Z coordinates. It takes no parameters.
* @return A string of the players X, Y, and Z coordinates.
*/
std::string Model::getPlayerXYZLocation() const
{
	std::stringstream ss;
	ss << pPlayerCharacter->getXCoord();
	ss << ",";
	ss << pPlayerCharacter->getYCoord();
	ss << ",";
	ss << pPlayerCharacter->getZCoord();
	return ss.str();
}

/////////////////////////////////////////////////////////////////////

/**
* The setCharacterPosition() mutator function sets Characters X, Y and Z corrdinates.
* @param Pointer to the Character Object instance. It returns no values.
* @param x
* @param y
* @param z
*/
void Model::setCharacterPosition(Character* character, int x, int y, int z)
{
	character->setCharacterPos(x, y, z);
}

/////////////////////////////////////////////////////////////////////


/**
* The setMapGridOccupant Sets the occupant field of the struct in the 3D Map
* at the specified X, Y, and Z coordinates. It returns no values.
* @param occupant A pointer to the specific Entity or Character object.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
*/
void Model::setMapGridOccupant(Character* occupant, int x, int y, int z)
{
	pMap->setOccupant(x, y, z, occupant->getCharacterName());
}


/**
* The updateDestxyzArray() function updates the xyzArray with the destination coordinates.
* @param pCharacter
* @param xoffset
* @param yoffset
* @param zoffset
* @return
*/
bool Model::updateDestxyzArray(Character* pCharacter, int xoffset, int yoffset, int zoffset)
{
	if (&xyzArray == 0)		// If the array pointer is NULL
		return false;
	else
	{
		xyzArray[0] = pCharacter->getXCoord() + xoffset;
		xyzArray[1] = pCharacter->getYCoord() + yoffset;
		xyzArray[2] = pCharacter->getZCoord() + zoffset;
	}
	return true;
}


/**
* The showAdjacentGSProps() function is used to show information about an adjacent map location.
* @param pCharacter
* @param xoffset
* @param yoffset
* @param zoffset
*/
void Model::showAdjacentGSProps(Character* pCharacter, int xoffset, int yoffset, int zoffset)
{
	int destX = pCharacter->getXCoord() + xoffset;
	int destY = pCharacter->getYCoord() + yoffset;
	int destZ = pCharacter->getZCoord() + zoffset;

	if (inMapBoundary(destX, destY, destZ))
	{
		showGsEprops(xoffset, yoffset, zoffset);
		showMapLocOccupant(xoffset, yoffset, zoffset);
		showMapLocItem(xoffset, yoffset, zoffset);
	}
	else
	{
		std::cout << "You see an impenetrable, luminescent, light blue force field." << std::endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////



/**
* The showGsEprops() function builds and sends to the console a string showing
* the gridSquares environmental properties. The wording is changed if the XYZ
* coordinates are the same as the location of the player. The Player Character is assumed.
* It returns no values.
* @param xoffset
* @param yoffset
* @param zoffset
*/
void Model::showGsEprops(int xoffset, int yoffset, int zoffset)
{
	int destX = pPlayerCharacter->getXCoord() + xoffset;
	int destY = pPlayerCharacter->getYCoord() + yoffset;
	int destZ = pPlayerCharacter->getZCoord() + zoffset;

	msgperfix = (xoffset == 0 && yoffset == 0 && zoffset == 0) ? "You are in " : "You see ";
	std::cout << msgperfix << pMap->Map3D[destX][destY][destZ].terrain << " " <<
		pMap->Map3D[destX][destY][destZ].areatype << "." << std::endl;
}


/**
* The showMapLocItem() function builds and sends to the console a string showing
* any items found at the location specified in reference to the players location.
* @param xoffset
* @param yoffset
* @param zoffset
*/
void Model::showMapLocItem(int xoffset, int yoffset, int zoffset)
{
	int destX = pPlayerCharacter->getXCoord() + xoffset;
	int destY = pPlayerCharacter->getYCoord() + yoffset;
	int destZ = pPlayerCharacter->getZCoord() + zoffset;

	std::string item = pMap->getItem(destX, destY, destZ);
	if (item != "")
	{
		bool thisgs = (xoffset == 0 && yoffset == 0 && zoffset == 0);
		msgperfix = (thisgs) ? "You see " : "There is ";

		std::cout << msgperfix << item << "." << std::endl;
	}
}


/**
* The showMapLocOccupant() function builds and sends to the console a string showing
* any occupant found at the location specified in reference to the players location.
* @param destX
* @param destY
* @param destZ
*/
void Model::showMapLocOccupant(int xoffset, int yoffset, int zoffset)
{
	int destX = pPlayerCharacter->getXCoord() + xoffset;
	int destY = pPlayerCharacter->getYCoord() + yoffset;
	int destZ = pPlayerCharacter->getZCoord() + zoffset;

	std::string occupant = pMap->getOccupant(destX, destY, destZ);
	if (occupant != "")
	{
		bool thisgs = (xoffset == 0 && yoffset == 0 && zoffset == 0);
		msgperfix = (thisgs) ? "You see " : "There is ";

		std::cout << msgperfix << occupant << "." << std::endl;
	}
}


/**
* The moveCharacter() function updates the players coordinates and map attributes if there is no collision.
* If ther is a collision it informs the player via console output. This function does not return any data.
* @param pCharacter - Character(or Entity) pointer to the player character object.
* @param xoffset - An int specifying the X offset from the current Character(or Entity) objects position.
* @param yoffset - An int specifying the Y offset from the current Character(or Entity) objects position.
* @param zoffset - An int specifying the Z offset from the current Character(or Entity) objects position.
*/
void Model::moveCharacter(Character* pCharacter, int xoffset, int yoffset, int zoffset)
{
	// Determine the destination map location - update xyzArray in place
	updateDestxyzArray(pCharacter, xoffset, yoffset, zoffset);

	// Check for collision
	if (collisionDetect(pCharacter, xoffset, yoffset, zoffset))
	{
		std::cout << "You can\'t go there!" << std::endl;
	}
	else
	{
		// Now we can move the character
		// First we remove the occupant from the current grid sauare
		pMap->setOccupant(pCharacter->getXCoord(), pCharacter->getYCoord(), pCharacter->getZCoord(), "");
		//	pMap->setOccupant(convertXYtoindex(pCharacter->getXCoord(), pCharacter->getYCoord()), "");

		// Set the new x and y coordinates in the character object
		pCharacter->setCharacterPos(xyzArray[0], xyzArray[1], xyzArray[2]);
	
		// Set the occupant in the destination grid square
		pMap->setOccupant(xyzArray[0], xyzArray[1], xyzArray[2], pCharacter->getCharacterName());


		// Show the current gridsquare properties
		if (pCharacter == pPlayerCharacter)
		{
			showGsEprops(0, 0, 0);
			//showGsOccupant(gs);			//As occupants are most likely blocking, do not need to show.
			showMapLocItem(0, 0, 0);

			// Show properties of adjacent squares
			std::cout << "\nLooking North: \t"; showAdjacentGSProps(pCharacter, 0, -1, 0);
			std::cout << "Looking West: \t"; showAdjacentGSProps(pCharacter, 1, 0, 0);
			std::cout << "Looking South: \t"; showAdjacentGSProps(pCharacter, 0, 1, 0);
			std::cout << "Looking East: \t"; showAdjacentGSProps(pCharacter, -1, 0, 0);
		}
	}
}


/**
* The inMapBoundary() function checks if the provided coordinates are whithin the map boundaries.
* @param destX
* @param destY
* @param destZ
* @return - A Boolean indicating the coordinates are in bounds. True indicates whithin the map boundaries.
*/
bool Model::inMapBoundary(int destX, int destY, int destZ)
{
	if (destX < pMap->mapXDim &&		// Handles when already on a X boundary gs
		destX > 0 &&
		destY < pMap->mapYDim &&		// Handles when already on a Y boundary gs
		destY > 0 &&
		destZ < pMap->mapZDim &&		// Handles when already on a Z boundary gs
		destZ > 0)
		return true;
	else
		return false;
}


/**
* The collisionDetect() function detects collisions with blocking map entities and gridSquares.
* @param pCharacter - Character(or Entity) pointer to the player character object.
* @param xoffset - An int specifying the X offset from the current Character(or Entity) objects position.
* @param yoffset - An int specifying the Y offset from the current Character(or Entity) objects position.
* @param zoffset - An int specifying the Z offset from the current Character(or Entity) objects position.
* @return - A boolean value reflecting the collision status. False indicates no collision.
*/
bool Model::collisionDetect(Character* pCharacter, int xoffset, int yoffset, int zoffset)
{
	int destX = pCharacter->getXCoord() + xoffset;
	int destY = pCharacter->getYCoord() + yoffset;
	int destZ = pCharacter->getZCoord() + zoffset;
	
	if (pGameEngine->collisionHandler())
	{
		// Do somethig else - For special handling by GameEngine
	}
	else
	{
		if (inMapBoundary(destX, destY, destZ) &&					// Check if within the map boundaries
			pMap->gsIsBlocking(destX, destY, destZ) == 0)			// Check if the destination is not blocking
		{
			return false;
		}
		else
			return true;
	} return false;
}
