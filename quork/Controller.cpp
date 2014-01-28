/*
* File:   Controller.cpp
* Author: TAbracadabra
*
* Created on January 14, 2014, 3:39 PM
*/

#include "Controller.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>		// For use of std::transform

using namespace std;

Controller::Controller(Engine* GameEngine, Model* World) : pGameEngine(GameEngine), pWorldModel(World), isalive(true)
//Controller::Controller(Engine* GameEngine) : pGameEngine(GameEngine), isalive(true)
{
	//std::cout << "Hi There - Game Controller at your service" << std::endl;
	//std::cout << "Game Controller has a pointer to the GameEngine object located at: " << pGameEngine << std::endl;
	//std::cout << "Game Controller has a pointer to the World Model object located at: " << pWorld << std::endl;
	// Instantiate the Keyboard Input Parser and create a pointer to it

	pWorldModel = World;
	KeyboardParser KParser;
	pKParser = &KParser;
	keyboardParserChk();

	gamestarted = true;
	gameLoop();
}


Controller::~Controller()
{
}

/////////////////////////////////////////////////////////////////////
/*
* The keyboardParserChk() function insures the KeyboardParser object was created.
*/
void Controller::keyboardParserChk()
{
	if (!pKParser->isalive)
	{
		std::cout << "ERROR: The Keyboard Parser instance was not created\n" << pKParser << std::endl;
	}
}


/**
* The getInput function gets user input as a string, converts it to lower case and calls parseInput().
* Input validation is done to insure the input string is not empty. If it is empty, returns.
*/
void Controller::getInput()
{
	cout << "Quork>";
	getline(cin, instr);
	
	if (instr.length() == 0)
		return;
	else
	{
		std::cout << std::endl;
		std::transform(instr.begin(), instr.end(), instr.begin(), ::tolower);
		parseInput(instr);
		std::cout << std::endl;
	}
}


/**
* The parseImput function .....
*/
void Controller::parseInput(string sin)
{
	// Process common input items that do not need significant parsing
	if (instr.compare("quit") == 0 || instr.compare("bye") == 0)
		gamestarted = false;
	else if (instr.compare("where am i") == 0)
	{
		std::cout << "Your X,Y coordinates are " << pWorldModel->getPlayerXYZLocation() << endl;
	}
	else
	{
		// Pass input to KeyboardParser for command decoding
		cmdMsg = pKParser->parseCommand(sin);

		if (cmdMsg.at(1).compare("0") != 0)			// Insure command field of the message has a valid command

		{
			if (cmdMsg.at(0).compare("0") == 0)
			{
				// delete the destination from the command message and call the destination dispatcher
				cmdMsg.erase(cmdMsg.begin());
				dispatchWorldModelMsg(cmdMsg);
			}
			else if (cmdMsg.at(0).compare("1") == 0)
			{
				cmdMsg.erase(cmdMsg.begin());
				dispatchGameEngineMsg(cmdMsg);
			}
		}
	}
}


/**
* The dispatchWorldModelMsg() function calls the appropriate function in the World Model
* based upon the command.
* @param cmsg - A 1D vector of strings that holds the command message.
*/
void Controller::dispatchWorldModelMsg(std::vector<std::string> &cmsg)
{
	// convert x and y to int
	int x = cnvrtVectStrElementToInt(cmsg, 1);
	int y = cnvrtVectStrElementToInt(cmsg, 2);
	int z = cnvrtVectStrElementToInt(cmsg, 3);

	switch (std::atoi(cmdMsg.at(0).c_str()))
	{
	case 1:																	// Look Command
		pWorldModel->showAdjacentGSProps(pWorldModel->pPlayerCharacter, x, y, z);
		break;
	case 2:
		pWorldModel->moveCharacter(pWorldModel->pPlayerCharacter, x, y, z);	// Move Command
		break;
	default: 
		std::cout << "WorldModel Dispacher can not determine the intention of this command" << endl;
	}
}

/**
* The dispatchGameEngineMsg() function calls the appropriate function in the Game Engine
* based upon the command.
* @param cmsg - A 1D vector of strings that holds the command message.
*/
void Controller::dispatchGameEngineMsg(std::vector<std::string> &cmsg)
{
	std::cout << "The GameEngine Dispacher recieved command elememt 0 = " << cmsg.at(0) << std::endl;
	std::cout << "The GameEngine Dispacher recieved command elememt 1 = " << cmsg.at(1) << std::endl;
	std::cout << "The GameEngine Dispacher recieved command elememt 2 = " << cmsg.at(2) << std::endl;
}


/*
	cnvrtVectStrElementToInt() function returns the value of a string element in a vector
	converted to an integer. If a minus sign preceeds the numeric the returned int will be negative.
	@param &vec - a reference to the vector.
	@param index - The index of the string element to be converted.
	@return - The string converted to a signed integer.
*/
int Controller::cnvrtVectStrElementToInt(std::vector<std::string> &vec, int index)
{
	return std::atoi(cmdMsg.at(index).c_str());;
}


/*
* The gameLoop() function is the main game loop implemented as a do-while.
* Conditions(so far) for the loop to fall through/exit is the boolean gamestarted identifier == false. 
*/
int Controller::gameLoop()
{
	do
	{
		getInput();
	} while (gamestarted);
	
	std::cout << "The game has ended,\nThanks for playing!" << std::endl;
	return 0;
}
