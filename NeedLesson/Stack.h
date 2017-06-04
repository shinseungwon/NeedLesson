#pragma once
class Stack
{
	class node {
	public:
		node() { next = NULL; }
		int value;
		node *next;
	};

public:
	int size = 0;
	node *head = new node;

	bool push(int value);
	int pop();	
};