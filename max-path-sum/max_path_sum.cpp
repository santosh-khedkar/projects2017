/*calculate the max path sum of the binary tree*/

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

int max_path_sum(node *root, int &res) {
	if (root ==  NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->value;

	int ls = max_path_sum(root->left, res);
	int rs = max_path_sum(root->right,res);

	if (root->left && root->right){
		res = max(res, ls + rs + root->value);

		return max(ls,rs) + root->value;
	}

	return root->left !=NULL? ls + root->value : rs + root->value;
}

int main(){
	/*contruct the tree
			1
		2		 3
	-4	   -5  6		7
						8
							9*/

	node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(-4);
	root->left->right = newnode(-5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->right->right->right = newnode(8);
	root->right->right->right->right = newnode(9);
	int max = INT_MIN;

	max_path_sum(root, max);

	cout <<"Maximum leaf to leaf sum: "<<max<<endl;


	return 0;
}