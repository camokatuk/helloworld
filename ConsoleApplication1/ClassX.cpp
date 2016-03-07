#include "ClassX.h"
#include <iostream>

������::������(������* next, int value)
{
	this->next = next;
	this->value = value;
}

������::~������()
{
	delete next;
}

Class����::Class����()
{
}


Class����::~Class����()
{
	delete this->head; //meaningless comment
}

// index is validated!
������* Class����::�������(int index)
{
	������* element = this->head;
	for (int i = 0; i < index; i++)
	{
		element = element->next;
	}
	return element;
}

int* Class����::get(int index)
{
	if (index < 0 || index >= this->length)
	{
		return nullptr;
	}
	������* element = this->�������(index);
	return &(element->value);
}

void Class����::add(int value)
{
	if (length == 0)
	{
		this->head = new ������(nullptr, value);
		this->length++;
		return;
	}

	������* tail = this->�������(this->length - 1);
	tail->next = new ������(nullptr, value);
	this->length++;
}

void Class����::remove(int index)
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

	������* element = this->�������(index - 1);
	������* removeMe = element->next;

	element->next = removeMe->next;
	removeMe->next = nullptr; // detach tail
	delete removeMe;
}

void Class����::printAll()
{
	if (!this->head)
	{
		return;
	}
	for (������* element = this->head; element; element = element->next)
	{
		std::cout << element->value << (element->next ? ", " : "");
	}
	std::cout << std::endl;
}

void Class����::printAllGets()
{
	for (int i = 0; i < this->length; i++)
	{
		std::cout << *this->get(i) << ((i < length - 1) ? ", " : "");
	}
	std::cout << std::endl;
}
