/*add linked list numbers 
	3 -> 4 -> 2
	5 -> 6 -> 4*/

#include <iostream>

using namespace std;

struct node {
	int value;
	node *next;
};

node * newnode (int val){
	node *node1 = new node;
	node1->value = val;
	node1->next = NULL;
	return node1;
}

node * addList (node *l1, node *l2){
	int dig = 0, carry = 0;
	node *head, *curr_node = NULL;
	while (l1 != NULL || l2 != NULL){
		if (l1 != NULL){
			dig = dig + l1->value;
			l1 = l1->next;
		}
		if (l2 != NULL){
			dig = dig + l2->value;
			l2 = l2->next;
		}
		dig = dig + carry;
		carry = dig / 10;
		dig = dig % 10;
		if (curr_node != NULL){
			curr_node->next = newnode(dig);
			curr_node = curr_node->next;
		}
		else {
			curr_node = newnode(dig);
			head = curr_node;
		}
		dig = 0;
	}
	return head;
}

void printlist(node *head){
	while (head != NULL){
		cout << head->value<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
	/*create the two list*/

	node *list1 = newnode(3);
	list1->next = newnode(4);
	list1->next->next = newnode(2);
	list1->next->next->next = newnode(7);
	node *list2 = newnode(5);
	list2->next = newnode(6);
	list2->next->next = newnode(4);

	node * head = addList(list1, list2);
	printlist (head);
	return 0;
}