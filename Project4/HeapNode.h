#ifndef HEAPNODE_H
#define HEAPNODE_H

//Created by Gracie Carver-Dews 11/17/15
//C-Level of project 4
//Creates the heap out of nodes and handles the queue

#include "HuffmanNode.h"
#include <queue>
#include <iostream>
using namespace std;

class HeapNode
{
	private:
		HuffmanNode* node;
		priority_queue<HeapNode> theHeap;


	public:
		HuffmanNode* Value() const; //returns the pointer to the Huffman node 
		bool operator<(const HeapNode& h2) const; //A HeapNode order will be determined by weight (greater weight = lower)
		void BuildLeaf(int value, int weight); //creates a huffman node
		void BuildNode(HuffmanNode* l, HuffmanNode* r); //Creates a Huffman node pointing to the two values given
		vector<string> BuildTree(vector<int> a); 
		priority_queue<HeapNode> getHeap(); //For testing in main

};

#endif
