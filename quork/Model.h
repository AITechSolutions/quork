/*
* File:   Model.h
* Author: TAbracadabra
*
* Created on January 14, 2014, 5:14 PM
*/

#ifndef MODEL_H
#define	MODEL_H
#pragma once

#include "Engine.h"
#include "Map.h"
#include "Character.h"

#include <iostream>
#include <string>
#include <unordered_map>
class Model
{
// Globals
public:
	bool isalive;
	
	Map GameMap; Map* pMap = &GameMap;						// Instantiate and assign pointer to the Game Map
	//Map GameMap3D; Map* pMap3D = &GameMap3D;				// Instantiate and assign pointer to the actual Game Map matrix

	Character PC; Character* pPlayerCharacter = &PC;		// Instantiate and assign pointer to the Player Character

	Character* pAnyCharacter;
	std::string anystring;

	Engine* pGameEngine;

	Model(Engine *GameEngine);
	~Model();

	std::string getPlayerXYZLocation() const;
	void setCharacterPosition(Character* character, int x, int y, int z);
	void setMapGridOccupant(Character* occupant, int x, int y, int z);
	bool updateDestxyzArray(Character* pCharacter, int xoffset, int yoffset, int zoffset);
	void showAdjacentGSProps(Character* pCharacter, int xoffset, int yoffset, int zoffset);
	void showGsEprops(int xoffset, int yoffset, int zoffset);
	void showMapLocItem(int xoffset, int yoffset, int zoffset);
	void showMapLocOccupant(int xoffset, int yoffset, int zoffset);
	void moveCharacter(Character* pCharacter, int xoffset, int yoffset, int zoffset);
	bool inMapBoundary(int destX, int destY, int destZ);
	bool collisionDetect(Character* pCharacter, int xoffset, int yoffset, int zoffset);
private:
	std::string msgperfix;
	int xyzArray[3];
	void initPlayerCharacter();
};

#endif	/* MODEL_H */