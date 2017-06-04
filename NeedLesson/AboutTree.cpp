#include "stdafx.h"
#include "iostream"
#include "AboutTree.h"
using namespace std;
#pragma warning(disable:4996)


bool AboutTree::insertValue(int value)
{
	if (root == NULL) {
		root = new node;
		root->value = value;
		cout << "Value " << value << " inserted\n";
		return true;
	}
	else{
		if(root->value != value)
			recIV(root, value);	
		else {
			cout << "Duplicated Value!\n";
			return false;
		}
	}	
}
bool AboutTree::recIV(node *NODE, int value) 
{
	if (NODE->value < value) {
		if(NODE->right != NULL)
			recIV(NODE->right, value);
		else {
			NODE->right = new node;
			NODE->right->value = value;
			cout << "Value " << value << " inserted in " << NODE->value << "'s right\n";
			return true;
		}
	}
	else if (NODE->value > value) {
		if (NODE->left != NULL)
			recIV(NODE->left, value);
		else {
			NODE->left = new node;
			NODE->left->value = value;
			cout << "Value " << value << " inserted in "<<NODE->value<<"'s left\n";
			return true;
		}
	}
	else {
		cout << "Duplicated Value!\n";
		return false;
	}
}
bool AboutTree::deleteValue(int value)
{	//삭제연산 다시설계

	if (root->value == value) {//root를 삭제
		if (root->left == NULL && root->right == NULL) {
			root = NULL;
			return true;
		}
		else if (root->left == NULL) {
			root = root->right;			
		}
		else if (root->right == NULL) {
			root = root->left;
		}
		else {

			node *candidatep = findCP(root, NULL, false);
			node *candidate = NULL;
			bool onleft = NULL;
			if (candidatep == root) {				
				candidate = root->left;
				onleft = true;
			}
			else {
				candidate = candidatep->right;
				onleft = false;
			}
			
			node* RL = root->left;
			node* RR = root->right;
			node* CL = candidate->left;
			
			node *temp = NULL;
			temp = root;

			root = candidate;
			root->left = RL;
			root->right = RR;
			
			
			if (onleft)
				candidatep->left = temp;
			else
				candidatep->right = temp;

			candidate = temp;
			candidate->left = CL;
			candidate->right = NULL;

			if (onleft) {
				if (candidate->left == NULL)
					candidatep->left = NULL;
				else 
					candidatep->left = candidate->left;
			}
			else {
				if (candidate->left == NULL)
					candidatep->right = NULL;
				else
					candidatep->right = candidate->left;
			}
			cout << "Value " << value << " successfully deleted!\n";
			postorderTraversal();
		}
	}
	else {//root가 아닌걸 삭제
		node* flag = NULL;
		flag = findP(root, NULL, value);
		if (flag == NULL) {
			cout << value << " Node Not Found, Can't Delete!\n";
			return false;
		}
		else {
			node* target = NULL;
			int dir = 0;
			if (flag->left != NULL) {
				if (flag->left->value == value) {
					target = flag->left;
					dir = -1;
				}
			}
			if (flag->right != NULL) {
				if (flag->right->value == value) {
					target = flag->right;
					dir = 1;
				}
			}

			if (target->left == NULL && target->right == NULL) {
				if (dir == -1)
					flag->left = NULL;
				else if (dir == 1)
					flag->right = NULL;
				else
					cout << "Error!\n";
			}
			else if (target->left == NULL) {
				if (dir == -1)
					flag->left = target->right;
				else if (dir == 1)
					flag->right = target->right;
				else
					cout << "Error!\n";
			}
			else if (target->right == NULL) {
				if (dir == -1)
					flag->left = target->left;
				else if (dir == 1)
					flag->right = target->left;
				else
					cout << "Error!\n";
			}
			else {
				//여기 양쪽노드 모두 살아있을 때 삭제연산 하기

				node *candidatep = findCP(target, NULL, false);
				node *candidate = NULL;
				bool onleft = NULL;
				if (candidatep == target) {
					candidate = target->left;
					onleft = true;
				}
				else {
					candidate = candidatep->right;
					onleft = false;
				}

				node* TL = target->left;
				node* TR = target->right;
				node* CL = candidate->left;

				node *temp = NULL;
				temp = target;
				
				if (dir == -1) {
					flag->left = candidate;
				}
				else if (dir == 1) {
					flag->right = candidate;
				}
				else {
					cout << "error!\n";
				}

				if (candidate != target->left)
					candidate->left = TL;
				else
					candidate->left = NULL;

				candidate->right = TR;
				
				if (onleft)
					candidatep->left = temp;
				else
					candidatep->right = temp;

				candidate = temp;
				candidate->left = CL;
				candidate->right = NULL;

				if (onleft) {
					if (candidate->left == NULL)
						candidatep->left = NULL;
					else
						candidatep->left = candidate->left;
				}
				else {
					if (candidate->left == NULL)
						candidatep->right = NULL;
					else
						candidatep->right = candidate->left;
				}
			}

			cout << value << " Node Found, Successfully Deleted!\n";
			postorderTraversal();
			return true;
		}
	}	
}
AboutTree::node* AboutTree::findCP(node *NODE,node *P,bool flag) {

	if (flag == false)
		findCP(NODE->left, NODE, true);
	else {
		if (NODE->right != NULL)
			findCP(NODE->right, NODE, true);
		else {
			
			return P;
		}
	}
}
AboutTree::node* AboutTree::findP(node *NODE,node* P,int value) {
	node *flag = NULL;	

	if (NODE->left != NULL) {
		if (NODE->left->value == value)
			return NODE;
	}

	if (NODE->right != NULL) {
		if (NODE->right->value == value)
			return NODE;
	}	
	
	if (NODE->left != NULL)
		flag = findP(NODE->left, NODE,value);
	if (NODE->right != NULL && flag == NULL)
		flag = findP(NODE->right, NODE,value);

	return flag;	
}

bool AboutTree::searchValue(int value)
{	
	node* flag=NULL;
	flag=recSV(root, value);
	if (flag != NULL) {
		cout << flag->value << " Found!\n";
		return true;
	}
	else {
		cout << value << " Not Found!\n";
		return false;
	}
	
}
AboutTree::node* AboutTree::recSV(node *NODE, int value) {

	node *flag=NULL;

	if (NODE->value == value)
		return NODE;
	
	if (NODE->left != NULL)
		flag=recSV(NODE->left,value);
	if (NODE->right != NULL && flag == NULL)
		flag=recSV(NODE->right, value);
		
	return flag;
	
}
int* AboutTree::inorderTraversal()
{
	cout << "Inorder Traversal :\n";
	recIn(root);
	cout << "\n";
	return NULL;
}
bool AboutTree::recIn(node *NODE) {
	if (NODE->left != NULL)
		recIn(NODE->left);

	cout << NODE->value << " ";

	if (NODE->right != NULL)
		recIn(NODE->right);	

	return true;
}
int* AboutTree::preorderTraversal()
{
	cout << "Preorder Traversal :\n";
	recPre(root);
	cout << "\n";
	return NULL;
}
bool AboutTree::recPre(node *NODE) {

	cout << NODE->value << " ";

	if (NODE->left != NULL)
		recPre(NODE->left);
	if (NODE->right != NULL)
		recPre(NODE->right);	

	return true;
}
int* AboutTree::postorderTraversal()
{
	cout << "Postorder Traversal :\n";
	recPost(root);
	cout << "\n";
	return NULL;
}
bool AboutTree::recPost(node *NODE) {
	if (NODE->left != NULL)
		recPost(NODE->left);
	if (NODE->right != NULL)
		recPost(NODE->right);
	
	cout << NODE->value << " ";
		
	return true;
}