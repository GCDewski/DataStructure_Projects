#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

//Created by: Gracie Carver-Dews (11/17/15)
//C-Level of Project 4
//Creates nodes and their children and assings them values and weights.

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class HuffmanNode
{
	private:
		int weight;
		int value; //reps the character held in node
		HuffmanNode *leftChild;
		HuffmanNode *rightChild;

	public:
		HuffmanNode(int w, int v); //Const: Creates node to have given value/weight & init left/right children as NULL (AKA LEAF)
		HuffmanNode(HuffmanNode *l, HuffmanNode *r); //Const: Sets values of children nodes and sets weight to be sum of weights from left and right children
		void travelTree(HuffmanNode *node, string path, vector<string> &code); //travel the tree and output leaf values (huff)
		int getValue(); //return value of node
		int getWeight(); //TEST
		HuffmanNode* getLeft(); //return left child
		HuffmanNode* getRight(); //return right child
};

#endif