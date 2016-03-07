#include "ClassX.h"
#include <iostream>

Õóÿñèê::Õóÿñèê(Õóÿñèê* next, int value)
{
	this->next = next;
	this->value = value;
}

Õóÿñèê::~Õóÿñèê()
{
	delete next;
}

ClassÕóÿñ::ClassÕóÿñ()
{
}


ClassÕóÿñ::~ClassÕóÿñ()
{
	delete this->head; //meaningless comment
}

// index is validated!
Õóÿñèê* ClassÕóÿñ::óãà÷àêà(int index)
{
	Õóÿñèê* element = this->head;
	for (int i = 0; i < index; i++)
	{
		element = element->next;
	}
	return element;
}

int* ClassÕóÿñ::get(int index)
{
	if (index < 0 || index >= this->length)
	{
		return nullptr;
	}
	Õóÿñèê* element = this->óãà÷àêà(index);
	return &(element->value);
}

void ClassÕóÿñ::add(int value)
{
	if (length == 0)
	{
		this->head = new Õóÿñèê(nullptr, value);
		this->length++;
		return;
	}

	Õóÿñèê* tail = this->óãà÷àêà(this->length - 1);
	tail->next = new Õóÿñèê(nullptr, value);
	this->length++;
}

void ClassÕóÿñ::remove(int index)
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

	Õóÿñèê* element = this->óãà÷àêà(index - 1);
	Õóÿñèê* removeMe = element->next;

	element->next = removeMe->next;
	removeMe->next = nullptr; // detach tail
	delete removeMe;
}

void ClassÕóÿñ::printAll()
{
	if (!this->head)
	{
		return;
	}
	for (Õóÿñèê* element = this->head; element; element = element->next)
	{
		std::cout << element->value << (element->next ? ", " : "");
	}
	std::cout << std::endl;
}

void ClassÕóÿñ::printAllGets()
{
	for (int i = 0; i < this->length; i++)
	{
		std::cout << *this->get(i) << ((i < length - 1) ? ", " : "");
	}
	std::cout << std::endl;
}
