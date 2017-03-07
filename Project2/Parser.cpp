#include "Parser.h"
#include <string>


/**
 * Create a parser to read from the terminal window.
 */
Parser::Parser() 
{
    //nothing to do here..
}

//gets command from input and splits it
Command Parser::getCommand()
{
    string inputLine;
    string word1 = "";
    string word2 = "";

    cout << "Enter Command: "; //print prompt
    getline(cin, inputLine); //takes input
    inputLine = toLowerCase(inputLine);

    //The "location is to find the big space and then jump to word"

    int location = inputLine.find_first_of(" ");
    while (location != string::npos) 
    {
        string word = inputLine.substr(0,location);
        if (word != "") 
        {
            word1 = word;
        }
        inputLine = inputLine.substr(location+1);
        location = inputLine.find_first_of(" ");
    }

    word2 = inputLine; // down to one word

    if(word1 == "") //fixes the error when the parser only finds one word..
    {
        word1 = word2;
        word2 = "";
    }
	
    // Now check whether this word is known. If so, create a command
    // with it. If not, create a "null" command (for unknown command).
    if(commands.isCommand(word1)) 
    {
        return Command(word1, word2);
    }
    else 
    {
        return Command("", word2); 
    }
}

//lower case everything in input
string Parser::toLowerCase(string data)
{
    tolower('A');
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

//shows all valid commands
void Parser::showCommands()
{
	commands.showAll();
}
