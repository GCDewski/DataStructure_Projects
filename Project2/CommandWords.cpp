#include "CommandWords.h"

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
 

CommandWords::CommandWords() //constuctor
{	
	// a vector that holds all valid command words
	validCommands.push_back("go");
	validCommands.push_back("quit");
	validCommands.push_back("help");
	validCommands.push_back("take");
}

/**
 * Check whether a given String is a valid command word. 
 * @return true if it is, false if it isn't.
 */
bool CommandWords::isCommand(string aString)
{
    for(int i = 0; i < validCommands.size(); i++) 
    {
        if(validCommands[i] == aString)
            return true;
    }
    
    // if we get here, the string was not found in the commands
    return false;
}

/**
 * Print all valid commands to System.out.
 */
void CommandWords::showAll()
{
	cout << "Valid Commands:" << endl;
	for(vector<string>::iterator command = validCommands.begin();
		command != validCommands.end();
		command++)
	{
		string word = *command;
		cout << word << endl;
	}
}