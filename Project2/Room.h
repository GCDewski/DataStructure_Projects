#include "Item.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * Class Room - a room in an adventure game.
 *
 * This class is part of the "World of Zuul" application. 
 * "World of Zuul" is a very simple, text based adventure game.  
 *
 * A "Room" represents one location in the scenery of the game.  It is 
 * connected to other rooms via exits.  For each existing exit, the room 
 * stores a reference to the neighboring room.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 * @version 2015.02.10 Gracie Carver-Dews
 */

#ifndef ROOM_H
#define ROOM_H
class Room
{
private:
	string description;
	Item * item;
	map<string, Room *> exits; // stores exits of this room.

public:
	Room(string descr, Item * item);
	void setExit(string direction, Room* neighbor);
	string getShortDescription();
	string getLongDescription();
	string getExitString();
	Room * getExit(string direction);
	Item* getItem();
};
#endif
