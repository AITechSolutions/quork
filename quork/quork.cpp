/*
* File:   quork.cpp
* Author: TAbracadabra
*
* Created on January 13, 2014, 11:31 PM
*/

#include <cstdlib>
#include <iostream>
#include "Engine.h"
#include "Model.h"
#include "Controller.h"

using namespace std;

/*
*
*/
int main(int argc, char** argv)
{
	cout << "Welcome to the world of Quork\n" << endl;

	// Instantiate and check existance of the Engine
	Engine GameEngine;
	Engine * pGameEngine = &GameEngine;
	if (!pGameEngine->isalive)
	{
		cout << "ERROR: The game engine instance was not created\n";
		return 1;
	}

	
	Model World(GameEngine);
	Model * pWorld = &World;
	if (!pWorld->isalive)
	{
		cout << "ERROR: The World Model instance was not created\n";
		return 1;
	}

	Controller GameController(GameEngine, World);
	Controller * pGameController = &GameController;
	if (!pGameController->isalive)
	{
		cout << "ERROR: The Game Controller instance was not created\n";
		return 1;
	}

	return 0;
}