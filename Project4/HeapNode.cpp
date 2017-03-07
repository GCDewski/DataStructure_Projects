//Created by Gracie Carver-Dews 11/17/15
//C-Level of project 4
//Creates the heap out of nodes and handles the queue

#include "HeapNode.h"
#include <vector>

//returns the pointer to the Huffman node
HuffmanNode* HeapNode::Value() const
{
	return node;
}  

//creates a huffman node
void HeapNode::BuildLeaf(int value, int weight)
{
	node = new HuffmanNode(value, weight);
}

//Creates a Huffman node pointing to the two values given
void HeapNode::BuildNode(HuffmanNode* l, HuffmanNode* r) 
{
	node = new HuffmanNode(l, r);
}

bool HeapNode::operator<(const HeapNode& h2) const
{
	int temp1 = Value()->getWeight();
	//cout << "Nodes weight: " << temp1 << endl; //test weight is right
	int temp2 = h2.Value()->getWeight();
	//cout << "Nodes weight: " << temp2 << endl;

	if(temp1 < temp2)
	{
		//cout << "Weight is less so it's greater on heap: " << temp1 << endl; //Test 
		return (temp2 < temp1);
	}

	return (temp2 < temp1);
}

vector<string> HeapNode::BuildTree(vector<int> charCount)
{
	for(int i = 0; i < charCount.size(); i++)
	{
		//cout << charCount.at(i) << endl; //TEST
		if(charCount.at(i) != 0)
		{
			HeapNode temp;
			temp.BuildLeaf(i, charCount[i]);
			theHeap.push(temp);
			//cout << "Heap Size: " << theHeap.size() << endl; //TEST: Check that the heap grows
		}	
	}

	//cout << "Heap Size: " << theHeap.size() << endl; //TEST: Should be 7

	while(theHeap.size() != 1) //prevents the function from stopping prematurely 
	{
		HeapNode temp1 = theHeap.top();

		//cout << endl;
		//cout << "first node val: " << (temp1.Value())->getValue() << endl; //TEST
		//cout << "first node weight: " << (temp1.Value())->getWeight() << endl; //TEST
		theHeap.pop();

		HeapNode temp2 = theHeap.top();
				
		//cout << "second node val: " << (temp2.Value())->getValue() << endl; //TEST
		//cout << "second node weight: " << (temp2.Value())->getWeight() << endl; //TEST

		theHeap.pop();
			
		HeapNode newNode;
		newNode.BuildNode(temp1.Value(), temp2.Value());
		//cout << "New Weight: " << newNode->Value()->getWeight() << endl;
		theHeap.push(newNode);
	}

	HuffmanNode * tree = theHeap.top().Value();

	vector <string> encode(257);
	tree->travelTree(tree, "", encode);
	return encode;
}

//for testing
priority_queue<HeapNode> HeapNode::getHeap()
{
	return theHeap;
}
  