/*Breadth first search and depth first search of a tree*/

#include <iostream>
#include <queue>
#include <stack>

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

void do_bfs(node *root){
	queue<node*> Q;
	Q.push(root);
	while (!Q.empty()){
		node *node1 = Q.front();
		Q.pop();
		cout << node1->value<<" ";
		if (node1->left != NULL)
			Q.push(node1->left);
		if (node1->right != NULL)
			Q.push(node1->right);
	}
	cout <<endl;
}


void do_dfs(node *root){
	stack<node*> S;
	S.push(root);
	while(!S.empty()){
		node *node1 = S.top();
		S.pop();
		cout<< node1->value<<" ";
		if(node1->left)
			S.push(node1->left);
		if(node1->right)
			S.push(node1->right);
	}
	cout <<endl;
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

	do_bfs(root); /*1 2 3 4 5 6 7 8 9*/
	do_dfs(root); /*1 3 7 8 9 6 2 5 4*/
	return 0;
}