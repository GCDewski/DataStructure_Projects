README

----------------------
Command Line Arguments
----------------------

Example:  ./getURL www.xavier.edu

------------------
Design Decisions
------------------

D-Level.
  

The Simplecurl files, created by someone else, needed to be modifed for the 
ultimate goal of Jesus golf. getRetrivedDocument gets the entire document,
but the methods findURLs, url_beg, and url_end were added to find the URLs
within the document. Those methods were basically copy and pasted straight 
from an older textbook example.

C-Level.


The URLGraph files were created to hold the neighbors of a single URL in a map,
and then utilizing that map, create a queue from previous LinkedList files.
The original source vertex and neighbors are assigned to maps of:

Color- Keeps track of if searched
Distance- Keeps track of how far down the node is from original source
Parent- Keeps track of the parent URL

During the queue loop, the above maps were used to keep track of if the URL had
already been serached and to change the level count. The neighbors of the URL
being serached it printed. 

B-Level.


The URLGraphs were modifed to take a target word. The methods toLowerCase and
findWord were added to SimpleCurl. toLowerCase obviously lowercases the input
word and the document so that the target isn't missed because of capatlization.
findWord takes the target the the document and checks by word using spaces and 
returns a boolean if the word is found. The BSF method was modifed to check if
the word was found. If found, the queue loop breaks because we don't need to 
search anymore.

A-Level.


An attempt to get the links that don't use http:// from a page and include
them in the output of neighbors. The url_beg method was modified to:

-find the <a href=“ (instead of ://
-skip ahead from the location it found that by 9 characters 
	(which gets you past that <a href=“ part of it)
-find the closing “ that ends the url by doing a find on \” from the
	 location where your url now starts (9 past the original location)
-Use substring to pull URL out. 

This code wasn't done correctly. See bugs for details...

-----------------------
Jesus Golf Process
-----------------------

These were the steps to the process:
    1 ) Uses SimpleCurl to grab an inputted URL from the command line and test if
	not broken.
    2 ) Gets the whole document from URL.
    3 ) Pulls out the URLs within the source URL and stores in vector.
    4 ) Sets target string
    5 ) Sets level cap
    6 ) Initiates a URLGraph
    7 ) Runs BSF search 

-----------------------
Bugs & Other Sad Things
-----------------------

1 ) Depending on the type of computer (Mac/Windows), users need to make sure they
    uncomment the correct line in the makefile.
2 ) Windows users must download cURL libraries and put them in the correct folder
    path.

3 ) The level for the first 2 or 3 URLs after the main source URL will have an 
    incorrect output. 

3 ) Using this project will throw an std::out_of_range error. This can be fixed by
    running the commit that has the message: "Added the curl setopts. Error for wikipedia still
    happens." This error doesn't happen if cURL libraries are right. A-Level won't
    happen, but all the other magic does :)


The End.
Gracie Carver-Dews on 11/6/15
