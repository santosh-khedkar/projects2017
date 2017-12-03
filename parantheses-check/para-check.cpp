#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool para_check(string str){
	int i = 0;
	stack <char> S;
	while (i < str.length()){
		if (str[i] == '}'){
			if (!S.empty() && S.top() != '{')
				return false;
			else 
				S.pop();
		}
		else if (str[i] == ')'){
			if (!S.empty() && S.top() != '(')
				return false;
			else 
				S.pop();
		}
		else if (str[i] == ']'){
			if (!S.empty() && S.top() != '[')
				return false;
			else 
				S.pop();
		}
		else {
			S.push(str[i]);
		}	
		i++;
	}
	if (S.empty())
		return true;
	else
		return false;
}

int main(){
	string str = "{([])}(){}";

	if (para_check(str)){
		cout<< "Paranthesis are balanced"<<endl;
	} else {
		cout<< "Paranthesis are not balanced"<<endl;
	}
	return 0;
}