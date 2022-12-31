#include "Linkedlist.h"
#include <iostream>

using namespace std;

Linkedlist::Linkedlist()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

Linkedlist::~Linkedlist()
{
	Node* temp = head;
	while (temp != NULL)
	{
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}

void Linkedlist::pushToTail(int value)
{
	Node* temp = new Node;
	temp->value = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
	count++;
}

void Linkedlist::pushToHead(int value)
{
	Node* temp = new Node;
	temp->value = value;
	temp->next = head;
	head = temp;
	if (tail == NULL)
	{
		tail = temp;
	}
	count++;
}

void Linkedlist::printList()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}