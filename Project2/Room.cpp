#include "Room.h"


/**
* Create a room described "description". Initially, it has
* no exits. "description" is something like "a kitchen" or
* "an open court yard".
* @param description The room's description.
*/
Room::Room(string descr, Item * i) //constructor
{
	description = descr;
	item = i;
}

/**
* Define an exit from this room.
* @param direction The direction of the exit.
* @param neighbor  The room to which the exit leads.
*/
void Room::setExit(string direction, Room *neighbor)
{
	exits.insert(pair<string,Room*>(direction, neighbor));
}

/**
 * @return The short description of the room
 * (the one that was defined in the constructor).
 */
string Room::getShortDescription()
{
	return description;
}

/**
 * Return a description of the room in the form:
 *     You are in the kitchen.
 *     Exits: north west
 * @return A long description of this room
 */
string Room::getLongDescription()
{
	cout << endl;
	return "You are in " + description + ".\n" + getExitString();
}

/**
 * Return a string describing the room's exits & items, for example
 * "Exits: north west".
 * @return Details of the room's exits.
 */
string Room::getExitString()
{
	string returnString = "Exits:";

	//Iterator listing exits 
	for (map<string,Room*>::iterator it=exits.begin(); it!=exits.end(); it++)
	{
		returnString+= " " + it->first;
	}
	return returnString;
}

/**
 * Return the room that is reached if we go from this room in direction
 * "direction". If there is no room in that direction, return null.
 * @param direction The exit's direction.
 * @return The room in the given direction.
 */
Room * Room::getExit(string direction)
{
	//Iterator finding values
	for (map<string,Room*>::iterator it=exits.begin(); it!=exits.end(); it++)
	{
		if(direction == it->first)
		{
			return it->second;
		}
	}
	return NULL;
}

//return the item in this room
Item* Room::getItem()
{
	return item;
}
