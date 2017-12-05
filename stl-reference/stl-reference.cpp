#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void stl_array(){
	/*declaration*/
	array<int,5> arr1 = { 2, 3, 4, 5, 6};
	/*parsing*/
	for (auto it = arr1.begin(); it != arr1.end(); it++)
		cout << *it <<" ";
	cout <<endl;

	for (int i; i < 5; i++)
		cout << arr1[i] <<" ";
	cout <<endl;

	array<int,5> arr2;

	arr2.fill(8); /* 8 8 8 8 8*/

	for (int &x : arr2)
		cout <<x <<" ";
	cout <<endl;

	/*Swapping two arrays*/
	arr1.swap(arr2);

	/*sorting*/
	array<int, 10> arr3 = {10, 1, 6, 7, 5, 4, 8, 3, 2, 9};
	//increasing order
	sort(arr3.begin(), arr3.end()); 
	//decreasing order
	sort(arr3.begin(), arr3.end(), greater<int>());
	/*in a specific order
	bool func(int i, int j) {
		return (i < j);
	}
	sort(arr3.begin(), arr3.end(), func); */

}

void stl_vector(){
	/*vector is resizable array*/
	/*declaration*/
	vector<int> v;
	for (int i = 1; i < 10; i++)
		v.push_back(i);
	vector<int> v2;
	v2.assign(3, 8); /*8 8 8*/
	array<int,5> arr = {1, 2, 3, 4, 5};
	vector<int> v3;
	v3.assign(arr.begin(), arr.end());
	vector<int> v4 = v3;

	/*parsing*/
	for(auto it = v.begin(); it != v.end(); it++)
		cout << *it <<" ";
	cout <<endl;

	for (int i = 0; i < v.size(); i++)
		cout<<v[i] <<" ";
	cout<<endl;

	/* size*/
	cout<<"current size:"<<v.size()<<endl; /*current size*/
	cout<<"capacity:"<<v.capacity()<<endl; /*storage allocated for the vector for growth*/
	cout<<"Max size:"<<v.max_size()<<endl; /*max num element a vector can hold*/
	v.resize(5); /* 1 2 3 4 5*/
	v.resize(8,100); /*1 2 3 4 5 100 100 100*/
	v.resize(12); /*1 2 3 4 5 100 100 100 0 0 0 0*/
	cout<<v.empty()<<endl; /*check if the current size of the vector is 0*/
	cout<<v.front()<<endl; /*front value: 1*/ 
	cout<<v.back()<<endl; /*back value: 0*/

	v.push_back(8); /*adds element to the end: 1 2 3 4 5 100 100 100 0 0 0 0 8*/  
	v.pop_back(); /*deletes last element 1 2 3 4 5 100 100 100 0 0 0 0*/

	/*insert*/
	v.insert(v.begin(), 7); /*7 1 2 3 4 5 100 100 100 0 0 0 0*/
	v.insert(v.begin(), 2, 8); /*8 8 7 1 2 3 4 5 100 100 100 0 0 0 0*/
	v.insert(v.begin() + 2, v4.begin(), v4.end()); /*8 8 |1 2 3 4 5| 7 1 2 3 4 5 100 100 100 0 0 0 0*/

	/*erase*/
	v.erase(v.begin()); /*give iter of the element to delete 8 1 2 3 4 5 7 1 2 3 4 5 100 100 100 0 0 0 0*/ 
	v.erase(v.begin(), v.begin()+5); /*give range of iter to delete 5 7 1 2 3 4 5 100 100 100 0 0 0 0*/

	/*swap*/
	v4.swap(v2);
	/*clear*/
	v2.clear(); /*clears everything*/

	/*sorting*/
	//increasing order
	sort(v.begin(), v.end()); 
	//decreasing order
	sort(v.begin(), v.end(), greater<int>());
	/*in a specific order
	bool func(int i, int j) {
		return (i < j);
	}
	sort(v.begin(), v.end(), func); */
}

void stl_string(){
	/*declaration*/
	string str = "My name is Santosh";
	string str1 = " and i am cool";
	/*concat and append*/
	string str3 = str + str1;
	cout<<str3<<endl;
	//append adds to the end
	str3.append(" guy.");
	str3.append(str1.begin(), str1.end());

	/*parsing*/
	for (auto it = str3.begin(); it != str3.end(); it++) /*by character*/
		cout<<*it;
	cout <<endl;

	for (int i = 0; i <str3.length(); i++)
		cout<<str3[i];
	cout <<endl;

	/*size and length are the same*/
	cout <<"Size: "<<str3.size()<<" "<<str3.length()<<endl;
	/*resize*/
	str3.resize(10); /*cut it to size 10 if orig > 10: My name is*/
	str3.resize(12, '%'); /*makes it 12 and inserts: My name is%%*/

	/*insert*/
	str3.insert(10, " Santosh"); /*My name is Santosh%%*/
	str3.insert(10," a",2); /*My name is a Santosh%%*/
	str3.insert(11, "sam and ", 4,4); /*My name is and a Santosh%%*/
	string::iterator it = str3.insert(str3.begin()+10,','); /*My name is, and a Santosh%%*/
	str3.insert(str3.end(), str1.begin(), str1.end()); /*My name is, and a Santosh%% and i am cool*/

	/*erase*/
	str3.erase(10,7); /*My name is Santosh%% and i am cool*/
	str3.erase(str3.begin()+18); /*My name is Santosh% and i am cool*/
	str3.erase(str3.begin()+18, str3.begin()+19); /*My name is Santosh and i am cool*/

	/*replace*/

	/*find*/

	/*compare*/

	/*substring/

	/*swap*/
	str3.swap(str1);

	/*cstring operation*/
	char str4[10];
	strcpy(str4, str1.c_str());
	/*clears everthing*/
	str1.clear();

}

int main(){
	stl_array();
	stl_vector();
	stl_string();
	return 0;
}