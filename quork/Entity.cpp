/*
* File:   Entity.cpp
* Author: TAbracadabra
*
* Created on January 25, 2014, 9:46 PM
*/

#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}


/**
* The getName() accessor function returns the entities name as a string.
@return - Entities name as a string.
*/
std::string Entity::getName() const
{
	return name;
}


/**
* The setName() mutator function modifies the entities name.
@param name - The entities name as a string.
*/
void Entity::setName(std::string name)
{
	name = name;
}


/**
* The getXCoord() accessor function returns the entities X coordinate as an int.
@return The entities X coordinate.
*/
int Entity::getXCoord() const
{
	return xPos;
}


/**
* The setXCoord() mutator function modifies the entities X coordinate as an int.
@param x - The X coordinate as an int.
*/
void Entity::setXCoord(int x)
{
	xPos = x;
}


/**
* The getYCoord() accessor function returns the entities Y coordinate as an int.
@return The entities Y coordinate.
*/
int Entity::getYCoord() const
{
	return yPos;
}


/**
* The setYCoord() mutator function modifies the entities Y coordinate.
@param y - The Y coordinate as an int.
*/
void Entity::setYCoord(int y)
{
	yPos = y;
}


/**
* The getZCoord() accessor function returns the entities Z coordinate as an int.
@return The entities Z coordinate.
*/
int Entity::getZCoord() const
{
	return zPos;
}


/**
* The setZCoord() mutator function modifies the entities Z coordinate.
@param z - The Z coordinate as an int.
*/
void Entity::setZCoord(int z)
{
	zPos = z;
}
