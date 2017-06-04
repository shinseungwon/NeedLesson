#include "stdafx.h"
#include "iostream"
#include "Queue.h"
using namespace std;
#pragma warning(disable:4996)


bool Queue::push(int value)
{
	node *r = new node;
	r->value = value;
	r->next = NULL;

	if (size == 0) {
		head->next = r;
		cout << "value : " << head->next->value << " inserted.\n";
		size++;
		return true;
	}
	else {
		node *cursor = head;

		while (cursor->next != NULL) {
			cursor = cursor->next;
		}

		cursor->next = r;

		cout << "value : " << r->value << " pushed.\n";
		size++;
		return true;
	}

	return false;
};

int Queue::pop()
{
	node *cursor = head;

	if (size == 0) {
		cout << "No Item\n";
		return false;
	}
	else {
		node *cursor = head;

		cout << cursor->next->value << " popped\n";
		cursor->next = NULL;
		return true;
	}

	return false;
};