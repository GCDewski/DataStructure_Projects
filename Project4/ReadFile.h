#ifndef READFILE_H
#define READFILE_H

//Created by: Gracie Carver-Dews (11/13/15)
//D-Level of Project 4
//Reads the text file given and counts the frequency of the characters.

#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int PSEUDOEOF = 256; //Lets us know we have reached the end of the file

class ReadFile
{
	private:
		vector<int> freqArray;

	public:
		vector<int> charFreq(string f);
		void encode(string g, vector<string> h, string freq, int nonZeroNums);
};

#endif
