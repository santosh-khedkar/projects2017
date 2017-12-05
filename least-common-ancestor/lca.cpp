/*least common ancestor in a binary tree*/

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

node * least_comm_ances(node *root, int v1, int v2){
	if (root == NULL)
		return NULL;
	if (root->value == v1 || root->value  == v2)
		return root;

	node *left_lca = least_comm_ances(root->left, v1, v2);
	node *right_lca = least_comm_ances(root->right, v1, v2);

	if (left_lca && right_lca)
		return root;

	return left_lca !=NULL ? left_lca : right_lca;
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

	node *lca = least_comm_ances(root, 9, 5);
	cout <<"Least common ancestor: "<<lca->value<<endl;
	return 0;
}