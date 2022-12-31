#pragma once
template <class T>
class Node
{

public:
	T data;
	Node<T>* next = nullptr;;


	Node(T data) {
		this->data = data;

	}
	Node() {
		this->data = T();
		this->next = nullptr;
	}

	Node(Node* other) {
		this->data = other->data;
		this->next = other->next;

	}
	~Node() {

	}






};