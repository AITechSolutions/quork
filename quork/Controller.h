/*
* File:   Controller.h
* Author: TAbracadabra
*
* Created on January 14, 2014, 3:39 PM
*/

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "Engine.h"
#include "Model.h"
#include "KeyboardParser.h"

#include <string>
#include <vector>

#pragma once

class Controller
{
public:
	bool gamestarted;
	bool isalive;
	Engine* pGameEngine;
	Model* pWorldModel;
	KeyboardParser* pKParser;
	std::string instr;
	std::vector<std::string> cmdMsg;
	
	Controller(Engine &pGameEngine, Model &pWorld);
	~Controller();

	int cnvrtVectStrElementToInt(std::vector<std::string> &vec, int index);

private:
	void keyboardParserChk();
	void getInput();
	void parseInput(std::string sin);
	void dispatchWorldModelMsg(std::vector<std::string> &cmsg);
	void dispatchGameEngineMsg(std::vector<std::string> &cmsg);
	int gameLoop();
};

#endif	/* CONTROLLER_H */
