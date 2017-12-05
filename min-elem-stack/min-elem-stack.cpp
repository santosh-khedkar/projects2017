/*find the minimum value in a dynamic stack in O(1)*/

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MyStack{
	stack<int> S;
	int minElem;

public:
	MyStack(){
		minElem = INT_MAX;
	}

	int getMin(){
		if (!S.empty()) {
			return minElem;
		} else {
			return INT_MAX;
		}
	}
	void push(int elem);
	void pop();
	int peek();
};

void MyStack::push(int elem){

	if (!S.empty()){
		if (elem > minElem){
			S.push(elem);
		}
		else {
			S.push(2*elem - minElem);
			minElem = elem;
		}
	} else{
		minElem = elem;
		S.push(elem);
	}
}

void MyStack::pop(){
	if (S.empty())
		return;
	int elem = S.top();
	S.pop();
	if (elem < minElem){
		minElem = 2*minElem - elem;
	}
}

int MyStack::peek(){
	if(S.empty()){
		return INT_MAX;
	}
	else {
		return S.top();
	}
}
using namespace std;

int main(){
	MyStack ms;
	ms.push(5);
	ms.push(4);
	ms.push(1);
	ms.push(6);
	ms.push(-1);
	ms.pop();
	cout<<ms.peek()<<endl;
	cout<<"Min:"<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.peek()<<endl;
	cout<<"Min:"<<ms.getMin()<<endl;
	return 0;
}