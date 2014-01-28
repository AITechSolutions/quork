/*
* File:   KeyboardParser.cpp
* Author: TAbracadabra
*
* Created on January 14, 2014, 7:35 PM
*/

#include "KeyboardParser.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

KeyboardParser::KeyboardParser()
{
	isalive = true;
	// Map of direction to x an y offsets
	xmap["down"] = "0";
	ymap["down"] = "0";
	zmap["down"] = "0";

	xmap["north"] = "0";
	ymap["north"] = "-1";
	zmap["north"] = "0";

	xmap["south"] = "0";
	ymap["south"] = "1";
	zmap["south"] = "0";

	xmap["east"] = "-1";
	ymap["east"] = "0";
	zmap["east"] = "0";

	xmap["west"] = "1";
	ymap["west"] = "0";
	zmap["west"] = "0";
}


KeyboardParser::~KeyboardParser()
{
}

std::vector<std::string> KeyboardParser::parseCommand(std::string s)
{
	msg.clear();
	cmdMsgOut.clear();
	std::string temp;
	// std::cout << "The string length is: " << s.length() << std::endl;

	// Parse the input string storing each word as an element of the vector::msg
	stringstream str(s);
	while (str >> temp)
		msg.push_back(temp);
	// Now msg is a vector containing each word in the input command

	// Set the destination of the command 0 = WorldModel, 1 = GameEngine
	setCmdDestination(pcmdMsgOut);

	// We want to set the first element to the command group
	// ***** These assume a 2 word command. May want to check the length to be sure so we can split up larger commands

	// Look = 1, Move = 2, etc...
	
	if (msg.front().compare("look") == 0)
	{
		// cout << "Command is Look which is command 1" << endl;
		cmdMsgOut.push_back("1");

		// Check if the X direction is valid, if not set the command field to 0 indicating it is invalid
		if (xmap.find(msg.at(1)) != xmap.end())
			cmdMsgOut.push_back(xmap.find(msg.at(1))->second);
		else
		{
			std::cout << "I don\'t know of a direction called " << msg.at(1) <<
				",\nso you can\'t look that way!" << endl;
			cmdMsgOut.at(1) = "0"; return cmdMsgOut;
		}
			
		// Check if the Y direction is valid, if not set the command field to 0 indicating it is invalid
		if (xmap.find(msg.at(1)) != xmap.end())
			cmdMsgOut.push_back(ymap.find(msg.at(1))->second);
		else
		{
			std::cout << "I don\'t know of a direction called " << msg.at(1) <<
				",\nso you can\'t look that way!" << endl;
			cmdMsgOut.push_back("0"); return cmdMsgOut;
		}

		// Check if the Z direction is valid, if not set the command field to 0 indicating it is invalid
		if (xmap.find(msg.at(1)) != xmap.end())
			cmdMsgOut.push_back(zmap.find(msg.at(1))->second);
		else
		{
			std::cout << "I don\'t know of a direction called " << msg.at(1) <<
				",\nso you can\'t look that way!" << endl;
			cmdMsgOut.push_back("0"); return cmdMsgOut;
		}
			
	}
	else if (msg.front().compare("go") == 0)
	{
		cmdMsgOut.push_back("2");

		// Check if the X direction is valid, if not set the command field to 0 indicating it is invalid
		if (xmap.find(msg.at(1)) != xmap.end())
			cmdMsgOut.push_back(xmap.find(msg.at(1))->second);
		else
		{
			std::cout << "I don\'t know of a direction called " << msg.at(1) <<
				",\nso you cant go that way!" << endl;
			cmdMsgOut.at(1) = "0"; return cmdMsgOut;
		}

		// Check if the Y direction is valid, if not set the command field to 0 indicating it is invalid
		if (xmap.find(msg.at(1)) != xmap.end())
			cmdMsgOut.push_back(ymap.find(msg.at(1))->second);	
		else
		{
			std::cout << "I don\'t know of a direction called " << msg.at(1) <<
				",\nso you cant go that way!" << endl;
			cmdMsgOut.push_back("0"); return cmdMsgOut;
		}

		// Check if the Z direction is valid, if not set the command field to 0 indicating it is invalid
		if (xmap.find(msg.at(1)) != xmap.end())
			cmdMsgOut.push_back(zmap.find(msg.at(1))->second);
		else
		{
			std::cout << "I don\'t know of a direction called " << msg.at(1) <<
				",\nso you cant go that way!" << endl;
			cmdMsgOut.push_back("0"); return cmdMsgOut;
		}
	}
	else
	{
		// Check if the verb is valid, if not set the command field to 0 indicating it is invalid
		cmdMsgOut.push_back("0");
		std::cout << "I don\'t know the verb: " << msg.front() <<
			",\nso you can\'t " << msg.front() << "!"<< std::endl;
	}
	
	return cmdMsgOut;
}

void KeyboardParser::setCmdDestination(std::vector<std::string>* pcmdMsg)
{
	// Set the default destination to WorldModel ("0")
	pcmdMsg->push_back("0");
}