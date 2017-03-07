#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
/* a node holds some stuff in a linked data structure */
class node {
	private: 
		string data;
		node * next;
	public:
		node(string d="",node *n=NULL):data(d),next(n){}
		string getData() {return data;}
		void setData(string d) {data = d;}
		node * getNext() {return next;}
		void setNext(node *n) {next = n;}
};
#endif
