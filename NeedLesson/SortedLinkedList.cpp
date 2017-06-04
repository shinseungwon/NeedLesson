#include "stdafx.h"
#include "iostream"
#include "SortedLinkedList.h"
using namespace std;
#pragma warning(disable:4996)


bool SortedLinkedList::addValue(int value) 
{	
	node *r=new node;
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
		
		while (cursor->next != NULL && cursor->next->value <= value) {			
			cursor = cursor->next;
		}
		
		if (cursor->next != NULL) {			
			r->next = cursor->next;
			cursor->next = r;
		}
		else {
			cursor->next = r;
		}

		cout << "value : " << r->value<< " inserted.\n";
		size++;
		return true;
	}
	
	return false;
};

bool SortedLinkedList::deleteValue(int value)
{
	node *cursor = head;

	if (size == 0) {
		cout << "No Item\n";
		return false;
	}
	else {
		node *cursor = head;

		while (cursor->next != NULL && cursor->next->value != value) {
			cursor = cursor->next;
		}

		if (cursor->next->value == value) {
			cursor->next = cursor->next->next;
			size--;
			cout << "value : " << value << " deleted.\n";
		}
		else {
			cout << "Item Not Found\n";
			return false;
		}
			
		return true;
	}
	
	return false;
};

void SortedLinkedList::print()
{
	cout << "size is : " << size << "\n";
		
	node *cursor=head;
	if (size == 0) {
		cout << "No Item\n";
		return;
	}
	
	do {
		cursor = cursor->next;
		cout << cursor->value<<" ";
	} while (cursor->next != NULL);


};