//Created by: Gracie Carver-Dews (11/13/15)
//D-Level of Project 4
//Reads the text file given and counts the frequency of the characters.

#include <fstream>
#include "ReadFile.h"

vector<int> ReadFile::charFreq(string file)
{
	freqArray.resize(257);
	freqArray[PSEUDOEOF] = 1; 
	fill(freqArray.begin(), freqArray.end()-1, 0); //fill this vector with 0's
	//cout << freqArray['A'] << endl; TEST: should be 0

	//Gets chars from file
	ifstream infile;
	infile.open(file.c_str()); // waaah
	/** while peeking ahead does not reveal end of file **/
	while(infile.peek() && !infile.eof())
	{
   		char ch = infile.get();

   		//cout << ch << endl; //TEST should be 'd' or ascii value of it
   		//cout << freqArray[ch] << endl; //TEST: should be 0

   		freqArray[ch]++;
   		//cout << freqArray[ch] << endl; //TEST: should be 1

   		//cout << ch << " count: " << freqArray[ch] << endl; //TEST: should show count by char in file
	}

	return freqArray;
}

void ReadFile::encode(string file, vector<string> code, string freq, int nonZero)
{
	//Gets chars from file & write to new one

	ofstream newFile;
	newFile.open("prog4.txt");
	newFile << nonZero << "\n";

	ifstream infile;
	infile.open(file.c_str()); // waaah

	newFile << freq;
	/** while peeking ahead does not reveal end of file **/
	while(infile.peek() && !infile.eof())
	{
   		char ch = infile.get();
   		//cout << code[ch] << endl; 
   		newFile << code[ch];
	}

	newFile << code[PSEUDOEOF];

	newFile.close();
	cout << "Written to prog4.txt!" << endl;
}

