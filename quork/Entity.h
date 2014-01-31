/*
* File:   Entity.h
* Author: TAbracadabra
*
* Created on January 25, 2014, 9:46 PM
*/

#ifndef ENTITY_H
#define	ENTITY_H

#pragma once

#include <string>

class Entity
{
public:
	std::string name;
	int xPos;
	int yPos;
	int zPos;

	Entity();
	~Entity();

	std::string getName() const;
	void setName(std::string name);
	int getXCoord() const;
	void setXCoord(int x);
	int getYCoord() const;
	void setYCoord(int y);
	int getZCoord() const;
	void setZCoord(int z);
private:

};

#endif	/* ENTITY_H */