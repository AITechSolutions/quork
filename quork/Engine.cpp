/*
* File:   Engine.cpp
* Author: TAbracadabra
*
* Created on January 14, 2014, 3:31 PM
*/

#include "Engine.h"
#include <iostream>



Engine::Engine()
{
	isalive = true;
	//std::cout << "Hi There - Game Engine at your service" << std::endl;
}


Engine::~Engine()
{
}

/*
	
*/
bool Engine::collisionHandler()
{
	// std::cout << "Debug Message - GameEngine\'s custom collision handler\n" << std::endl;
	return false;
}
