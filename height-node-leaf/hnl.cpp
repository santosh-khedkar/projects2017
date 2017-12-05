/*find the no of nodes, height and no. of leaf 
nodes in a binary tree */

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

int numnode(node *root){
	if (root == NULL)
		return 0;
	
	return (1 + numnode(root->left) + numnode(root->right));
}

int height(node *root){
	if (root == NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

int numleaf(node *root){
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	
	return numleaf(root->left) + numleaf(root->right);
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
	cout << "Number of nodes in the tree: "<< numnode(root)<<endl;
	cout << "height of the tree is: "<< height(root)<<endl;
	cout << "Num of leaf node: "<<numleaf(root)<<endl;
	return 0;
}