/**
Gracie Carver-Dews
10/28/2015

Header File
Hold the information about the graph from a single URL and stores as an adjacenecy list graph. 
Implments a BFS that takes a parameter of the certain amount of levels to search.
Created by Gracie Carver-Dews on 10/28/15.
**/

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class URLGraph
{
private:
	map<string, vector<string> > graph; //key is URL and vector of strings is URL neighbors
	map<string, int> color;
	map<string, string> parent;
	map<string, int> distance; //need this?

public:
	URLGraph(string v, vector<string> n); //v for vertex, n for neighbors
	void BFS(string v, int level, string target);
};

