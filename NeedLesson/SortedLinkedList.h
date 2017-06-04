#pragma once
class SortedLinkedList
{	
	class node {
	public:
		node() { next = NULL; }
		int value;
		node *next;
	};

public:
	int size = 0;
	node *head=new node;

	bool addValue(int value);
	bool deleteValue(int value);
	void print();
};