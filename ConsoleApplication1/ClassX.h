#pragma once

class ������
{
	friend class Class����;
	private:
		������* next = nullptr;
		int value;
	public:
		������(������* next, int value);
		~������();
};

class Class����
{
	private:
		������* head = nullptr;
		int length = 0;
		������* �������(int index);
	public:
		Class����();
		~Class����();
		int* get(int index);
		void add(int value);
		void remove(int index);
		void printAll();
		void printAllGets();
};



