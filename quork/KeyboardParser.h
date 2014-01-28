/*
* File:   KeyboardParser.h
* Author: TAbracadabra
*
* Created on January 14, 2014, 7:35 PM
*/

#ifndef KEYBOARDPARSER_H
#define	KEYBOARDPARSER_H

#include <string>
#include <vector>
#include <map>
#include "Model.h"

#pragma once


class KeyboardParser
{
public:
	bool isalive;
	std::vector<std::string> msg;
	
	KeyboardParser();
	~KeyboardParser();

	std::vector<std::string> parseCommand(std::string s);
	std::vector<std::string> cmdMsgOut;
	std::vector<std::string>*  pcmdMsgOut = &cmdMsgOut;
private:

	std::map<std::string, std::string> xmap;
	std::map<std::string, std::string>::iterator xmap_it;
	std::map<std::string, std::string> ymap;
	std::map<std::string, std::string>::iterator ymap_it;
	std::map<std::string, std::string> zmap;
	std::map<std::string, std::string>::iterator zmap_it;
	void setCmdDestination(std::vector<std::string>* pcmdMsgOut);
};

#endif	/* KEYBOARDPARSER */