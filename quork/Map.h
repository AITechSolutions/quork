/*
* File:   Map.h
* Author: TAbracadabra
*
* Created on January 17, 2014, 8:51 PM
*/

#ifndef MAP_H
#define	MAP_H

#pragma once

#include <string>
#include <vector>
#include "Entity.h"

class Map
{
private:
	void initMap();
public:
	struct gridSquare
	{
		std::string name = "ground";
		std::string terrain = "a grass covered";
		std::string areatype = "clearing";
		bool blocking = false;
		std::string symbol = "";
		std::string occupant = "";
		std::string item = "";
		Entity* pEntity;	// Superclass of Character
	};
	gridSquare baseGS;
	int mapSize;
	int mapXDim;
	int mapYDim;
	int mapZDim;

	std::vector<gridSquare>  mapv;
	//std::vector<gridSquare> baseGS;  //Not used yet
	std::vector<std::vector<std::vector<gridSquare> > > Map3D;
	//std::vector<std::vector<std::vector<gridSquare> > >* pMap3D;  //Not used yet

	Map();
	~Map();

	std::string getOccupant(int x, int y, int z) const;
	void setOccupant(int x, int y, int z, std::string ostr);
	std::string getSymbol(int x, int y, int z) const;
	void setSymbol(int x, int y, int z, std::string sym);
	bool gsIsBlocking(int x, int y, int z) const;
	std::string getItem(int x, int y, int z) const;
	void setItem(int x, int y, int z, std::string item);
	void setEntity(Entity* pEntity, int x, int y, int z);
	void setGsEnvAttributes(int x, int y, int z, std::string name, std::string terrain, std::string areatype, bool blk, std::string sym);
	void addThickForest(int x, int y, int z);
};

#endif	/* MAP_H */