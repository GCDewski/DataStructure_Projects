#include "item.h"

/**
A dumbed down version of the Item class from CSII Zuul project.
*Handles placing a specific item in the room and allowing the character to take it.
*
*@author Gracie Carver-Dews
*@version 10.03.2015
*/

Item::Item(string itemName, string itemDescr) //constuctor
{
	name = itemName;
	description = itemDescr;
	bool taken = false;
}

//return name of item
string Item::getName()
{
	return name;
}

//return description of item
string Item::getDescription()
{
	return description;
}

//return true if the item has been taken from room
bool Item::isItemTaken()
{
	return taken;
}

//change the bool value of taken when user takes item
void Item::takeItem()
{
	taken = true;
}
