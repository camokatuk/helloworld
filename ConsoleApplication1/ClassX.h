#pragma once

class ’у€сик
{
	friend class Class’у€с;
	private:
		’у€сик* next = nullptr;
		int value;
	public:
		’у€сик(’у€сик* next, int value);
		~’у€сик();
};

class Class’у€с
{
	private:
		’у€сик* head = nullptr;
		int length = 0;
		’у€сик* угачака(int index);
	public:
		Class’у€с();
		~Class’у€с();
		int* get(int index);
		void add(int value);
		void remove(int index);
		void printAll();
		void printAllGets();
};



