/**
CPP File
Hold the information about the graph from a single URL and stores as an adjacenecy list graph. 
Implments a BFS that takes a parameter of the certain amount of levels to search.
Created by Gracie Carver-Dews on 10/28/15.
**/

#include "SimpleCurl.h"
#include "LinkedList.h"
#include "URLGraph.h"
#include <iostream>

URLGraph::URLGraph(string v, vector<string> n)
{
	graph.insert(pair<string, vector<string> > (v, n));
}

//Breadth-first search as far down as given parameter
void URLGraph::BFS(string vertexSource, int level, string target)
{
	//init Queue and starting values

	int j =0; //for level cap
	int p =0; //page count
	bool targetFound = false; //See if found target word
	string targetURL = ""; //where target word at

	//give the key of the source vertex and get the vector of all the neighbors back
	for(int i = 0; i < graph.size(); i++)
	{
		vector<string> neighbors = graph[vertexSource]; 
		string n = neighbors[i];

		color.insert(pair<string, int>(n, 0)); //set all neighbors as white
		parent.insert(pair<string, string>(n, "")); //set all parents to null 
		distance.insert(pair<string, int>(n, 0)); //infinite?? && do I need this?
	}

	LinkedList Q; //Queue
	Q.push_back(vertexSource); //put source URL to front of Queue and go from there

	//cout << vertexSource <<endl; //TEST for the first URL

	//init The beginning URL 
	distance.insert(pair<string, int>(vertexSource, 0));
	color.insert(pair<string, int>(vertexSource, 0));
	parent.insert(pair<string, string>(vertexSource, ""));//no parent



	//until we run out of URLs in the Queue or the search cap is hit by the search then keep going
	while(!Q.empty() && j <= level && !targetFound)
	{
		string k = Q.pop();

		if((graph.find(k) == graph.end()))
		{
			continue;
		}
			
		vector<string> neighbors = graph.at(k);
		SimpleCurl httpGrabber;

		cout << "Key URL: " << k << endl; //TEST for the source vertex
		cout << endl;

		//for all neightbors in k (vertex) search for target word and change color accordingly
		for(int i = 0; i < neighbors.size(); i++)
		{
			string u = neighbors[i]; 
			cout << u << endl; //TEST for neighbor

			 //change color while searching
			if(color[u] == 0 || color.find(u) == color.end())
			{
				color[u] = 1; //change to gray
				parent[u] = k; //get the key 
				distance[u] = distance[k]+1;
				j = distance[u];

				//search page for word
				if(httpGrabber.getURL(u) != -1)
				{
					string doc = httpGrabber.getRetrievedDocument(); //get doc
	    			vector<string> n = findURLs(doc); //neighbors
	    			graph.insert(pair<string, vector<string> > (u, n)); //add to graph
	    			targetFound = httpGrabber.findWord(doc, target); //search document for target word
	    			Q.push_back(u);
    			}

    			//stop loop or keep searching next page
    			if(targetFound)
	    		{
	    			//cout << endl;
	    			//cout << "FOUND WORD" << endl; //TEST
	    			targetURL = u;
	    			break;
	    		}
			}
			color[u] = -1;
			p++;	
		}

		cout << endl;
		cout << "Level: " << j << endl;	
		cout << endl;
	}

	//summary output
	cout << "Summary: " << endl;
	cout << endl;

	cout << "Page Count: " << p << endl;
	cout << "Level: " << j << endl;	

	//output depends on if the target word was found
	if(targetURL == "")
	{
		cout << "Target word not found 0_0" << endl;
	}
	else
	{
		cout << "Target Word On: " << targetURL << endl;
		cout << "Path way from target page to original source:" << endl;
		cout << "     " << targetURL << endl;
		//output the pathway to target word.
		while(parent[targetURL] != "")
		{
			targetURL = parent[targetURL];
			cout << "     "  << targetURL << endl;
		}
	}
}
