/**
Modified by Gracie Carver-Dews 10/27/15

All code here adapted (modified as little as possible) from 
www.luckyspin.org
Adaptation by Gary Lewandowski, 14 October 2007.

Original header comments follow.
**/

/*
 * This is a very simple example of how to use libcurl from within 
 * a C++  program. The basic idea is that you want to retrieve the 
 * contents of a web page as a string. Obviously, you can replace 
 * the buffer object with anything you want and adjust elsewhere 
 * accordingly.
 * 
 * Hope you find it useful..
 * 
 * Todd Papaioannou 
 */

#include <string>
#include <iostream>
#include <vector>
#include "SimpleCurl.h"
#include "URLGraph.h"

using namespace std;

int main(int argc, char *argv[])
{
	/** one way to use SimpleCurl: via a constuctor. Give a string and it
	  tries to retrieve the document.
	  **/
	//SimpleCurl httpGrabber(argv[1]);
	SimpleCurl httpGrabber;
	//string doc = httpGrabber.getRetrievedDocument();
	//cout << doc << endl;

    /** Here is a second way -- the more likely way you'll use it.
        After creating an httpGrabber, invoke the getURL method.
        It returns -1 on failure.
        **/

     //TEST getRetrievedDoc

	// if (httpGrabber.getURL("http://www.cs.xu.edu/~lewandow") !=-1)
 	//  cout << httpGrabber.getRetrievedDocument() << endl;
	// else
	// 	cout << "Could not retrieve document" << endl;


    //TEST Vector URLS
    // if(httpGrabber.getURL(argv[1]) != -1) //add argv because needs string & checks if bad URL    
    // {
    // 	string doc = httpGrabber.getRetrievedDocument();
    // 	vector<string> urls = findURLs(doc);
    // 	for(int i = 0; i<urls.size(); i++)
    // 	{
    // 		cout << urls.at(i) << endl;
    // 	}
		
    // }


 //    //TEST Graph Map Fill
     
 //    //fill map if URL is valid
	// if(httpGrabber.getURL(argv[1]) != -1)
 //    {
 //    	string doc = httpGrabber.getRetrievedDocument();
 //    	vector<string> neighbors = findURLs(doc); //neighbors
 //    	string vertex = argv[1]; //main URL

 //    	URLGraph graph(vertex, neighbors);

 //    	cout << "Key URL: " << vertex << endl;
 //    	cout << endl;
 //    	cout << "Values:" << endl;
 //    	cout << endl;
 //    	for(int i = 0; i<neighbors.size(); i++)
 //    	{
 //    		cout << neighbors.at(i) << endl;
 //    	}
 //    }

    //TEST Breadth Search

    
    if(httpGrabber.getURL(argv[1]) != -1)
    {
    	string doc = httpGrabber.getRetrievedDocument();
    	vector<string> neighbors = findURLs(doc); //neighbors
    	string vertex = argv[1]; //main URL
        //string target = "student"; //TEST: should be found first lvl thru www.xavier.edu
        string target = "Gracie"; //TEST: shound't be found in 3 lvls thru www.xavier.edu/CS (shorter level list)
        //string target = "Jesus"; //for Wikipedia
        int level = 3; 

    	URLGraph graph(vertex, neighbors);

    	graph.BFS(vertex, level, target);
    }



}
