#pragma once

class Node
{
	friend class List;
	private:
		Node* next = nullptr;
		int value;
	public:
		Node(Node* next, int value);
		~Node();
};

class List
{
	private:
		Node* head = nullptr;
		int length = 0;
		Node* getNode(int index);
	public:
		List();
		~List();
		int* get(int index);
		void add(int value);
		void remove(int index);
		void printAll();
		void printAllGets();
};



