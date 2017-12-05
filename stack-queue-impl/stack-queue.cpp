/*Implement stack and queues*/

#include <iostream>
#include <climits>

using namespace std;

#define MAX 3
/*Stack */
class stack {
	int top;
	int sarr[MAX];
public:
	stack() {
		top = -1;
	}
	void push(int value);
	void pop();
	int peek();
	bool isEmpty();
};

void stack::push(int value){
	if (top == MAX - 1){
		cout << "Stack push failed"<<endl;
		return;
	}
	else {
		top++;
		sarr[top] = value;
	}
}

void stack::pop() {
	if (isEmpty()){
		cout<<"Stack is empty"<<endl;
		return;
	}
	else {
		top--;
	}
}

int stack::peek() {
	if (!isEmpty())
		return sarr[top];
	else 
		return INT_MIN;
}

bool stack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}


/*Queues*/
class queue {
	int front, rear;
	int curr_size;
	int qarr[MAX];
public:
	queue(){
		front = -1, rear = -1;
		curr_size = 0;
	}
	bool isEmpty();
	void push(int value);
	void pop();
	int peek();
};

bool queue::isEmpty(){
	if (front == -1)
		return true;
	else
		return false;
}


void queue::push(int value){
 	if (front == -1){
 		front  = 0;
 	}
 	if (curr_size < MAX) {
 		rear++;
 		rear = rear % MAX;
 		qarr[rear] = value;
 		curr_size++;
 	}
 	else {
 		cout << "queue is full"<<endl;
 		return;
 	}
}

void queue::pop() {
	if (curr_size == 0){
		cout<<"Queue is empty"<<endl;
		return;
	}
	else {
		front++;
		front = front%MAX;
		curr_size--;
		if (curr_size == 0){
			front = -1;
			rear = -1;
		}
	}
}

int queue::peek(){
	if (!isEmpty()){
		return qarr[front];
	}
	else {
		return INT_MIN;
	}
}
int main(){
	stack S;
	S.push(1);
	S.push(2);
	S.push(3);
	//cout <<S.peek()<<endl;
	S.pop();
	//cout <<S.peek()<<endl;
	S.pop();
	S.pop();

	queue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	cout<<Q.peek()<<endl;
	Q.pop();
	Q.push(4);
	cout<<Q.peek()<<endl;
	Q.pop();
	cout <<Q.peek()<<endl;
	Q.pop();
	Q.pop();
	Q.pop();


	return 0;
}