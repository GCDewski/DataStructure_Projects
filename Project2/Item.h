#include <iostream>
#include <string>
using namespace std;

#ifndef ITEM_H
#define ITEM_H

/**
A dumbed down version of the Item class from CSII Zuul project.
*Handles placing a specific item in the room and allowing the character to take it.
*
*@author Gracie Carver-Dews
*@version 10.03.2015
*/

class Item
{
private:
	string name;
	string description;
	bool taken;

public:
	Item(string itemName, string itemDescr);
	string getName();
	string getDescription();
	bool isItemTaken();
	void takeItem();
};
#endif
