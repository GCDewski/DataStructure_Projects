/**
Modified by Gracie Carver-Dews, 10/27/2015

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

#include <vector>
#include <cctype>
#include <algorithm> 
#include <string>
#include <iostream>
#include <curl/curl.h>
#include "SimpleCurl.h"

using namespace std;

   int SimpleCurl::writer(char *data, size_t size, size_t nmemb,
                  std::string *buffer)
   {
  // What we will return
     int result = 0;

  // Is there anything in the buffer?
     if (buffer != NULL)
     {
        // Append the data to the buffer
       buffer->append(data, size * nmemb);

        // How much did we write?
       result = size * nmemb;
     }

     return result;
   }

   SimpleCurl::SimpleCurl(string url)
   {
	   if (getURL(url) == -1) exit(-1);
   }

   int SimpleCurl::getURL(string url)
    {
	     buffer = "";
       // Create our curl handle
       curl = curl_easy_init();

       if (curl)
       {
         // Now set up all of the curl options
         curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
         curl_easy_setopt(curl, CURLOPT_HEADER, 0);
         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER,1);
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST,2); 
         curl_easy_setopt(curl,CURLOPT_CAINFO,"/MinGW/MSYS/1.0/local/bin/curl-ca-bundle.crt"); 

         // Attempt to retrieve the remote page
         result = curl_easy_perform(curl);

         // Always cleanup
         curl_easy_cleanup(curl);

         // Did we succeed?
         if (result != CURLE_OK)
         {
                cout << "Error: [" << result << "] - " << errorBuffer;
		return -1;
         }
         return buffer.length();
       }
       return 0;
     }

  string SimpleCurl::getRetrievedDocument()
  { 
	return buffer;
  }

  typedef string::const_iterator iter;

  //return true when character passed can't be URL
  bool not_url_char(char c)
  {
    //symbols other than alphabet that are legal
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    //see whether c can return in URL & return negative
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) !=url_ch.end());

  }

  //look for letters followed by ://
  string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
  {
    //static const string sep = "://"; 
    string sep = "<a href=/ </a>";
    sep = sep.substr(0,9); //where the / is found plus 9 to get hyperlink
    int location = sep.find_first_of("/");

    while (location != string::npos) 
    {
      string word = sep.substr(0,location);

      sep = sep.substr(location+1);
    } 

    //url_ beg code that was needed for B-level, but shouldn't be needed for A-Level

    //i marks where seperater is found
    //iter i = b;

    // while((i = search(i, e, sep.begin(), sep.end())) != e)
    // {
    //   //make sure sep isnt at beginning or end of line
    //   if(i != b && i + sep.size() != e)
    //   {
    //     //beg marks beginning of protocal name (ie before sepeartor)
    //     iter beg = i;
    //     while(beg !=b && isalpha(beg[-1]))
    //     {
    //       beg--;
    //     }
        
    //     //is there a char before and after the seperator
    //     if(beg != i && !not_url_char(i[sep.size()]))
    //     {
    //       return beg;
    //     }

    //   }

    //   //seperator wasnt apart of URL so move on
    //   i += sep.size();

    // }
      return e;
    }

   //get URL after ://
  string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
  {
    return find_if(b, e, not_url_char); 
  }

  //finds URLs on the page and returns a vector of them.
  vector<string> findURLs(const string& s)
  {
    
    vector<string> ret; //vector to store URLs. Each element is new URL
    iter b = s.begin(), e = s.end();

    //look through all input
    while(b != e)
    {

      b = url_beg(b, e); //change what url_beg fine

      //if we found it
      if(b !=e)
      {
        iter after = url_end(b, e);

        //remember URL
        ret.push_back(string(b, after));

        //advance b and check for more URLs
        b = after;
      }
    }
    return ret;
  } 

  //lower case everything in input
string SimpleCurl::toLowerCase(string data)
{
    tolower('A');
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data;
}

//search data for target word and return true if target found
bool SimpleCurl::findWord(string data, string target)
{
  bool found = false;
  string word1 = "";
  data = toLowerCase(data);
  target = toLowerCase(target);
  int location = data.find_first_of(" ");

  while (location != string::npos) 
  {
    string word = data.substr(0,location);
    if (word != "") 
    {
      word1 = word; //word 1 is the word between spaces

      if(word1 == target) //check if matches target
      {
        found = true;
      }
    }

    data = data.substr(location+1);
    location = data.find_first_of(" "); 
  } 

  return found;
}




