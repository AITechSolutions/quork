/*
* File:   Map.cpp
* Author: TAbracadabra
*
* Created on January 17, 2014, 8:51 PM
*/

#include "Map.h"
#include <iostream>

// Fwd Declare

// Constructor
Map::Map() : mapXDim(7), mapYDim(7), mapZDim(3), Map3D(mapXDim, std::vector<std::vector<gridSquare> >(mapYDim, std::vector <gridSquare>(mapZDim)))
{
	initMap();
}

// Destructor
Map::~Map()
{
}

/**
* initMap() function customizes the map by updating gridSquares.
* It takes no parameters and does not return anything.	
*/
void Map::initMap()
{
	addThickForest(3, 2, 1);
	addThickForest(2, 3, 1);
	addThickForest(0, 0, 1);
	setItem(5,2,1, "a golden key");					// Only for interface look testing - Need an actual item object.
	setItem(4, 4, 1, "an axe");						// Only for interface look testing - Need an actual item object.
	setOccupant(2, 5, 1, "an ogre");				// Only for interface look testing - Need an actual Entity object.
	setOccupant(3, 1, 1, "a beautiful princess");	// Only for interface look testing - Need an actual Entity object.
	setGsEnvAttributes(4,1,1, "Castle", "a moat", "with a castle in the distance", true, "CM");
}

/**
* The getOccupant() accesor method returns the value of the occupant field
* of the grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @return - The value of the occupant field as a string.
*/
std::string Map::getOccupant(int x, int y, int z) const
{
	return Map3D[x][y][z].occupant;
}
///////////////////////////////////////////////////////////

/**
* The setOccupant() mutator function sets the value of the occupant field
* in the grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @param ostr - The value of the occupant field as a string.
*/
void Map::setOccupant(int x, int y, int z, std::string ostr)
{
	Map3D[x][y][z].occupant = ostr;
}


/**
* The getSymbol accessor function returns the symbol field
* of the grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @return - The symbol of the gridSquare as a string.
*/
std::string Map::getSymbol(int x, int y, int z) const
{
	return Map3D[x][y][z].symbol;
}


/**
* The setSymbol() mutator function sets the symbol in the
* grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @param sym - The symbol of the gridSquare as a string.
*/
void Map::setSymbol(int x, int y, int z, std::string sym)
{
	Map3D[x][y][z].symbol = sym;
}


/**
* The gsIsBlocking() constant accessor function returns the value of the blocking
* field in the grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @return - The boolean value of the blocking field.
*/
bool Map::gsIsBlocking(int x, int y, int z) const
{
	return Map3D[x][y][z].blocking;
}


/**
* The getItem() accessor function returns the value of the item string
* in the grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @return - The item value as a string.
*/
std::string Map::getItem(int x, int y, int z) const
{
	return Map3D[x][y][z].item;
}


/**
* The setItem() mutator function sets the item name in the
* grid square struct at the specified X, Y, and Z location.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @param item - The item value as a string.
*/
void Map::setItem(int x, int y, int z, std::string item)
{
	Map3D[x][y][z].item = item;
}


/**
* The setEntity() mutator function sets the entity or character in the
* grid square struct at the specified X, Y, and Z location.
* It returns no values.
* @param pEntity
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
*/
void Map::setEntity(Entity* pEntity, int x, int y, int z)
{
	Map3D[x][y][z].pEntity = pEntity;
}


/**
* The setGsEnvAttributes() function sets environmental attrinutes in the map's gridSquare struct. 
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
* @param name - The name of the location as a string.
* @param terrain - The terrain descriptor used for console output as a string.
* @param areatype - The area type descriptor used for console output as a string.
* @param blk - A boolean attribute used to determine if this map location is blocking. False = not blocking.
* @param sym - The symbol used to describe the map location as a string.
*/
void Map::setGsEnvAttributes(int x, int y, int z, std::string name, std::string terrain, std::string areatype, bool blk, std::string sym)
{
	Map3D[x][y][z].name = name;
	Map3D[x][y][z].terrain = terrain;
	Map3D[x][y][z].areatype = areatype;
	Map3D[x][y][z].blocking = blk;
	Map3D[x][y][z].symbol = sym;
}


/**
* The  addThickForest() function sets a gridsquares environmental parameters.
* @param x - The X coordinate as an int.
* @param y - The Y coordinate as an int.
* @param z - The Z coordinate as an int.
*/
void Map::addThickForest(int x, int y, int z)
{
	Map3D[x][y][z].name = "Thick Forest";
	Map3D[x][y][z].terrain = "a leaf and stick covered";
	Map3D[x][y][z].areatype = "Woodland";
	Map3D[x][y][z].blocking = true;
	Map3D[x][y][z].symbol = "TF";
}