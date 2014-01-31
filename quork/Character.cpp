/* 
 * File:   Character.cpp
 * Author: TAbracadabra
 * 
 * Created on January 17, 2014, 9:37 PM
 */

#include "Character.h"

// Forward declarations

// Constructor
Character::Character() : health(100)
{
}

// Destructor
Character::~Character()
{
}


// Note The xPos, yPos, zPos variables and their get functions are inherrited from Entity.
/**
* The setCharacterPos() mutator function sets the X, Y, and Z coordinates of the Character object.
* It returns no values.
*@param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
*/
void Character::setCharacterPos(int x, int y, int z)
{
	xPos = x; yPos = y; zPos = z;
}

/**
	The setAttributes mutator() function sets the Characters attributes. It does not return anything.
	@param n - The Characters name as a string.
	@param mapsym - The Characters map symbol as a string.
	@param blk - Boolean that indicats if the Character is blocking.
				 False equals no which is the default for a gridsquare.  
*/
void Character::setAttributes(std::string n, std::string mapsym, bool blk)
{
	name = n; mapsymbol = mapsym; blocking = blk;
}

/**
* The getMapSymbol() accessor function returns the characters map symbol as a string.
*/
std::string Character::getMapSymbol() const
{
	return mapsymbol;
}


/**
* The getCharacterName() accessor function returns the characters name as a string.
*/
std::string Character::getCharacterName() const
{
	return name;
}