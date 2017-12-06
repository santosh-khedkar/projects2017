/*implement a stack using two queues and queue using two stacks*/

#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

class Mystack {
	queue<int> q1;
	queue<int> q2;

public:
	void push(int value);
	void pop();
	int top();
	bool isEmpty();
};

void Mystack::push(int value) {
	int elem;
	if (q1.empty()){
		q1.push(value);
		while (!q2.empty()){
			elem = q2.front();
			q2.pop();
			q1.push(elem);
		}
	}
	else {
		q2.push(value);
		while (!q1.empty()){
			elem = q1.front();
			q1.pop();
			q2.push(elem);
		}
	}

	q1.swap(q2);
}

bool Mystack::isEmpty(){
	if (q1.empty() && q2.empty())
		return true;
	else 
		return false;
}

void Mystack::pop(){
	if (isEmpty()) {
		cout<<"Stack is empty"<<endl;
	} else if (!q1.empty()){
		q1.pop();
	} else if (!q2.empty()){
		q2.pop();
	}
}

int Mystack::top(){
	if (isEmpty()) {
		cout<<"Stack is empty"<<endl;
		return INT_MIN;
	} else if (!q1.empty()){
		return q1.front();
	} else if (!q2.empty()){
		return q2.front();
	}
}

/*=======================================================================================*/

class Myqueue {
	stack<int> s1;
	stack<int> s2;

public:
	void push(int value);
	void pop();
	int front();
	bool isEmpty();
};

void Myqueue::push(int value){
	int elem;
	while (!s1.empty()){
		elem = s1.top();
		s2.push(elem);
		s1.pop();
	}
	s2.push(value);
	while(!s2.empty()){
		elem = s2.top();
		s1.push(elem);
		s2.pop();
	}
}

bool Myqueue::isEmpty() {
	if (s1.empty() and s2.empty())
		return true;
	else 
		return false;
}

void Myqueue::pop(){
	if (isEmpty()){
		cout <<"Queue is empty"<<endl;
	} else if (!s1.empty()){
		s1.pop();
	} else if (!s2.empty()){
		s2.pop();
	}
}

int Myqueue::front(){
	if (isEmpty()){
		cout <<"Queue is empty"<<endl;
		return INT_MIN;
	} else if (!s1.empty()){
		return s1.top();
	} else if (!s2.empty()){
		return s2.top();
	}
}

int main(){
	Mystack S; 
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	cout <<"Top of stack: "<<S.top()<<endl;
	S.pop();
	cout <<"Top of stack: "<<S.top()<<endl;
	S.pop();
	cout <<"Top of stack: "<<S.top()<<endl;
	S.pop();
	cout <<"Top of stack: "<<S.top()<<endl;
	S.pop();
	cout <<"Top of stack: "<<S.top()<<endl;
	/*=========================*/
	Myqueue Q; 
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	cout <<"front of queue: "<<Q.front()<<endl;
	Q.pop();
	cout <<"front of queue: "<<Q.front()<<endl;
	Q.pop();
	cout <<"front of queue: "<<Q.front()<<endl;
	Q.pop();
	cout <<"front of queue: "<<Q.front()<<endl;
	Q.pop();
	cout <<"front of queue: "<<Q.front()<<endl;
	return 0;
}