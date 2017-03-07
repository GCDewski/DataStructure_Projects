#include "Command.h"
#include "CommandWords.h"
#include "Room.h"
#include "Parser.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
//Testing for Command class

	// cout << "Test 1" << endl;
	// Command test("Hulk", "Smash"); 
	// cout << "First command: " << test.getCommandWord() << endl; //HULK
	// cout << "Second command: " << test.getSecondWord() << endl; //SMASH
	// cout << "First word is empty: " << test.isUnknown() << endl; //0
	// cout << "Has second word: " << test.hasSecondWord() << endl; //1

	// cout << endl;
	// cout << "Test 2" << endl;
	// Command test2("", "go");
	// cout << "First command: " << test2.getCommandWord() << endl; //""
	// cout << "Second command: " << test2.getSecondWord() << endl; //go
	// cout << "First word is empty: " << test2.isUnknown() << endl; //1
	// cout << "Has second word: " << test2.hasSecondWord() << endl; //1

	// cout << endl;
	// cout << "Test 3" << endl;
	// Command test3("help","");
	// cout << "First command: " << test3.getCommandWord() << endl; //"help"
	// cout << "Second command: " << test3.getSecondWord() << endl; //""
 	// cout << "first word is empty: " << test3.isUnknown() << endl; //1
	// cout << "Has second word: " << test3.hasSecondWord() << endl; //0

//Testing for CommandWords

	// cout << endl;
	// cout << "Test 4" << endl;

	// CommandWords test4;

	// cout << "Is 'SMASH' a command?" << " " << test4.isCommand("SMASH") << endl; //0
	// cout << "Is 'go' a command?" << " " << test4.isCommand("go") << endl; //1
	// test4.showAll(); //show commands

	// cout << endl;

//Testing for Parser

	// cout << "Test 5" << endl;

	// Parser test5;
	// test5.getCommand();

//Testing for Room

 //    cout << "Test 6" << endl;
	// Room * test6;
	// Room * exitRoom1;
	// Room * exitRoom2;
	// Room * exitRoom3;
	// test6 = new Room("The Red Room", NULL);
	// exitRoom1 = new Room("Russia", NULL);
	// exitRoom2 = new Room("America", NULL);
	// exitRoom3 = new Room("Canada", NULL);

	// string d = test6->getShortDescription();
	// cout << "Short Descr: " << d << endl;
	// test6->setExit("north", exitRoom1);
	// test6->setExit("south", exitRoom2);
	// test6->setExit("west", exitRoom3);
	// cout << "Long Descr: " << test6->getLongDescription() << endl;

	// Room *testRoom = test6->getExit("north");
	// string d2 = testRoom->getShortDescription();
	// cout << "North Room: " << d2 << endl; //Russia

//Testing for Game
	Game gameTest;
	gameTest.play();
}
