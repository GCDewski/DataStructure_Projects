#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include "node.h"
using namespace std;

class LinkedList
{
	private: 
		node * head;
		node *findTail()
		{
			if (empty()) return NULL;
			node *tailCandidate = head;
			while (tailCandidate->getNext() != NULL)
			{
				tailCandidate = tailCandidate->getNext();
			}
			return tailCandidate;
		}

	node *deepCopy() const
	{
		node *oldList = head;
		node *newListHead = NULL;
		node *newListTail = NULL;
		while (oldList != NULL) {
			node * temp = new node(oldList->getData());
			if (newListTail == NULL) {
				newListTail= temp;
				newListHead = temp;
			}
			else {
				newListTail->setNext(temp);
				newListTail = temp;
			}
			oldList = oldList->getNext();
		}
		return newListHead;
	}
	
	public:
		LinkedList() : head(NULL)
		{}
		LinkedList(const LinkedList &copyMe) 
		{
			head = copyMe.deepCopy();
		}
		LinkedList & operator=(const LinkedList &copyMe)
		{
			head = copyMe.deepCopy();
			return *this;
		}
		~LinkedList() {
			while (!empty())
				pop();
		}
		bool empty() {return head==NULL;}
		void push_front(string item)
		{
			node *newThing = new node(item,head);
			head = newThing;
		}
		/*
		* remove front item from list
		**/
		string pop()
		{
			string result("");
			if (!empty()) 
			{
				result = head->getData();
				node * temp = head;
				head = head->getNext();
				temp->setNext(NULL);
				delete temp; /* in C++, explicit deallocation*/
			}
			return result;
		}

		/*
		* insert new item at end (tail) of list
		*/
		void push_back(string item)
		{
			if (empty()) 
			{
				push_front(item);
			}
			else 
			{
				node *tail = findTail();
				node * newThing = new node(item,NULL);
				tail->setNext(newThing);
				//tail = newThing;
				//findTail()->setNext(new node(item,NULL));
			}
			/* fill in details */
		}
		bool contains(string item)
		{
			node *current = head; 
			while (current != NULL)
			{
				if (current->getData() == item) return true;
				else current = current->getNext();
			}
			return false;
		}
};
#endif

