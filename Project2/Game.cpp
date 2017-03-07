#include "Game.h"
#include "CommandWords.h"

/**
 *  This class is the main class of the "World of Zuul" application. 
 *  "World of Zuul" is a very simple, text based adventure game.  Users 
 *  can walk around some scenery. That's all. It should really be extended 
 *  to make it more interesting!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initialises all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 * 
 * @author  Michael Kölling and David J. Barnes
 * @version 2011.08.08
 * @version 2015.10.03 Gracie Carver-Dews
 */


/**
* Create the game and initialise its internal map.
*/
Game::Game()
{
	createRooms();
	Parser parser;
}

/**
* Create all the rooms and link their exits together.
*/
void Game::createRooms()
{
	Room * outside;
	Room * theater;
	Room * pub;
	Room * lab;
	Room * office;

    //create the items
    Item * microphone;
    Item * bottle;
    Item * screwdriver;
    Item * pen;

    microphone = new Item("Microphone", "A wireless mic.");
    bottle = new Item("Bottle", "It's empty, and cracked on the bottom,");
    screwdriver = new Item("Screwdriver", "Is it sonic?");
    pen = new Item("Pen", "Mightier than the sword..");
	
	//create the rooms
	outside = new Room("outside the main entrance of the university", NULL);
    theater = new Room("in a lecture theater", microphone);
    pub = new Room("in the campus pub", bottle);
    lab = new Room("in a computing lab", screwdriver);
    office = new Room("in the computing admin office", pen);
    
    // initialise room exits
    outside->setExit("east", theater);
    outside->setExit("south", lab);
    outside->setExit("west", pub);

    theater->setExit("west", outside);

    pub->setExit("east", outside);

    lab->setExit("north", outside);
    lab->setExit("east", office);

    office->setExit("west", lab);

    currentRoom = outside;  // start game outside
}

/**
 *  Main play routine.  Loops until end of play.
 */
void Game::play()
{
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the game is over.
                
    bool finished = false;
    while (!finished) {
        Command command = parser.getCommand();
        finished = processCommand(command);
    }
    cout << "Thank you for playing.  Good bye." << endl;
}

/**
 * Print out the opening message for the player.
 */
void Game::printWelcome()
{
	cout << endl;
	cout << "Welcome to the World of Zuul!" << endl;
	cout << "World of Zuul is a new, incredibly boring adventure game." << endl;
	cout << "Type 'help' if you need help." << endl;
	cout << endl;
	cout << currentRoom->getLongDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * @param command The command to be processed.
 * @return true If the command ends the game, false otherwise.
 */
bool Game::processCommand(Command command)
{
	bool wantToQuit = false;

    if(command.isUnknown()) 
    {
        cout << "I don't know what you mean..." << endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord == "help") 
    {
        printHelp();
    }
    else if (commandWord == "go") 
    {
        goRoom(command);
    }
    else if (commandWord == "quit") 
    {
        wantToQuit = quit(command);
    }
    else if (commandWord == "take")
    {
        takeItem();
    }
    // else command not recognised.
    return wantToQuit;
}


/**
 * Print out some help information.
 * Here we print some stupid, cryptic message and a list of the 
 * command words.
 */
void Game::printHelp()
{
    cout << endl;
	cout << "You are lost. You are alone. You wander" << endl;
	cout << "around at the university." << endl;
	cout << endl;
	parser.showCommands();
    cout << endl;
}

/** 
 * Try to in to one direction. If there is an exit, enter the new
 * room, otherwise print an error message.
 */
void Game::goRoom(Command command)
{
    Item * currentItem;

    if(!command.hasSecondWord()) 
    {
	    // if there is no second word, we don't know where to go...
	    cout << "Go where?" << endl;
	    return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room * nextRoom = currentRoom->getExit(direction);

    if (nextRoom == NULL) 
    {
        cout << "There is no door!" << endl;
    }
    else 
    {
        currentRoom = nextRoom;
        currentItem = currentRoom->getItem();
        cout << currentRoom->getLongDescription() << endl;
        cout << endl;
        if(currentItem != NULL && currentItem->isItemTaken() == false)
        {          
            cout << "There is a " << currentItem->getName() << " in the room" << endl;
            cout << currentItem->getDescription() << endl;
        }
    }

}

//"Take" was entered. Change the boolean for the item 
//vaiable so it does not appear in the room anymore.
void Game::takeItem()
{  
    Item * currentItem = currentRoom->getItem();

    //if there is an item in the room
    if(currentItem != NULL && currentItem->isItemTaken() == false)
    {          
        currentItem->takeItem();
        cout << "Item taken!" << endl;
    }
    else
    {
        cout << "There is nothing to take!" << endl;
        cout << endl;
    }
    cout << currentRoom->getLongDescription() << endl; //reprint the exits and what room in
}

/** 
 * "Quit" was entered. Check the rest of the command to see
 * whether we really quit the game.
 * @return true, if this command quits the game, false otherwise.
 */
bool Game::quit(Command command)
{
    if(command.hasSecondWord()) 
    {
        cout << "Quit what?" << endl;
        return false;
    }
    else 
    {
        return true;  // signal that we want to quit
    }   
}

