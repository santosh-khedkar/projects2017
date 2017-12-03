/*Reverse a linkedlist 
1->2->3->4->5->6->7->8*/

#include <iostream>

using namespace std;

struct node {
	int value;
	node *next;
};

node * newnode(int value){
	node *node1 = new node;
	node1->value = value;
	node1->next = NULL;
	return node1;
}

void printlist(node *head){

	while(head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout<< endl;
}

void iter_reverse(node **head){
	node *prev = NULL;
	node *curr = *head;
	node *next;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

/*we pass the address of the rest so 
rest is always fixed with recursive call*/
void recur_reverse(node **head){
	if (head == NULL)
		return;
	node *first = *head;
	node *rest = (*head)->next;
	if (rest == NULL)
		return;
	recur_reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

void cleanup(node *head){
	if (head == NULL)
		return;
	cleanup(head->next);
	delete head;
}

int main(){

	node *head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = newnode(6);
	head->next->next->next->next->next->next = newnode(7);

	printlist(head);
	iter_reverse(&head);
	printlist(head);
	recur_reverse(&head);
	printlist(head);
	cleanup(head);
	head = NULL;
	return 0;
}