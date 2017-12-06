/*flatten a binary tree */

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

void printList(node *root){

	while (root!=NULL){
		cout << root->value <<"->";
		root = root->right;
	}
	cout<<"NULL"<<endl;
}

node * flatten_bt(node *root){
	if (root == NULL)
		return NULL;

	node *rtree = root->right;
	if (root->left != NULL) {
		root->right = root->left;
		root->left = NULL;
		root = flatten_bt(root->right);
	}
	
	if (rtree!=NULL) {
		root->right = rtree;
		root = flatten_bt(root->right);
	}
	return root;
}

int main(){
	/*contruct the tree
			 1
		2		 5
	3      4		6    => 1->2->3->4->5->6*/

	node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(5);
	root->left->left = newnode(3);
	root->left->right = newnode(4);
	root->right->right = newnode(6);

	node * root1 = root;
	flatten_bt(root);

	printList(root1);


	return 0;
}