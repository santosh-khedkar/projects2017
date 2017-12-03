#include <iostream>
#include <string>

using namespace std;

void permute_string(string s, string choose){
	if(s.empty()){
		cout << choose <<endl;
	} else {
		for (int i = 0; i < s.length(); i++){
			char c = s[i];
			s.erase(i, 1);
			choose = choose + c;

			permute_string(s, choose);

			s.insert(i, 1, c);
			choose.erase(choose.length()-1, 1);
		}
	}
}

int main() {

	permute_string("abcd","");

	return 0;
}