#include "ClassX.h"
#include <iostream>

Node::Node(Node* next, int value)
{
	this->next = next;
	this->value = value;
}

Node::~Node()
{
	delete next;
}

List::List()
{
}


List::~List()
{
	delete this->head; //meaningless comment
}

// index is validated!
Node* List::getNode(int index)
{
	Node* element = this->head;
	for (int i = 0; i < index; i++)
	{
		element = element->next;
	}
	return element;
}

int* List::get(int index)
{
	if (index < 0 || index >= this->length)
	{
		return nullptr;
	}
	Node* element = this->getNode(index);
	return &(element->value);
}

void List::add(int value)
{
	if (length == 0)
	{
		this->head = new Node(nullptr, value);
		this->length++;
		return;
	}

	Node* tail = this->getNode(this->length - 1);
	tail->next = new Node(nullptr, value);
	this->length++;
}

void List::remove(int index)
{
	if (index < 0 || index >= this->length)
	{
		return;
	}

	length--;

	if (length == 0)
	{
		delete this->head;
		return;
	}

	Node* element = this->getNode(index - 1);
	Node* removeMe = element->next;

	element->next = removeMe->next;
	removeMe->next = nullptr; // detach tail
	delete removeMe;
}

void List::printAll()
{
	if (!this->head)
	{
		return;
	}
	for (Node* element = this->head; element; element = element->next)
	{
		std::cout << element->value << (element->next ? ", " : "");
	}
	std::cout << std::endl;
}

void List::printAllGets()
{
	for (int i = 0; i < this->length; i++)
	{
		std::cout << *this->get(i) << ((i < length - 1) ? ", " : "");
	}
	std::cout << std::endl;
}
