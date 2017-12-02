/*Printing the preorder , postorder and inorder traversal of a binary tree
		1
	2		3
  4	  5	  6   7

*/


#include <iostream>
#include <new>

using namespace std;

struct node {
	int value;
	node* left;
	node* right;
};

node *newnode(int value){
	node *node1 = new node;
	node1->value = value;
	node1->left = NULL;
	node1->right = NULL;
	return node1;
}

void pre_order(node *root){

	if(root == NULL)
		return;

	cout <<root->value<<endl;
	pre_order(root->left);
	pre_order(root->right);
}

void in_order(node *root){
	
	if(root == NULL)
		return;
	
	in_order(root->left);
	cout <<root->value<<endl;
	in_order(root->right);
}

void post_order(node *root){
	
	if(root == NULL)
		return;
	
	post_order(root->left);	
	post_order(root->right);
	cout <<root->value<<endl;

}

void cleanup (node *root){
	 if(root == NULL)
	 	return;

	 cleanup(root->left);
	 cleanup(root->right);
	 root->value = 0;
	 delete root;
}

int main() {

	node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);

	cout<<"Pre-order traversal" <<endl;
	pre_order(root);
	cout<<"In-order traversal" <<endl;
	in_order(root);
	cout<<"Post-order traversal" <<endl;
	post_order(root);

	cleanup(root);
	root = NULL;
	
	return 0;
}