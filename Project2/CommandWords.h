#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.
 * 
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 * @version 2015.10.03 Gracie Carver-Dews
 */
 
#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H
class CommandWords
{
private:
	vector<string> validCommands;

public:
	CommandWords();
	bool isCommand(string aString);
	void showAll();

};
#endif
