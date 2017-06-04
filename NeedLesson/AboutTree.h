#pragma once
class AboutTree
{
	class node {
	public:
		node() { left = NULL; right = NULL; }
		int value;
		node *left=NULL;
		node *right=NULL;
	};

public:	
	node *root = NULL;
	bool insertValue(int value);
	bool recIV(node *NODE, int value);
	bool deleteValue(int value);
	node* findP(node *NODE,node *P,int value);
	node* findCP(node *NODE,node *P,bool flag);
	bool searchValue(int value);
	node* recSV(node *NODE, int value);
	int* inorderTraversal();
	bool recIn(node *NODE);
	int* preorderTraversal();
	bool recPre(node *NODE);
	int* postorderTraversal();
	bool recPost(node *NODE);
};