/*check if a binary tree is BST*/

#include <iostream>
#include <climits>

using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};


node * newnode(int v){
	node *node1 = new node;
	node1->value = v;
	node1->left = NULL;
	node1->right = NULL;
	return node1;
}


bool check_bst(node *root, int gmin, int gmax){
	if (root == NULL)
		return true;
	if (root->value < gmin || root->value > gmax){
		return false;
	}
	return check_bst(root->left, gmin, root->value - 1) &&
		   check_bst(root->right, root->value + 1, gmax);
}

int main(){
	/*contruct the tree
			5
		4		 7
	3	      6		10
						11
							12*/

	node *root = newnode(5);
	root->left = newnode(4);
	root->left->left = newnode(3);
	root->right = newnode(7);
	root->right->left = newnode(6);
	root->right->right = newnode(10);
	root->right->right->right = newnode(11);
	root->right->right->right->right = newnode(12);

	if (check_bst(root, INT_MIN, INT_MAX)){
		cout <<"Binary tree is BST"<<endl;
	} else {
		cout <<"Binary tree is not a BST"<<endl;
	}

	return 0;
}