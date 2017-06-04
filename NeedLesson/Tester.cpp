#include "stdafx.h"
#include "iostream"
#include "sortedLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "AboutTree.h"
using namespace std;
#pragma warning(disable:4996)
void main()
{
	cout << "Tester ON\n\n";
	/*
	SortedLinkedList L;
	L.addValue(5);
	L.addValue(13);
	L.addValue(6);
	L.addValue(3);
	L.addValue(1);
	L.deleteValue(6);
	L.print();
	*/

	/*
	Stack S;
	S.push(5);
	S.push(12);
	S.pop();
	S.push(16);
	*/

	/*
	Queue Q;
	Q.push(5);
	Q.push(12);
	Q.pop();
	Q.push(16);
	*/

	AboutTree T ;
	/*
	T.insertValue(10);
	T.insertValue(7);
	T.insertValue(14);
	T.insertValue(15);
	T.insertValue(5);
	T.insertValue(9);	
	T.insertValue(12);
	T.insertValue(8);
	T.inorderTraversal();
	T.preorderTraversal();
	T.postorderTraversal();
	T.searchValue(7);
	T.searchValue(16);
	T.deleteValue(10);
	T.deleteValue(7);
	T.deleteValue(18);
	*/
	for (int i = 0; i < 1000; i++)
		T.insertValue(rand());
	
	T.postorderTraversal();

	//for (int i = 0; i < 1000; i++)
		//T.deleteValue(rand());

	T.postorderTraversal();
}