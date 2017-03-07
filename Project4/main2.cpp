//Created by: Gracie Carver-Dews (12/4/15)
//main class for testing the decompression of the huff

#include "bitops.h"
#include "HeapNode.h"
#include "HuffmanNode.h"
#include "ReadFile.h"
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	vector<int> freqArray(257);
	freqArray[PSEUDOEOF] = 1; 
	fill(freqArray.begin(), freqArray.end()-1, 0); //fill this vector with 0's

	string file = "prog4.txt";
	ifstream infile;
	infile.open(file.c_str()); // waaah

	int n;
	int ch;
	int freq;

	infile >> n;
	cout << n << endl; //TEST: should be 7

	for(int i = 0; i < n; i++) //loop for number of characters
	{
		ch = infile.get(); //get char
		cout << ch << " "; //TEST: Should be 10 (ASCII val of A)

		infile >> freq; //get frequency
		cout << freq << endl; //TEST: Should be 49 (ASCII value of 1)

		infile.get(); //get space

		freqArray[ch] = freq;
	}

	HeapNode h;
	vector <string> chars = h.BuildTree(freqArray);

	priority_queue<HeapNode> theHeap = h.getHeap();
	HuffmanNode *node = theHeap.top().Value();
	HuffmanNode *root = node;

	return 0;// TEST

	for(int i = 0; i < chars.size(); i++)
	{
		ch = infile.get();
		//cout << ch << endl;

		if(node->getLeft() == NULL && node->getRight() == NULL) //check if it's a leaf
		{
			if(node->getValue() == 256) //check if PSUDEOOF
			{
				cout << "end" << endl;
				break;
			}

			cout << "Leaf: " << chars[node->getValue()] << endl; 
			node = root;
		}

		if(ch == '0') //if 0, go left on tree
		{
			node = node->getLeft();

			if(node->getValue() == 256) //check if PSUDEOOF 
			{
				cout << "end" << endl;
				break;
			}
		}
		else //it's a 1 so go right
		{
			node = node->getRight(); //might be node = node->getRight()

			if(node->getValue() == 256) //check if PSUDEOOF & stop if it is
			{
				break;
			}
		}
	}

	infile.close();
}

