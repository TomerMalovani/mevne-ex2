// linked list class declaration with head and tail pointers 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Linkedlist
{
public:
	Linkedlist();
	~Linkedlist();
	void pushToTail(int value);
	void pushToHead(int value);
	void printList();

private:
	struct Node
	{
		int value;
		Node* next;
	};
	Node* head;
	Node* tail;
	int count;
};

#endif
