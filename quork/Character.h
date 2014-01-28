/*
* File:   Character.h
* Author: TAbracadabra
*
* Created on January 17, 2014, 9:37 PM
*/

#ifndef CHARACTER_H
#define	CHARACTER_H

#pragma once

#include "Entity.h"
#include <string>
#include <vector>

class Character: public Entity
{
public:
	std::string name;
	std::string mapsymbol;

	Character();
	~Character();

	void setCharacterPos(int x, int y, int z);
	int getXCoord() const;
	int getYCoord() const;
	int getZCoord() const;
	std::string getCharacterName() const;

	std::string getMapSymbol() const;
	void setAttributes(std::string n, std::string mapsym, bool blk);


private:
	int health;
	bool blocking;
	std::vector<std::string> inventory;

};

#endif	/* CHARACTER_H */