//Created by: Gracie Carver-Dews (11/17/15)
//C-Level of Project 4
//Creates nodes and their children and assings them values and weights.

#include "HuffmanNode.h"
#include <fstream>

//Constuctors:


//Creates node to have given value/weight & init left/right children as NULL (AKA LEAF)
HuffmanNode::HuffmanNode(int v, int w)
{
	weight = w;
	value = v;
	leftChild = NULL;
	rightChild = NULL;
} 

//Sets given values to children nodes and sets weight to be sum of weights from left and right children
HuffmanNode::HuffmanNode(HuffmanNode *l, HuffmanNode *r)
{
	leftChild = l;
	rightChild = r;
	value = -1;
	weight = leftChild->getWeight() + rightChild->getWeight();
}

//travels the tree and returns encoding of the huffmanNode
void HuffmanNode::travelTree(HuffmanNode *node,  string path, vector <string> &code)
{

	//HuffmanNode* left = node->getLeft(); //TESTS
	//HuffmanNode* right = node->getRight();

	if(node->getLeft() == NULL && node->getRight() == NULL)
	{
		//cout << node->value << endl;
		//cout << path << endl;
		code[node->value] = path;
		return;
	}

	if(node->getLeft() !=NULL)
	{
		//cout << node->getWeight() << endl;
		//cout << "Left: " << path + "0" << endl;
		travelTree(node->getLeft(), path + "0", code);

	}

	if(node->getRight() !=NULL)
	{
		//cout << node->getWeight() << endl;
		//cout << "Right: " << path + "1" << endl;
		//code.push_back(path + "1");
		travelTree(node->getRight(), path + "1", code);
	}
}

//Get Methods:


int HuffmanNode::getValue()
{
	return value;
}

int HuffmanNode::getWeight()
{
	return weight;
}

HuffmanNode* HuffmanNode::getLeft()
{
	return leftChild;
}

HuffmanNode* HuffmanNode::getRight()
{
	return rightChild;
}
