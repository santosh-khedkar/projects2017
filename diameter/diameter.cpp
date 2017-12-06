/*calculate the diameter of the binary tree*/

#include <iostream>

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

int height (node *root) {
	if (root == NULL)
		return 0;

	return 1 + max (height(root->left), height(root->right));
}

int main(){
	/*contruct the tree
			1
		2		 3
	4	   5  6		7
						8
							9*/

	node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->right->right->right = newnode(8);
	root->right->right->right->right = newnode(9);
	cout << "Height of the tree: "<<height(root)<<endl;
	int diameter = height (root->left) + height(root->right) + 1; 
	cout << "Diameter of the tree: "<<diameter<<endl;
	return 0;
}