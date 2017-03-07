//Created by: Gracie Carver-Dews (11/13/15)
//main class for testing building the Huff

#include "HeapNode.h"
#include "HuffmanNode.h"
#include "ReadFile.h"
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	// //D-LEVEL test:
	ReadFile a;
	vector<int> chars = a.charFreq("test.txt"); 

	// //C-LEVEL test:

	// //Huffmannode testing
	int val = 4;
	int wei = 6;
	// HuffmanNode b(val, wei); //parent
	// HuffmanNode* c = new HuffmanNode(val+1, wei+1); //left child
	// HuffmanNode* d = new HuffmanNode(val+2, wei+2); //right child

	// int value = b.getValue();
	// cout << "Parent value: " << val << endl; //should be 4
	// int weight = b.getWeight();
	// cout << "Parent weight: " << weight << endl; //should be 6
	// cout << endl;

	// HuffmanNode *empty = b.getLeft();
	// if(empty == NULL)
	// {
	// 	cout << "Left: NUll" << endl; 
	// }
	// else
	// {
	// 	cout << "This is not right! Should print NULL" << endl;
	// }

	// cout << endl;
	// HuffmanNode tree(c, d);

	// HuffmanNode *left = tree.getLeft(); 
	// HuffmanNode *right = tree.getRight();
	// if(right == NULL || left == NULL)
	// {
	// 	cout << "This is not right! Should print value" << endl;
	// }
	// else
	// {
	// 	cout << "Left child value: " << left->getValue() << endl; //should be 5
	// 	cout << "Left child weight: " << left->getWeight() << endl; //should be 7
	// 	cout << "Right child value: " << right->getValue() << endl; //should be 6
	// 	cout << "Right child weight: " << right->getWeight() << endl; //should be 8
	// 	cout << "Both value: " << tree.getValue() << endl; //should be -1
	// 	cout << "Both weight: " << tree.getWeight() << endl; //should be 15
	// }

	// //HeapNode testing

	// cout << endl;
	// HuffmanNode* g = new HuffmanNode(val+3, wei+3);
	// HeapNode e;
	// HeapNode f;
	// e.BuildNode(c,d);
	// f.BuildNode(d,g);
	
	// if (e.operator<(f))
	// {
	// 	cout <<  "E is greater" << endl; //should be this
	// }
	// else
	// {
	// 	cout <<  "F is greater" << endl; 
	// }

	//Building Heap testing
	// cout << endl;
	 // HeapNode h; 
	 // HeapNode i; 
	 // HeapNode j; 
	 // HeapNode k;

	 // h.BuildLeaf(val+1, wei+2);
	 // i.BuildLeaf(val+2, wei+3);
	 // j.BuildLeaf(val+2, wei+1);
	 // k.BuildNode(h.Value(),j.Value());

	 // priority_queue<HeapNode> theHeap = k.getHeap();

	 // theHeap.push(h);
	 // theHeap.push(i);
	 // theHeap.push(j);
	 // theHeap.push(k);

	// cout << theHeap.size() << endl; //should be 4 HeapNodes
	// theHeap.pop();
	// cout << theHeap.size() << endl; //should be 3 HeapNodes


	// for(int index = 0; index < theHeap.size(); index++)
	// {
	// 	HuffmanNode L = theHeap.pop().Value();
	// 	cout << L.getValue() << endl; //should print 5,6,6
	// }

	// theHeap.pop();

	// for(int index = 0; index < theHeap.size(); i++)
	// {
	// 	cout << theHeap(index).Value().getValue() << endl; //should print 5,6,6
	// }

	//Build Huffman Tree testing
	cout << endl;
	HeapNode L;
	vector<string> chart = L.BuildTree(chars);

	//cout << "Read File size: " << chars.size() << endl; //should be 257
	//cout << "Chart output: " << chart[256] << endl; //should be 000


	//Encode testing

	string final = "";
	string toString = "";

	for(int index = 0; index < chars.size()-1; index++) //-1 because we don't need PSUEDOEOF output since always 1
	{
		if(chars[index] != 0)
		{
			int num = chars[index];
			ostringstream convert; //new stream every loop or it will stack.
			convert << num;
			toString = convert.str();

			final = final + (char) index + toString + " "; 
		}
	}

	int nonZero = 0;

	for(int i = 0; i < chars.size(); i++)
	{
		if (chars[i] != 0)
		{
			nonZero++;
		}
	}

	//cout << nonZero << endl; //should be 7
	//cout << "Final Path: " << final << " ";
	a.encode("test.txt", chart, final, nonZero); //encode and write to a new file
}
